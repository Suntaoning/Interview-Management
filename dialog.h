#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDir>
#include <QAxObject>
#include <QActionGroup>
#include <QPushButton>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QDialogButtonBox>
#include <QPlainTextEdit>
#include <QMessageBox>

namespace Ui {
class new_dialog;
}



class new_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit new_dialog(QWidget *parent = nullptr);
    ~new_dialog();
    void setLineText(QLineEdit *lineedit, QString &string);
    QLineEdit *getLineEdit(int num);
    QDialogButtonBox *getdialogbuttonbox();

private slots:


private:
    Ui::new_dialog *ui;
    int row;
};

#endif // DIALOG_H
