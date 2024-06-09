#include "dialog.h"
#include "ui_dialog.h"

extern QString filePath;

using namespace std;

new_dialog::new_dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::new_dialog)
{
    ui->setupUi(this);
}

new_dialog::~new_dialog()
{
    delete ui;
}

void new_dialog::setLineText(QLineEdit *lineedit, QString &string)
{
    lineedit->setText(string);
}

QLineEdit *new_dialog::getLineEdit(int num)
{
    if(num == 1)
        return ui->lineEdit_1;
    else if(num == 2)
        return ui->lineEdit_2;
    else if(num == 3)
        return ui->lineEdit_3;
    else if(num == 4)
        return ui->lineEdit_4;
    else if(num == 5)
        return ui->lineEdit_5;

    return nullptr;

}

QDialogButtonBox *new_dialog::getdialogbuttonbox()
{
    return this->ui->buttonBox;
}


