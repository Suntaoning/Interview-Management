#ifndef WIDGET_FORM1_H
#define WIDGET_FORM1_H

#include <QWidget>

namespace Ui {
class widget_Form1;
}

class widget_Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit widget_Form1(QWidget *parent = nullptr);
    ~widget_Form1();

private:
    Ui::widget_Form1 *ui;
};

#endif // WIDGET_FORM1_H
