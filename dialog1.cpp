#include "dialog1.h"
#include "ui_dialog1.h"

Dialog1::Dialog1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::setText(QString &string)
{
    ui->plainTextEdit->setPlainText(string);
}

QPushButton *Dialog1::getbutton(int i)
{
    if(i == 1)
        return ui->pushButton;
    return ui->pushButton_2;
}

QString Dialog1::getTextEdit()
{
    return ui->plainTextEdit->toPlainText();;
}
