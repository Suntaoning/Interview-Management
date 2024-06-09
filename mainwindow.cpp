#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMap>
#include <vector>

using namespace std;

QString filePath = QDir::currentPath() + "/1.xlsx";    // 打开的excel路径 可自定义
std::unordered_map<QTreeWidgetItem*, int> itemRow;
std::unordered_map<int, QString> rowString;
std::multimap<QString, QTreeWidgetItem*, StringCompare> todayTimeItem;
std::unordered_map<QString, vector<int>> everyDateItemRow;
QDate today = QDate::currentDate();
QString todayString = today.toString("yyyy/mm/dd");
int itemNum = 1;   // 包括删除的项--共写过x条记录
QAxObject *excel,*workbooks,*workbook,*sheets,*sheet;  //excel信息

void createExcelFile(const QString &filePath)
{
    // 创建 Excel 应用程序对象
    QAxObject *excel = new QAxObject("Excel.Application");
    if (!excel) {
        qWarning() << "Excel not installed!";
        return;
    }

    // 设置 Excel 应用程序不可见
    excel->setProperty("Visible", false);

    // 创建一个新的工作簿
    QAxObject *workbooks = excel->querySubObject("Workbooks");
    workbooks->dynamicCall("Add");

    // 获取当前工作簿
    QAxObject *workbook = excel->querySubObject("ActiveWorkbook");

    // 保存工作簿到指定位置
    workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(filePath));

    // 关闭工作簿
    workbook->dynamicCall("Close()");

    // 退出 Excel 应用程序
    excel->dynamicCall("Quit()");

    delete excel;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QActionGroup *actiongroup = new QActionGroup(this);
    actiongroup->setExclusive(true);
    actiongroup->addAction(ui->action);
    actiongroup->addAction(ui->action_2);
    actiongroup->addAction(ui->action_3);
    actiongroup->addAction(ui->action_4);
    actiongroup->addAction(ui->action_5);
    // 设置工具栏图标大小
    ui->toolBar->setIconSize(QSize(60, 60));
    ui->action->setIcon(QIcon(":/1.png"));
    ui->action_2->setIcon(QIcon(":/6.png"));
    ui->action_3->setIcon(QIcon(":/3.png"));
    ui->action_4->setIcon(QIcon(":/4.png"));
    ui->action_5->setIcon(QIcon(":/7.png"));
    ui->treeWidget->setColumnWidth(0, 200);  // 设置第一列宽度为 200 像素
    ui->treeWidget->setColumnWidth(1, 100);
    ui->treeWidget->setColumnWidth(2, 200);
    ui->treeWidget->setColumnWidth(3, 200);
    ui->treeWidget->setColumnWidth(4, 150);
    ui->tableWidget->setColumnWidth(0,200);
    ui->tableWidget->setColumnWidth(1, 200);
    ui->tableWidget->setColumnWidth(2, 200);
    ui->tableWidget->setColumnWidth(3, 200);

    QFile file(filePath);
    if (!file.exists()){
        createExcelFile(filePath);
    }
    //qDebug() << "123";
    excel = new QAxObject("Excel.Application");
    workbooks = excel->querySubObject("Workbooks");
    workbook = workbooks->querySubObject("Open(const QString&)", filePath);
    // 获取工作表
    sheets = workbook->querySubObject("Sheets");
    sheet = sheets->querySubObject("Item(int)", 1); // 获取第一张表

    display_excel(ui->treeWidget);
    ui->stackedWidget->setCurrentIndex(0);
    // 在此处打开excel 并在程序运行期间一直保持excel开启   在程序结束时期关闭excel

    connect(ui->treeWidget, &QTreeWidget::itemExpanded, this, &MainWindow::onItemExpanded);  // 展开树
    connect(ui->treeWidget, &QTreeWidget::itemCollapsed, this, &MainWindow::onItemCollapsed);    // 取消展开树
    // 连接 triggered 信号到槽函数
    connect(actiongroup, &QActionGroup::triggered, this, [=](QAction *action) {
        // 将所有动作取消高亮状态
        for (QAction *act : actiongroup->actions()) {
            act->setChecked(false);
        }
        // 将触发动作设置为高亮状态
        action->setChecked(true);
    });

    connect(QApplication::instance(), &QApplication::aboutToQuit, this, [=](){
        if (workbook) {
            workbook->dynamicCall("Close()");
        }
        if (excel) {
            excel->dynamicCall("Quit()");
            delete excel;
        }
    });
}

void highlightItem(QTreeWidgetItem* item)
{
    // 设置高亮背景色
    item->setBackground(0, QBrush(Qt::black)); // 设置第0列背景色
    for (int i = 1; i < item->columnCount(); ++i) {
        item->setBackground(i, QBrush(Qt::black)); // 设置其余列背景色
    }

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
    //display_excel(ui->treeWidget);
}

void MainWindow::on_action_2_triggered()    //新增一个面试
{
    // ui->stackedWidget->setCurrentIndex(1);
    Dialog2 *dialog = new Dialog2();
    dialog->setWindowTitle("新增面试");
    QStringList list;

    connect(dialog->getdialogbuttonbox(), &QDialogButtonBox::accepted, [=](){
        QString newText1 = dialog->getLineEdit(1)->text();
        QString newText2 = dialog->getLineEdit(2)->text();
        QString newText3 = dialog->getLineEdit(3)->text();
        QString newText4 = dialog->getLineEdit(4)->text();
        QString newText5 = dialog->getLineEdit(5)->text();
        QString newText6 = dialog->getLineEdit(6)->text();
        QString newText7 = dialog->getLineEdit(7)->text();
        QString newText8 = dialog->getLineEdit(8)->text();
        if (newText1.isEmpty() || newText2.isEmpty() || newText3.isEmpty()){
            QMessageBox messageBox;
            messageBox.addButton("确定", QMessageBox::AcceptRole);
            messageBox.addButton("取消", QMessageBox::RejectRole);

            messageBox.setWindowTitle("error");
            messageBox.resize(500,500);
            messageBox.setText("填充信息不全");

            messageBox.exec();
            return;
        }
        if(newText4.size() != 4){     // 格式判断
            QMessageBox messageBox;
            messageBox.addButton("确定", QMessageBox::AcceptRole);
            messageBox.addButton("取消", QMessageBox::RejectRole);

            messageBox.setWindowTitle("error");
            messageBox.resize(500,500);
            messageBox.setText("年份输入错误");

            messageBox.exec();
            return;
        }
        if(newText5.toInt() < 0 || newText5.toInt() > 12){
            QMessageBox messageBox;
            messageBox.addButton("确定", QMessageBox::AcceptRole);
            messageBox.addButton("取消", QMessageBox::RejectRole);

            messageBox.setWindowTitle("error");
            messageBox.resize(500,500);
            messageBox.setText("月份输入错误");

            messageBox.exec();
            return;
        }
        if(newText6.toInt() < 0 || newText6.toInt() > 31){
            QMessageBox messageBox;
            messageBox.addButton("确定", QMessageBox::AcceptRole);
            messageBox.addButton("取消", QMessageBox::RejectRole);

            messageBox.setWindowTitle("error");
            messageBox.resize(500,500);
            messageBox.setText("日期输入错误");

            messageBox.exec();
            return;
        }
        if(newText7.toInt() > 24 || newText7.toInt() < 0 || newText8.toInt() > 60 || newText8.toInt() < 0){
            QMessageBox messageBox;
            messageBox.addButton("确定", QMessageBox::AcceptRole);
            messageBox.addButton("取消", QMessageBox::RejectRole);

            messageBox.setWindowTitle("error");
            messageBox.resize(500,500);
            messageBox.setText("时间输入错误");

            messageBox.exec();
            return;
        }

        if(newText5.size() == 1){
            newText5 = "0" + newText5;
        }
        if(newText6.size() == 1){
            newText6 = "0" + newText6;
        }
        if(newText8.size() == 1){
            newText8 = "0" + newText8;
        }

        QString Date1 = newText4 + "/" + newText5 + "/" + newText6;
        QString Time1 = newText7 + ":" + newText8;

        // 获取最大行列数
        QAxObject *usedRange = sheet->querySubObject("UsedRange");
        QAxObject *rows = usedRange->querySubObject("Rows");

        int rowCount = rows->property("Count").toInt();

        if (rowCount == 1) {
            QAxObject *cell = sheet->querySubObject("Cells(int,int)", 1, 1);
            QString cellValue = cell->dynamicCall("Value()").toString();
            if (cellValue.isEmpty()) {
                rowCount = 0; // 空白文件，设置行数为0
            }
        }

        if(sheet){
            QAxObject *cell = sheet->querySubObject("Cells(int,int)", rowCount + 1, 1);  // itemNum暂时没啥作用
            cell->dynamicCall("value", itemNum++);
            QAxObject *cell1 = sheet->querySubObject("Cells(int,int)", rowCount + 1, 2);
            cell1->dynamicCall("value", newText1);
            QAxObject *cell2 = sheet->querySubObject("Cells(int,int)", rowCount + 1, 3);
            cell2->dynamicCall("value", newText3);
            QAxObject *cell3 = sheet->querySubObject("Cells(int,int)", rowCount + 1, 4);
            cell3->dynamicCall("value", newText2);
            QAxObject *cell4 = sheet->querySubObject("Cells(int,int)", rowCount + 1, 5);
            cell4->dynamicCall("value", Date1);
            cell4->setProperty("NumberFormat", "yyyy/MM/dd");
            QAxObject *cell5 = sheet->querySubObject("Cells(int,int)", rowCount + 1, 6);
            cell5->dynamicCall("value", Time1);
            workbook->dynamicCall("Save()");
        }

        dialog->accept(); // 关闭对话框
    });

    connect(dialog->getdialogbuttonbox(), &QDialogButtonBox::rejected, [=](){
        dialog->accept(); // 关闭对话框
    });

    dialog->exec();
    delete dialog;
    ui->treeWidget->clear();
    display_excel(ui->treeWidget);
}

void MainWindow::on_action_3_triggered()
{
    int currentIndex = ui->stackedWidget->currentIndex();
    if(currentIndex == 0){
        ui->treeWidget->clear();
        display_excel(ui->treeWidget);
    }
    if(currentIndex == 1){
        //ui->treeWidget->clear();
        display_setting();
    }
    if(currentIndex == 2){
        ui->tableWidget->setRowCount(0);
        display_today_excel();
    }
}

void MainWindow::on_action_4_triggered()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->tableWidget->setRowCount(0);
    display_today_excel();
}

void MainWindow::on_action_5_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
    display_setting();
}

QString calculateTimeDifference(const QString &time1, const QString &time2, const QString &format = "HH:mm:ss") {
    QTime t1 = QTime::fromString(time1, format);
    QTime t2 = QTime::fromString(time2, format);
    //qDebug() << t1 << t2;

    if (!t1.isValid() || !t2.isValid()) {
        return "Invalid time format";
    }

    int secondsDiff = t1.secsTo(t2); // Calculate difference in seconds
    //qDebug() << secondsDiff;
    QTime timeDiff(0, 0, 0);
    timeDiff = timeDiff.addSecs(secondsDiff);

    return timeDiff.toString("HH:mm:ss");
}

bool timeReduce(QString &lhs, QString &rhs){
    if(!lhs.isEmpty() && lhs[0] == '0' && lhs[1] != ':'){
        lhs.remove(0, 1);
    }
    //qDebug() << lhs << rhs;
    if (lhs.length() == rhs.length()) {
        //qDebug() << lhs << rhs;
        return (lhs < rhs);
    }
    return lhs.length() < rhs.length();
}


void MainWindow::display_excel(QTreeWidget *treeWidget)
{
    QMap<QDate, QTreeWidgetItem*> map;
    itemRow.clear();
    rowString.clear();
    todayTimeItem.clear();
    everyDateItemRow.clear();

    // 获取最大行列数
    QAxObject *usedRange = sheet->querySubObject("UsedRange");
    QAxObject *rows = usedRange->querySubObject("Rows");
    QAxObject *columns = usedRange->querySubObject("Columns");

    int rowCount = rows->property("Count").toInt();
    columns->property("Count").toInt();

    if (rowCount == 1) {
        QAxObject *cell = sheet->querySubObject("Cells(int,int)", 1, 1);
        QString cellValue = cell->dynamicCall("Value()").toString();
        if (cellValue.isEmpty()) {
            rowCount = 0; // 空白文件，设置行数为0
        }
    }

    for(int row = 1; row <= rowCount; ++row){
        QAxObject *cell = sheet->querySubObject("Cells(int,int)", row, 5);
        QString value = cell->dynamicCall("Text").toString(); // 获取单元格的文本内容
        value = value.trimmed(); // 去除字符串两端的空格
        QDate date1 = QDate::fromString(value, "yyyy/MM/dd");

        QTreeWidgetItem* item;
        if(!map.contains(date1)){
            //qDebug() << date1;
            item = new QTreeWidgetItem(QStringList(value));
            map[date1] = item;
        }
    }

    for (auto it = map.begin(); it != map.end(); ++it) {
        treeWidget->addTopLevelItem(it.value());
        if(it.key() == today){
            highlightItem(it.value());
        }
    }
    //qDebug() << todayrowItem.size();

    for(int row = 1; row <= rowCount; ++row){
        QAxObject *cell = sheet->querySubObject("Cells(int,int)", row, 5);
        QString value = cell->dynamicCall("Text").toString(); // 获取单元格的文本内容
        QDate date1 = QDate::fromString(value, "yyyy/MM/dd");
        //qDebug() << date1;
        QTreeWidgetItem* item = map[date1];

        QAxObject *cell2 = sheet->querySubObject("Cells(int,int)", row, 2);
        QString value2 = cell2->dynamicCall("Text").toString(); // 获取单元格的文本内容
        QAxObject *cell3 = sheet->querySubObject("Cells(int,int)", row, 6);
        QString value3 = cell3->dynamicCall("Text").toString();
        QAxObject *cell4 = sheet->querySubObject("Cells(int,int)", row, 4);
        QString value4 = cell4->dynamicCall("Text").toString();
        QAxObject *cell5 = sheet->querySubObject("Cells(int,int)", row, 3);
        QString value5 = cell5->dynamicCall("Text").toString();
        QStringList child;
        child << value2 << value3 << value4 << value5;
        //qDebug() << value2 << value3 << value4 << value5;
        QTreeWidgetItem *TreeWidgetItemchild = new QTreeWidgetItem(item,child);
        itemRow[TreeWidgetItemchild] = row;
        rowString[row] = value3;
        everyDateItemRow[value].push_back(row);   // 初始化每个日期 包含的所有面试行
        if (date1 == today){
            todayTimeItem.insert(std::make_pair(value3, TreeWidgetItemchild));
            //todayTimeItem[value3] = TreeWidgetItemchild;
        }

    }
}

void MainWindow::testTodayInterviewTime()
{
    QAxObject *cell1 = sheet->querySubObject("Cells(int,int)", 1, 12);
    QString chooseInterview = cell1->dynamicCall("Text").toString();
    QAxObject *cell2 = sheet->querySubObject("Cells(int,int)", 1, 10);
    QString chooseInterviewTH1 = cell2->dynamicCall("Text").toString();
    QAxObject *cell3 = sheet->querySubObject("Cells(int,int)", 1, 11);
    QString chooseInterviewTH2 = cell3->dynamicCall("Text").toString();
    QString chooseInterviewTH;
    if(chooseInterviewTH2.size() == 1){
        chooseInterviewTH = chooseInterviewTH1 + ":0" + chooseInterviewTH2 + ":00";
    }else{
        chooseInterviewTH = chooseInterviewTH1 + ":" + chooseInterviewTH2 + ":00";
    }


    if(chooseInterview == "0" || chooseInterview == nullptr)
        return;
    //qDebug() << chooseInterviewTH;
    int tmp = -99, color = 0, i = 0;
    std::map<QString, QTreeWidgetItem*> TimeMap;   // 存储时间 - 孩子item
    for(auto& todayItem: todayTimeItem){
        QTreeWidgetItem* it = todayItem.second;
        QString timeStr;
        timeStr =  it->text(1) + ":00";
        if(timeStr.size() == 7){
            timeStr.prepend("0");
        }

        // QTableWidgetItem *item = ui->tableWidget->item(row, column);  -- 在tablewidget中操作
        // if (!item) {
        //     item = new QTableWidgetItem(); // 如果单元格为空，需要先创建一个新的 QTableWidgetItem
        //     ui->tableWidget->setItem(row, column, item);
        // }
        //item->setBackground(QBrush(QColor(255, 0, 0))); // 设置背景颜色为红色

        auto lastItem = TimeMap.rbegin();
        if(lastItem != TimeMap.rend()){
            QString TimeDiff1 = calculateTimeDifference(lastItem->first, timeStr);
            bool b = timeReduce(TimeDiff1, chooseInterviewTH);
            //qDebug() << b;
            if(b){    // 满足条件treeWidgetItem画标记
                //qDebug() << tmp;
                if(i == tmp + 2){   // 大于等于连续的三个面试间隔时间小于阈值
                    color--;
                }
                //qDebug() << color;
                if(color % 2 == 0){
                    QTableWidgetItem *item = ui->tableWidget->item(i - 1, 3);
                    item->setBackground(QBrush(QColor(0, 0, 128)));
                    QTableWidgetItem *item2 = ui->tableWidget->item(i, 3);
                    item2->setBackground(QBrush(QColor(0, 0, 128)));
                    color++;
                }else{
                    QTableWidgetItem *item = ui->tableWidget->item(i - 1, 3);
                    item->setBackground(QBrush(QColor(34, 139, 34)));
                    QTableWidgetItem *item2 = ui->tableWidget->item(i, 3);
                    item2->setBackground(QBrush(QColor(34, 139, 34)));
                    color++;
                }
                tmp = i - 1;
            }
        }
        TimeMap[timeStr] = it;
        i++;
    }

}

void MainWindow::display_today_excel(){

    //ui->stackedWidget->setCurrentIndex(2);

    if(todayTimeItem.empty()){
        // 创建一个 QLabel 来显示图片
        QLabel *imageLabel = new QLabel(ui->scrollArea_3);

        // 加载图片
        QPixmap pixmap(":/5.png");

        // 检查图片是否加载成功
        if (pixmap.isNull()) {
            qDebug() << "Failed to load image";
            return;
        }

        // 设置图片到 QLabel 上
        imageLabel->setPixmap(pixmap);

        // 设置 QLabel 的对齐方式
        imageLabel->setAlignment(Qt::AlignCenter);

        // 根据图片大小调整 QLabel 的大小
        imageLabel->setScaledContents(true); // 使图片自适应标签大小

        // 添加 QLabel 到 QWidget 上
        QVBoxLayout *layout = new QVBoxLayout(ui->scrollArea_3);
        layout->addWidget(imageLabel);
        ui->scrollArea_3->setLayout(layout);
    }
    else{
        for(auto& todayItem: todayTimeItem){
            //qDebug() << "123";
            QTreeWidgetItem* it = todayItem.second;
            QStringList strList;
            strList << it->text(0) << it->text(2) << it->text(3) << it->text(1);
            //qDebug() << strList;
            int currentRowCount = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(currentRowCount);
            for (int column = 0; column < 4; ++column) {
                QTableWidgetItem *item = new QTableWidgetItem(strList[column]);
                item->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget->setItem(currentRowCount, column, item);
            }
        }
        testTodayInterviewTime();
    }
}

void MainWindow::display_setting()     //设置界面
{
    QAxObject *cell1 = sheet->querySubObject("Cells(int,int)", 1, 10);
    QString collision_hour = cell1->dynamicCall("Text").toString();
    QAxObject *cell2 = sheet->querySubObject("Cells(int,int)", 1, 11);    // 未初始化时候为nullptr
    QString collision_min = cell2->dynamicCall("Text").toString();
    QAxObject *cell3 = sheet->querySubObject("Cells(int,int)", 1, 12);
    QString chooseInterview = cell3->dynamicCall("Text").toString();

    if(collision_hour != nullptr && collision_min != nullptr){
        ui->lineEdit->setText(collision_hour);
        ui->lineEdit_2->setText(collision_min);
    }

    if(chooseInterview == "0" || chooseInterview == nullptr){
        ui->checkBox->setChecked(false);
    }else if (chooseInterview == "1"){
        ui->checkBox->setChecked(true);
    }

    connect(ui->pushButton, &QPushButton::clicked, [=](){
        // 点击按钮提交新的面试碰撞时间
        QString collision_hour1 = ui->lineEdit->text();
        QString collision_min1 = ui->lineEdit_2->text();
        QAxObject *cell3 = sheet->querySubObject("Cells(int,int)", 1, 10);
        cell3->dynamicCall("value", collision_hour1);
        QAxObject *cell4 = sheet->querySubObject("Cells(int,int)", 1, 11);
        cell4->dynamicCall("value", collision_min1);
        workbook->dynamicCall("Save()");

        // 弹出一个确认messagebox
        // QMessageBox messageBox;
        // QPushButton *ok = messageBox.addButton("确定", QMessageBox::AcceptRole);
        // QPushButton *cancel = messageBox.addButton("取消", QMessageBox::RejectRole);
        // messageBox.setWindowTitle("修改面试时间冲突阈值");
        // messageBox.resize(500,500);
        // messageBox.setText("确定修改?");

        // if(messageBox.exec() == QMessageBox::AcceptRole){
        //      qDebug() << "456";
        //     workbook->dynamicCall("Save()");
        // }
        // messageBox.done(QMessageBox::Accepted);

    });


    connect(ui->checkBox, &QCheckBox::stateChanged, this, [=](int state) {
        if (state == Qt::Checked) {
            QAxObject *cell3 = sheet->querySubObject("Cells(int,int)", 1, 12);
            cell3->dynamicCall("value", 1);
        }else{
            QAxObject *cell3 = sheet->querySubObject("Cells(int,int)", 1, 12);
            cell3->dynamicCall("value", 0);
        }
        workbook->dynamicCall("Save()");
    });

}

void MainWindow::onButtonClicked(QTreeWidgetItem *childItem){ // 修改面试信息
    new_dialog *dialog = new new_dialog();
    dialog->setWindowTitle("修改面试信息");
    QStringList list;
    //int row = childItem->text(4).toInt();
    int row = itemRow[childItem];   // 刷新excel数据
    //qDebug() << row;
    list << childItem->text(0) << childItem->text(2) << childItem->text(3);
    QTreeWidgetItem *parentItem = childItem->parent();
    list << parentItem->text(0) << childItem->text(1);

    //qDebug() << list;
    for(int i = 0; i < 5; i++){
        dialog->setLineText(dialog->getLineEdit(i + 1),list[i]);
    }

    connect(dialog->getdialogbuttonbox(), &QDialogButtonBox::accepted, [=](){
        QString newText1 = dialog->getLineEdit(1)->text();
        QString newText2 = dialog->getLineEdit(2)->text();
        QString newText3 = dialog->getLineEdit(3)->text();
        QString newText4 = dialog->getLineEdit(4)->text();
        QString newText5 = dialog->getLineEdit(5)->text();

        childItem->setText(0, newText1);
        childItem->setText(2, newText2);
        childItem->setText(3, newText3);
        parentItem->setText(0, newText4);
        childItem->setText(1, newText5);

        if(sheet){
            QAxObject *cell1 = sheet->querySubObject("Cells(int,int)", row, 2);
            cell1->dynamicCall("value", newText1);
            QAxObject *cell2 = sheet->querySubObject("Cells(int,int)", row, 3);
            cell2->dynamicCall("value", newText3);
            QAxObject *cell3 = sheet->querySubObject("Cells(int,int)", row, 4);
            cell3->dynamicCall("value", newText2);
            QAxObject *cell4 = sheet->querySubObject("Cells(int,int)", row, 5);
            cell4->dynamicCall("value", newText4);
            QAxObject *cell5 = sheet->querySubObject("Cells(int,int)", row, 6);
            cell5->dynamicCall("value", newText5);
            workbook->dynamicCall("Save()");
        }

        dialog->accept(); // 关闭对话框
    });

    connect(dialog->getdialogbuttonbox(), &QDialogButtonBox::rejected, [=](){
        dialog->accept(); // 关闭对话框
    });

    dialog->exec();
    delete dialog;
}

void MainWindow::onButton2Clicked(QTreeWidgetItem *childItem)  // 查看面试记录
{
    Dialog1 *dialog = new Dialog1();
    dialog->setWindowTitle("面试记录");
    QString string;
    int row = itemRow[childItem];   // 刷新excel数据

    QAxObject *cell = sheet->querySubObject("Cells(int,int)", row, 7);
    string = cell->dynamicCall("Text").toString();

    dialog->setText(string);

    connect(dialog->getbutton(1), &QPushButton::clicked, [=](){
        QString newText = dialog->getTextEdit();

        if(sheet){
            QAxObject *cell1 = sheet->querySubObject("Cells(int,int)", row, 7);
            cell1->dynamicCall("value", newText);
            workbook->dynamicCall("Save()");
        }

        dialog->accept(); // 关闭对话框
    });

    connect(dialog->getbutton(2), &QPushButton::clicked, [=](){
        dialog->accept(); // 关闭对话框
    });

    dialog->exec();
    delete dialog;
}

void MainWindow::onButton3Clicked(QTreeWidgetItem *treeWidgetitem)  // 删除某条面试
{
    // 获取要删除的行范围
    QAxObject* range = sheet->querySubObject("Rows(int)", itemRow[treeWidgetitem]);

    QString str = rowString[itemRow[treeWidgetitem]];
    if(todayTimeItem.find(str) != todayTimeItem.end()){
        todayTimeItem.erase(str);
    }

    if (range) {
        // 删除该行
        range->dynamicCall("Delete()");
        delete range; // 删除 QAxObject 指针以避免内存泄漏
        workbook->dynamicCall("Save()");
    } else {
        qDebug() << "Failed to retrieve the row range.";
    }

    ui->treeWidget->clear();
    display_excel(ui->treeWidget);
}

void vecReduce(vector<int> &rowVec){
    for(int i = 0; i < rowVec.size(); i++){
        rowVec[i] -= 1;
    }
}

void MainWindow::onButton4Clicked(QString date)   // 删除某日的所有面试
{
    vector<int> rowVec = everyDateItemRow[date];
    for(int i = 0; i < rowVec.size(); i++){
        QAxObject* range = sheet->querySubObject("Rows(int)", rowVec[i]);
        if (range) {
            // 删除该行
            range->dynamicCall("Delete()");
            delete range; // 删除 QAxObject 指针以避免内存泄漏
            workbook->dynamicCall("Save()");
        } else {
            qDebug() << "Failed to retrieve the row range.";
        }
        vecReduce(rowVec);
    }

    QDate date1 = QDate::fromString(date, "yyyy/mm/dd");
    if (date1 == today){
        todayTimeItem.clear();
    }

    ui->treeWidget->clear();
    display_excel(ui->treeWidget);
}


void MainWindow::testInterviewTime(QTreeWidgetItem *treeWidgetItem)   //监视每个日期下的所有面试是否有时间冲突
{
    //int useInterviewTH = ui->checkBox->checkState(); // checked--2   not checked--0
    QAxObject *cell1 = sheet->querySubObject("Cells(int,int)", 1, 12);
    QString chooseInterview = cell1->dynamicCall("Text").toString();
    QAxObject *cell2 = sheet->querySubObject("Cells(int,int)", 1, 10);
    QString chooseInterviewTH1 = cell2->dynamicCall("Text").toString();
    QAxObject *cell3 = sheet->querySubObject("Cells(int,int)", 1, 11);
    QString chooseInterviewTH2 = cell3->dynamicCall("Text").toString();
    QString chooseInterviewTH;
    if(chooseInterviewTH2.size() == 1){
        chooseInterviewTH = chooseInterviewTH1 + ":0" + chooseInterviewTH2 + ":00";
    }else{
        chooseInterviewTH = chooseInterviewTH1 + ":" + chooseInterviewTH2 + ":00";
    }

    if(chooseInterview == "0" || chooseInterview == nullptr)
        return;
    //qDebug() << chooseInterviewTH << treeWidgetItem->childCount();
    int tmp = -99, color = 0;
    std::map<QString, QTreeWidgetItem*> TimeMap;   // 存储时间 - 行数
    for (int i = 0; i < treeWidgetItem->childCount(); i++) {
        QTreeWidgetItem *child = treeWidgetItem->child(i);
        QString childTime = child->text(1) + ":00";
        if(childTime.size() == 7){
            childTime.prepend("0");
        }
        auto lastItem = TimeMap.rbegin();
        if(lastItem != TimeMap.rend()){
            QString TimeDiff1 = calculateTimeDifference(lastItem->first, childTime);
            bool b = timeReduce(TimeDiff1, chooseInterviewTH);
            if(b){    // 满足条件treeWidgetItem画标记
                //qDebug() << tmp;
                if(i == tmp + 2){   // 大于等于连续的三个面试间隔时间小于阈值
                    color--;
                }
                //qDebug() << color;
                if(color % 2 == 0){
                    lastItem->second->setBackground(1, QBrush(QColor(0, 0, 128)));
                    child->setBackground(1, QBrush(QColor(0, 0, 128)));
                    color++;
                }else{
                    lastItem->second->setBackground(1, QBrush(QColor(34, 139, 34)));
                    child->setBackground(1, QBrush(QColor(34, 139, 34)));
                    color++;
                }
                tmp = i - 1;
            }
        }
        TimeMap[childTime] = child;
    }
}



void MainWindow::onItemExpanded(QTreeWidgetItem *item)
{
    std::multimap<QString, QTreeWidgetItem*, StringCompare> sortedChildren;
    int oldItemNum = item->childCount(), t = 0;
    for (int i = 0; i < oldItemNum; ++i) {
        //qDebug() << oldItemNum;
        QStringList list;
        QTreeWidgetItem *childItem = item->child(i);
        // list << childItem->text(0) << childItem->text(1) << childItem->text(2) << childItem->text(3) << childItem->text(4);
        // QTreeWidgetItem *childItem1 = new QTreeWidgetItem(item,list); // 加到尾巴
        //QTreeWidgetItem *childItem = item->child(i);
        QString TimeString1 = childItem->text(1);
        sortedChildren.insert(std::make_pair(TimeString1, childItem));
        //sortedChildren[TimeString1] = childItem; map--支持
    }

    //移除所有子项 -- 父类的指针被删除，但是对象空间不被删除
    while(t < oldItemNum){
        item->removeChild(item->child(0));
        t++;
    }
    // 按日期排序后重新添加子项
    for (auto it = sortedChildren.begin(); it != sortedChildren.end(); ++it) {

        item->addChild(it->second);
        QTreeWidgetItem *childItem = it->second;
        // 设置每个列的对齐方式为居中
        for (int col = 0; col < childItem->columnCount(); ++col) {
            childItem->setTextAlignment(col, Qt::AlignCenter);
        }
        //qDebug() << itemRow[it.value()];
        QPushButton *button = new QPushButton("修改面试信息", ui->scrollArea_2);
        QPushButton *button2 = new QPushButton("查看面试内容", ui->scrollArea_2);
        QPushButton *button3 = new QPushButton("删除", ui->scrollArea_2);
        QPushButton *button4 = new QPushButton("全部删除", ui->scrollArea_2);

        // 将自定义小部件添加到树节点的第4,5列中
        ui->treeWidget->setItemWidget(childItem, 5, button);
        ui->treeWidget->setItemWidget(childItem, 4, button2);
        ui->treeWidget->setItemWidget(childItem, 6, button3);
        ui->treeWidget->setItemWidget(childItem->parent(), 6, button4);

        connect(button, &QPushButton::clicked, this, [=]() {
            onButtonClicked(childItem);
        });

        connect(button2, &QPushButton::clicked, this, [=]() {
            onButton2Clicked(childItem);
        });

        connect(button3, &QPushButton::clicked, this, [=]() {
            QMessageBox messageBox;
            QPushButton *ok = messageBox.addButton("确定", QMessageBox::AcceptRole);
            QPushButton *cancel = messageBox.addButton("取消", QMessageBox::RejectRole);

            messageBox.setWindowTitle("删除面试信息");
            messageBox.resize(500,500);
            messageBox.setText("确定删除?");

            messageBox.exec();
            if(messageBox.clickedButton() == ok){
                onButton3Clicked(childItem);
            }

            //onButton3Clicked(childItem);
        });

        QString date = item->text(0);
        connect(button4, &QPushButton::clicked, this, [=]() {
            QMessageBox messageBox;
            QPushButton *ok = messageBox.addButton("确定", QMessageBox::AcceptRole);
            QPushButton *cancel = messageBox.addButton("取消", QMessageBox::RejectRole);

            messageBox.setWindowTitle("删除全部面试信息");
            messageBox.resize(500,500);
            messageBox.setText("确定删除?");

            messageBox.exec();
            if(messageBox.clickedButton() == ok){
                onButton4Clicked(date);
            }
        });

    }
    testInterviewTime(item);
}

void MainWindow::onItemCollapsed(QTreeWidgetItem *item)
{
    QWidget *buttonWidget = ui->treeWidget->itemWidget(item,6);
    if (buttonWidget) {
        ui->treeWidget->removeItemWidget(item, 6);
        delete buttonWidget;
    }
}







