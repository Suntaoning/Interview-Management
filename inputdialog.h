#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QWidget>
#include <QDialog>

class Inputdialog : public QDialog
{
    Q_OBJECT
public:
    explicit Inputdialog(QWidget *parent = nullptr);

signals:
};

#endif // INPUTDIALOG_H
