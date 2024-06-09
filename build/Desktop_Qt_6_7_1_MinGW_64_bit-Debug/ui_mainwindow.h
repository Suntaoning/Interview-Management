/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    QTreeWidget *treeWidget;
    QWidget *page_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QWidget *page_3;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1290, 621);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        action->setCheckable(true);
        action->setMenuRole(QAction::NoRole);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        action_2->setCheckable(true);
        action_2->setMenuRole(QAction::NoRole);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        action_3->setMenuRole(QAction::NoRole);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName("action_4");
        action_4->setMenuRole(QAction::NoRole);
        action_5 = new QAction(MainWindow);
        action_5->setObjectName("action_5");
        action_5->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        horizontalLayout_2 = new QHBoxLayout(page);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        scrollArea_2 = new QScrollArea(page);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 88, 579));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        treeWidget = new QTreeWidget(scrollAreaWidgetContents_2);
        treeWidget->headerItem()->setText(5, QString());
        treeWidget->headerItem()->setText(6, QString());
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(6, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(5, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(4, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(3, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(2, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(1, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setMinimumSize(QSize(0, 561));
        treeWidget->setStyleSheet(QString::fromUtf8(""));
        treeWidget->setAutoExpandDelay(20);

        verticalLayout_3->addWidget(treeWidget);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_2->addWidget(scrollArea_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        scrollArea = new QScrollArea(page_2);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 10, 1181, 541));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1179, 539));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 151, 41));
        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(140, 40, 61, 21));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 40, 31, 21));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(300, 40, 53, 21));
        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(230, 40, 61, 21));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 40, 80, 23));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(480, 40, 82, 21));
        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        verticalLayout = new QVBoxLayout(page_3);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea_3 = new QScrollArea(page_3);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 88, 88));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        tableWidget = new QTableWidget(scrollAreaWidgetContents_3);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");

        verticalLayout_4->addWidget(tableWidget);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        verticalLayout->addWidget(scrollArea_3);

        stackedWidget->addWidget(page_3);

        verticalLayout_2->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1290, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::LeftToolBarArea, toolBar);

        toolBar->addAction(action);
        toolBar->addAction(action_2);
        toolBar->addAction(action_3);
        toolBar->addAction(action_4);
        toolBar->addAction(action_5);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\344\273\212\346\227\245", nullptr));
        action_5->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("MainWindow", "\351\235\242\350\257\225\345\206\205\345\256\271", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("MainWindow", "\351\235\242\350\257\225\345\262\227\344\275\215", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("MainWindow", "\351\235\242\350\257\225\351\203\250\351\227\250", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "\351\235\242\350\257\225\346\227\266\351\227\264", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\351\235\242\350\257\225\346\227\245\346\234\237", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\234\200\344\275\216\351\235\242\350\257\225\351\227\264\351\232\224\351\230\210\345\200\274", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "h", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "min", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\220\257\346\255\244\351\200\211\351\241\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\351\235\242\350\257\225\344\274\201\344\270\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\351\235\242\350\257\225\351\203\250\351\227\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\351\235\242\350\257\225\345\262\227\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\351\235\242\350\257\225\346\227\266\351\227\264", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
