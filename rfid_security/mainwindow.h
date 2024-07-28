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
    void on_pushButton_4_clicked();
    void dataUse(NewClientStruct &structure);

private:
    Ui::MainWindow *ui;
    Add_New_Dialog *NewClientDialog;
};

#endif // MAINWINDOW_H
