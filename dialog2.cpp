#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::setLineText(QLineEdit *lineedit, QString &string)
{
    lineedit->setText(string);
}

QLineEdit *Dialog2::getLineEdit(int num)
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
    else if(num == 6)
        return ui->lineEdit_6;
    else if(num == 7)
        return ui->lineEdit_7;
    else if(num == 8)
        return ui->lineEdit_8;
    return nullptr;

}

QDialogButtonBox *Dialog2::getdialogbuttonbox()
{
    return this->ui->buttonBox;
}
