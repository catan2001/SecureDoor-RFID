#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QMenu>
#include <QMenuBar>
#include <QListWidget>
#include <QLineEdit>
#include <QWidgetAction>
#include <QAction>
#include <QStringList>
#include <QDebug>
#include <add_new_dialog.h>
#include <settingsdialog.h>
#include <searchdialog.h>
#include "sys/stat.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum HIDDEN {NOT_HIDDEN, HIDDEN};
typedef enum HIDDEN hidden_t ;

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
    void commandUse(search_t &searchTable);
    void on_listWidgetOptions1_itemClicked(QListWidgetItem *item);
    void on_listWidgetSideBar2_itemClicked(QListWidgetItem *item);
    void on_pushButtonDbgHistory_clicked();
    void on_pushButtonSaveData_clicked();
    void on_pushButtonLoad_clicked();

private:
    Ui::MainWindow *ui;

    Add_New_Dialog *NewClientDialog;
    SettingsDialog *settingsDialog;
    SearchDialog *searchDialog;
    hidden_t if_hidden = NOT_HIDDEN;
    QAction *searchAction;
    QLineEdit *searchWidget;
    void readXmlData(char *path);
    void writeXmlData(char *path);
};

#endif // MAINWINDOW_H
