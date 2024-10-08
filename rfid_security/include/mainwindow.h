/*MIT License

Copyright (c) 2024 catan2001

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ctime>
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
#include <include/rfidreader.h>
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

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void dataUse(NewClientStruct &structure);
    void commandUse(search_t &searchTable);
    void on_listWidgetOptions1_itemClicked(QListWidgetItem *item);
    void on_listWidgetSideBar2_itemClicked(QListWidgetItem *item);
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
    void readRFIDtag(QString rfidtag);

    void on_actionContents_triggered();

private:
    Ui::MainWindow *ui;

    QString foundPersonImgPath;
    QThread* thread;
    RFIDReader* rfidreader;
    Add_New_Dialog *NewClientDialog;
    SettingsDialog *settingsDialog;
    SearchDialog *searchDialog;
    hidden_t if_hidden = NOT_HIDDEN;
    hidden_t leftSideBarIfHidden = NOT_HIDDEN;
    QAction *searchAction;
    QLineEdit *searchWidget;
    QString readRFIDTag;
    void readXmlData(char *path);
    void writeXmlData(char *path);
    void resizeEvent(QResizeEvent *event) override; // overrides resize event to fit picture
};

#endif // MAINWINDOW_H
