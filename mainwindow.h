#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTableWidgetItem>
#include <QTreeWidget>
#include "dialog.h"
#include "dialog1.h"
#include "dialog2.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct StringCompare {
    bool operator()(const QString &lhs, const QString &rhs) const {
        if (lhs.length() == rhs.length()) {
            return lhs < rhs;
        }
        return lhs.length() < rhs.length();
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void display_excel(QTreeWidget *treeWidget);
    void display_today_excel();
    void onButtonClicked(QTreeWidgetItem *item);
    void onButton2Clicked(QTreeWidgetItem *item);
    void onButton3Clicked(QTreeWidgetItem *item);
    void onButton4Clicked(QString date);
    void testInterviewTime(QTreeWidgetItem *treeWidgetItem);
    void testTodayInterviewTime();
    void display_setting();
    ~MainWindow();

private slots:
    void on_action_triggered();
    void onItemExpanded(QTreeWidgetItem *item);
    void onItemCollapsed(QTreeWidgetItem *item);
    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
