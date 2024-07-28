#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QListWidget>
#include "add_new_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void startUp();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);
    //void on_pushButtonAdd_clicked();
    void dataUse(NewClientStruct &structure);

    void on_listWidgetOptions1_itemClicked(QListWidgetItem *item);

    void on_pushButtonLoad_clicked();

private:
    Ui::MainWindow *ui;
    Add_New_Dialog *NewClientDialog;
};

#endif // MAINWINDOW_H
