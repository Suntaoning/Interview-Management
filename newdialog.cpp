#include "newdialog.h"
#include "ui_newdialog.h"

newDialog::newDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::newDialog)
{
    ui->setupUi(this);
}

newDialog::~newDialog()
{
    delete ui;
}
