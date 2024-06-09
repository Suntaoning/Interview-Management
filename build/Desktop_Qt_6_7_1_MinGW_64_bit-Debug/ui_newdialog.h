/********************************************************************************
** Form generated from reading UI file 'newdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDIALOG_H
#define UI_NEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_newDialog
{
public:
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_4;
    QLabel *label_4;

    void setupUi(QDialog *newDialog)
    {
        if (newDialog->objectName().isEmpty())
            newDialog->setObjectName("newDialog");
        newDialog->resize(400, 300);
        label_5 = new QLabel(newDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 150, 71, 16));
        lineEdit_5 = new QLineEdit(newDialog);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(120, 150, 171, 21));
        lineEdit_5->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        label_3 = new QLabel(newDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 90, 71, 16));
        buttonBox = new QDialogButtonBox(newDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(60, 190, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit_2 = new QLineEdit(newDialog);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(120, 60, 171, 21));
        label_2 = new QLabel(newDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 60, 71, 16));
        lineEdit_3 = new QLineEdit(newDialog);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(120, 90, 171, 21));
        lineEdit = new QLineEdit(newDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 30, 171, 21));
        label = new QLabel(newDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 71, 16));
        lineEdit_4 = new QLineEdit(newDialog);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(120, 120, 171, 21));
        label_4 = new QLabel(newDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 120, 71, 16));

        retranslateUi(newDialog);

        QMetaObject::connectSlotsByName(newDialog);
    } // setupUi

    void retranslateUi(QDialog *newDialog)
    {
        newDialog->setWindowTitle(QCoreApplication::translate("newDialog", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("newDialog", "\351\235\242\350\257\225\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("newDialog", "\351\235\242\350\257\225\345\262\227\344\275\215", nullptr));
        label_2->setText(QCoreApplication::translate("newDialog", "\351\235\242\350\257\225\351\203\250\351\227\250", nullptr));
        label->setText(QCoreApplication::translate("newDialog", "\351\235\242\350\257\225\344\274\201\344\270\232", nullptr));
        label_4->setText(QCoreApplication::translate("newDialog", "\351\235\242\350\257\225\346\227\245\346\234\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newDialog: public Ui_newDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDIALOG_H
