#include "widget_form1.h"
#include "ui_widget_form1.h"

widget_Form1::widget_Form1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget_Form1)
{
    ui->setupUi(this);
}

widget_Form1::~widget_Form1()
{
    delete ui;
}
