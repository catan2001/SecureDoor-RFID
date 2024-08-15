#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QMenu>
#include <QMenuBar>
#include <QDesktopServices>
#include <QListWidget>
#include <QLineEdit>
#include <QWidgetAction>
#include <QAction>
#include <QStringList>
#include <QDebug>
#include <QTimer>
#include <QResizeEvent>
#include <include/add_new_dialog.h>
#include <include/settingsdialog.h>
#include <include/searchdialog.h>
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
    void on_actionFull_Screen_triggered();
    void on_actionNormal_triggered();
    void on_actionMinimize_triggered();
    void on_actionShow_Right_Sidebar_triggered();
    void on_actionShow_Left_Sidebar_triggered();
    void on_actionSearch_triggered();
    void on_actionMonitor_triggered();
    void on_actionAdd_New_Client_triggered();
    void on_actionGithub_source_triggered();
    void on_actionReadMe_triggered();
    void on_actionDeveloper_triggered();
    void on_actionLicense_triggered();
    void on_actionContents_2_triggered();
    void handleResize(void);


private:
    Ui::MainWindow *ui;

    Add_New_Dialog *NewClientDialog;
    SettingsDialog *settingsDialog;
    SearchDialog *searchDialog;
    hidden_t if_hidden = NOT_HIDDEN;
    hidden_t leftSideBarIfHidden = NOT_HIDDEN;
    QAction *searchAction;
    QLineEdit *searchWidget;
    void readXmlData(char *path);
    void writeXmlData(char *path);
    void resizeEvent(QResizeEvent *event) override; // overrides resize event to fit picture
};

#endif // MAINWINDOW_H
