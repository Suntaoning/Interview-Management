#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QDialogButtonBox>
namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = nullptr);
    ~Dialog2();
    void setLineText(QLineEdit *lineedit, QString &string);
    QLineEdit *getLineEdit(int num);
    QDialogButtonBox *getdialogbuttonbox();

private:
    Ui::Dialog2 *ui;
};

#endif // DIALOG2_H
