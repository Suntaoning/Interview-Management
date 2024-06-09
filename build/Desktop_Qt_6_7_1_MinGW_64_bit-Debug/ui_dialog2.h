/********************************************************************************
** Form generated from reading UI file 'dialog2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG2_H
#define UI_DIALOG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog2
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLineEdit *lineEdit_1;
    QDialogButtonBox *buttonBox;
    QLabel *label_1;
    QLineEdit *lineEdit_4;
    QLabel *label_2;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_8;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QDialog *Dialog2)
    {
        if (Dialog2->objectName().isEmpty())
            Dialog2->setObjectName("Dialog2");
        Dialog2->resize(394, 276);
        verticalLayout = new QVBoxLayout(Dialog2);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(Dialog2);
        widget->setObjectName("widget");
        lineEdit_1 = new QLineEdit(widget);
        lineEdit_1->setObjectName("lineEdit_1");
        lineEdit_1->setGeometry(QRect(110, 20, 171, 21));
        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(50, 180, 201, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_1 = new QLabel(widget);
        label_1->setObjectName("label_1");
        label_1->setGeometry(QRect(30, 20, 71, 16));
        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(110, 110, 51, 21));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 50, 71, 16));
        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(190, 110, 51, 21));
        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(110, 80, 171, 21));
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 140, 71, 16));
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 80, 71, 16));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(110, 50, 171, 21));
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 110, 71, 16));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 110, 16, 21));
        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(270, 110, 51, 21));
        lineEdit_7 = new QLineEdit(widget);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(110, 140, 51, 21));
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(250, 110, 21, 21));
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(330, 110, 21, 21));
        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(170, 140, 16, 21));
        lineEdit_8 = new QLineEdit(widget);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(190, 140, 51, 21));
        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(250, 140, 16, 21));
        label_10 = new QLabel(widget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(270, 140, 81, 21));

        verticalLayout->addWidget(widget);


        retranslateUi(Dialog2);

        QMetaObject::connectSlotsByName(Dialog2);
    } // setupUi

    void retranslateUi(QDialog *Dialog2)
    {
        Dialog2->setWindowTitle(QCoreApplication::translate("Dialog2", "Dialog", nullptr));
        label_1->setText(QCoreApplication::translate("Dialog2", "\351\235\242\350\257\225\344\274\201\344\270\232", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog2", "\351\235\242\350\257\225\351\203\250\351\227\250", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog2", "\351\235\242\350\257\225\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog2", "\351\235\242\350\257\225\345\262\227\344\275\215", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog2", "\351\235\242\350\257\225\346\227\245\346\234\237", nullptr));
        label->setText(QCoreApplication::translate("Dialog2", "\345\271\264", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog2", "\346\234\210", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog2", "\346\227\245", nullptr));
        label_8->setText(QCoreApplication::translate("Dialog2", "\346\227\266", nullptr));
        label_9->setText(QCoreApplication::translate("Dialog2", "\345\210\206", nullptr));
        label_10->setText(QCoreApplication::translate("Dialog2", "(24\345\260\217\346\227\266\345\210\266)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog2: public Ui_Dialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG2_H
