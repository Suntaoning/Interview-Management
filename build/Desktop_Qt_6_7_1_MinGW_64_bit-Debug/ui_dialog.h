/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_3;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_5;
    QLabel *label;
    QLabel *label_6;

    void setupUi(QWidget *new_dialog)
    {
        if (new_dialog->objectName().isEmpty())
            new_dialog->setObjectName("new_dialog");
        new_dialog->resize(417, 263);
        buttonBox = new QDialogButtonBox(new_dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(60, 190, 191, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_5 = new QLabel(new_dialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 150, 71, 16));
        lineEdit_4 = new QLineEdit(new_dialog);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(120, 120, 171, 21));
        lineEdit_3 = new QLineEdit(new_dialog);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(120, 90, 171, 21));
        label_1 = new QLabel(new_dialog);
        label_1->setObjectName("label_1");
        label_1->setGeometry(QRect(40, 30, 71, 16));
        label_2 = new QLabel(new_dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 60, 71, 16));
        label_4 = new QLabel(new_dialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 120, 71, 16));
        label_3 = new QLabel(new_dialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 90, 71, 16));
        lineEdit_2 = new QLineEdit(new_dialog);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(120, 60, 171, 21));
        lineEdit_1 = new QLineEdit(new_dialog);
        lineEdit_1->setObjectName("lineEdit_1");
        lineEdit_1->setGeometry(QRect(120, 30, 171, 21));
        lineEdit_5 = new QLineEdit(new_dialog);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(120, 150, 171, 21));
        label = new QLabel(new_dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 120, 91, 21));
        label_6 = new QLabel(new_dialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(300, 150, 81, 21));

        retranslateUi(new_dialog);

        QMetaObject::connectSlotsByName(new_dialog);
    } // setupUi

    void retranslateUi(QWidget *new_dialog)
    {
        new_dialog->setWindowTitle(QCoreApplication::translate("new_dialog", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("new_dialog", "\351\235\242\350\257\225\346\227\266\351\227\264", nullptr));
        label_1->setText(QCoreApplication::translate("new_dialog", "\351\235\242\350\257\225\344\274\201\344\270\232", nullptr));
        label_2->setText(QCoreApplication::translate("new_dialog", "\351\235\242\350\257\225\351\203\250\351\227\250", nullptr));
        label_4->setText(QCoreApplication::translate("new_dialog", "\351\235\242\350\257\225\346\227\245\346\234\237", nullptr));
        label_3->setText(QCoreApplication::translate("new_dialog", "\351\235\242\350\257\225\345\262\227\344\275\215", nullptr));
        label->setText(QCoreApplication::translate("new_dialog", "YY/MM/DD\346\240\274\345\274\217", nullptr));
        label_6->setText(QCoreApplication::translate("new_dialog", "XX:YY\346\240\274\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_dialog: public Ui_new_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
