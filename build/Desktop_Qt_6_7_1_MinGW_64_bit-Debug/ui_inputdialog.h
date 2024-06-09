/********************************************************************************
** Form generated from reading UI file 'inputdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIALOG_H
#define UI_INPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Inputdialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;

    void setupUi(QDialog *Inputdialog)
    {
        if (Inputdialog->objectName().isEmpty())
            Inputdialog->setObjectName("Inputdialog");
        Inputdialog->resize(333, 251);
        Inputdialog->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        buttonBox = new QDialogButtonBox(Inputdialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(50, 190, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Inputdialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 71, 16));
        label_2 = new QLabel(Inputdialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 60, 71, 16));
        label_3 = new QLabel(Inputdialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 90, 71, 16));
        label_4 = new QLabel(Inputdialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 120, 71, 16));
        label_5 = new QLabel(Inputdialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 150, 71, 16));
        lineEdit = new QLineEdit(Inputdialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(110, 30, 171, 21));
        lineEdit_2 = new QLineEdit(Inputdialog);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(110, 60, 171, 21));
        lineEdit_3 = new QLineEdit(Inputdialog);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(110, 90, 171, 21));
        lineEdit_4 = new QLineEdit(Inputdialog);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(110, 120, 171, 21));
        lineEdit_5 = new QLineEdit(Inputdialog);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(110, 150, 171, 21));
        lineEdit_5->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        label_5->raise();
        label_2->raise();
        buttonBox->raise();
        lineEdit_3->raise();
        label->raise();
        label_4->raise();
        lineEdit_5->raise();
        lineEdit_4->raise();
        lineEdit_2->raise();
        lineEdit->raise();
        label_3->raise();

        retranslateUi(Inputdialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Inputdialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Inputdialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Inputdialog);
    } // setupUi

    void retranslateUi(QDialog *Inputdialog)
    {
        Inputdialog->setWindowTitle(QCoreApplication::translate("Inputdialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Inputdialog", "\351\235\242\350\257\225\344\274\201\344\270\232", nullptr));
        label_2->setText(QCoreApplication::translate("Inputdialog", "\351\235\242\350\257\225\351\203\250\351\227\250", nullptr));
        label_3->setText(QCoreApplication::translate("Inputdialog", "\351\235\242\350\257\225\345\262\227\344\275\215", nullptr));
        label_4->setText(QCoreApplication::translate("Inputdialog", "\351\235\242\350\257\225\346\227\245\346\234\237", nullptr));
        label_5->setText(QCoreApplication::translate("Inputdialog", "\351\235\242\350\257\225\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inputdialog: public Ui_Inputdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
