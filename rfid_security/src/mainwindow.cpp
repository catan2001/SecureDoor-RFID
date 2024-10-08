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

#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->listWidget->setStyleSheet("QListWidget"
                                  "{background-color : #1a1a1a;" // darker gray-black
                                  "color: #C0C0C0;}" // white

                                  "QListWidget::item"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:hover"
                                  "{background-color: #152238;"
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:selected"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0}");

    ui->listWidgetSideBar2->setStyleSheet("QListWidget"
                                  "{background-color : #1a1a1a;" // darker gray-black
                                  "color: #C0C0C0;}" // white

                                  "QListWidget::item"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:hover"
                                  "{background-color: #152238;"
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:selected"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0}");

    ui->listWidgetOptions1->setStyleSheet("QListWidget"
                                  "{background-color : transparent;" //
                                  "color: #C0C0C0;}" // white

                                  "QListWidget::item"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:hover"
                                  "{background-color: #4863A0;" //4863A0
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:selected"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0}");

    ui->listWidgetHistory->setStyleSheet("QListWidget"
                                  "{background-color : #444444;" // darker gray-black
                                  "color: #C0C0C0;"
                                  "border: 3px solid #1a1a1a;}" // dark gray/blue

                                  "QListWidget::item"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:hover"
                                  "{background-color: #152238;"
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:selected"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0}");

    ui->statusbar->setStyleSheet("QStatusBar"
                                 "{color: #eeeeee}"); // white

    ui->tableWidget->setStyleSheet("QTableWidget"
                                   "{background-color : #444444;"
                                   "border: 1px solid #1a1a1a;"
                                   "gridline-color: #1a1a1a;"
                                   "color: #eeeeee;"
                                   "outline : 0;}"

                                   "QTableView::disabled"
                                   "{background-color: #242526;"
                                   "border: 1px solid #32414B;"
                                   "color: #656565;"
                                   "gridline-color: #656565;"
                                   "outline : 0;}"

                                   "QTableView::item:hover"
                                   "{background-color: #C0C0C0;" //233040
                                   "color: #eeeeee;}"

                                   "QTableView::item:selected"
                                   "{background-color: #404040;"
                                   "border: 2px solid #808080;"
                                   "color: #eeeeee;}"

                                   "QLineEdit"
                                   "{background-color: #404040;"
                                   "border: 2px solid #808080;"
                                   "color: #eeeeee;}"

                                   "QTableView::item:selected:disabled"
                                   "{background-color: #1a1b1c;"
                                   "border: 2px solid #525251;"
                                   "color: #656565;}");

    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section"
                                   "{background-color: #242526;"
                                   "color: #eeeeee;"
                                   "padding: 4px;}"

                                    "QHeaderView::section:hover"
                                    "{background-color: #4969ff;"
                                    "color: #eeeeee;}"

                                   "QHeaderView::section:selected"
                                   "{background-color: #eeeeee;"
                                   "color: #656565;}"

                                   "QHeaderView::section:checked"
                                   "{color: #fff;"
                                   "background-color: #4969ff;}");

    ui->labelSettings->setStyleSheet("QLabel{color: #eeeeee;}");
    ui->labelEmail->setStyleSheet("QLabel{color: #eeeeee;}");
    ui->labelReadEmail->setStyleSheet("QLabel{color: #eeeeee;}");
    ui->labelName->setStyleSheet("QLabel{color: #eeeeee;}");
    ui->labelReadName->setStyleSheet("QLabel{color: #eeeeee;}");
    ui->labelLastName->setStyleSheet("QLabel{color: #eeeeee;}");
    ui->labelReadLastName->setStyleSheet("QLabel{color: #eeeeee;}");
    ui->labelTime->setStyleSheet("QLabel{color: #eeeeee;}");
    ui->labelReadTime->setStyleSheet("QLabel{color: #eeeeee;}");

    ui->LabelReadImage->setStyleSheet("QLabel{"
                                      "border : 2px solid #111111;"
                                      "padding: 6px;"
                                      "background-color: #212121;"
                                      "}");

    ui->pushButtonLoad->setStyleSheet("QPushButton"
                                     "{border : 2px solid #111111;"
                                     "background-color : #3f3f3f;"
                                     "padding: 6px;"
                                     "min-width: 4em;"
                                     "color: #A9A9A9;}"
                                     "QPushButton:pressed"
                                     "{background-color: #7393B3;"
                                     "color: #eeeeee;}");

    ui->pushButtonSaveData->setStyleSheet("QPushButton"
                                     "{border : 2px solid #111111;"
                                     "background-color : #3f3f3f;"
                                     "padding: 6px;"
                                     "min-width: 4em;"
                                     "color: #A9A9A9;}"
                                     "QPushButton:pressed"
                                     "{background-color: #7393B3;"
                                     "color: #eeeeee;}");

    QIcon icon;
    QPixmap pixmap;
    pixmap.load("../icons/ClientsOff.png"); // when not selected
    icon.addPixmap(pixmap, QIcon::Normal);
    pixmap.load("../icons/ClientsOn.png"); // when selected
    icon.addPixmap(pixmap, QIcon::Selected);
    if(!icon.isNull()){
        ui->listWidget->item(0)->setIcon(icon);
    }

    pixmap.load("../icons/MonitorOff.png"); // when not selected
    icon.addPixmap(pixmap, QIcon::Normal);
    pixmap.load("../icons/MonitorOn.png"); // when selected
    icon.addPixmap(pixmap, QIcon::Selected);
    if(!icon.isNull()){
        ui->listWidget->item(1)->setIcon(icon);
    }

    icon = QIcon("../icons/AddIconOn.png");
    if(!icon.isNull()){
        ui->listWidgetSideBar2->item(0)->setIcon(icon);
    }

    icon = QIcon("../icons/SearchIconOn.png");
    if(!icon.isNull()){
        ui->listWidgetSideBar2->item(1)->setIcon(icon);
    }

    icon = QIcon("../icons/SettingsIconOn.png");
    if(!icon.isNull()){
        ui->listWidgetSideBar2->item(2)->setIcon(icon);
    }

    icon = QIcon("../icons/AddClientOn.png");
    if(!icon.isNull()){
        ui->listWidgetOptions1->item(0)->setIcon(icon);
    }

    icon = QIcon("../icons/GarbageOn.png");
    if(!icon.isNull()){
        ui->listWidgetOptions1->item(1)->setIcon(icon);
    }

    icon = QIcon("../icons/RFIDOn.png");
    if(!icon.isNull()){
        ui->listWidgetOptions1->item(2)->setIcon(icon);
    }

    icon = QIcon("../icons/ShowHideOn.png");
    if(!icon.isNull()){
        ui->listWidgetOptions1->item(3)->setIcon(icon);
    }

    ui->statusbar->showMessage("Welcome! SecureDoor greets you!");
    ui->stackedWidget->setCurrentWidget(ui->page_Clients);
    ui->listWidget->item(0)->setSelected(true);
    ui->listWidget->selectionModel()->select(ui->listWidget->currentIndex(), QItemSelectionModel::NoUpdate);
    ui->listWidget->item(0)->setSelected(true);

    char path[] = "../config/dataBase.xml";
    readXmlData(path);

    QTimer::singleShot(0, this, SLOT(handleResize()));

    thread = new QThread();
    rfidreader = new RFIDReader();

    rfidreader->moveToThread(thread);
    connect(thread, &QThread::started, rfidreader, &RFIDReader::readingProcess);
    connect(rfidreader, &RFIDReader::finished, thread, &QThread::quit);
    connect(rfidreader, &RFIDReader::finished, rfidreader, &RFIDReader::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    // connect RFIDReader's signal function sendRFIDtag to MainWindow's slot function readRFIDtag...
    QObject::connect(rfidreader, SIGNAL(sendRFIDtag(QString)), this, SLOT(readRFIDtag(QString)));
    thread->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleResize(void) {
    QResizeEvent event(ui->LabelReadImage->size(), ui->LabelReadImage->size());
    resizeEvent(&event);
    QPixmap pmap;
    pmap.load("../person2.png");
    if (!pmap.isNull()) {
        // Scale the pixmap to fit within the label while keeping the aspect ratio
        pmap = pmap.scaled(ui->LabelReadImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

        // Set the pixmap to the label
        ui->LabelReadImage->setPixmap(pmap);

        ui->LabelReadImage->setAlignment(Qt::AlignCenter);
    }
}

void MainWindow::dataUse(NewClientStruct &structure) {
    qDebug() << "Connected!\n";

    auto model = ui->tableWidget->model();

    //if(ui->tableWidget->rowCount() <= 0) ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    model->setData(model->index(ui->tableWidget->rowCount()-1, 0), structure.firstName);
    model->setData(model->index(ui->tableWidget->rowCount()-1, 1), structure.lastName);
    model->setData(model->index(ui->tableWidget->rowCount()-1, 2), structure.emailAddress);
    model->setData(model->index(ui->tableWidget->rowCount()-1, 3), structure.RFIDTag);
    model->setData(model->index(ui->tableWidget->rowCount()-1, 4), structure.imagePath);
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if(item == ui->listWidget->item(0))
        ui->stackedWidget->setCurrentWidget(ui->page_Clients);
    if(item == ui->listWidget->item(1))
        ui->stackedWidget->setCurrentWidget(ui->page_Monitor);
}

void MainWindow::on_listWidgetOptions1_itemClicked(QListWidgetItem *item)
{
    if(item == ui->listWidgetOptions1->item(0)) {
        NewClientDialog = new Add_New_Dialog(this);
        NewClientDialog->setStyleSheet("QDialog {border: 2px solid #111111; "
                                       "background: no;"
                                       "background-color : #222222; "
                                       "padding: 2px }");
        NewClientDialog->show();
        // connect NewClientDialog with MainWindow to get data
        QObject::connect(NewClientDialog, SIGNAL(dataChanged(NewClientStruct &)),
                         this, SLOT(dataUse(NewClientStruct &)));
        QObject::connect(rfidreader, SIGNAL(sendRFIDtag(QString)), NewClientDialog, SLOT(readRFIDtag(QString)));
    }

    // REMOVE ROW FROM TABLE
    if(item == ui->listWidgetOptions1->item(1)) {
        if(ui->tableWidget->currentRow()>=0) {
            ui->tableWidget->removeRow(ui->tableWidget->currentRow());
        }
    }

    //TODO: SCAN RFID
    if(item == ui->listWidgetOptions1->item(2)) {
        //just for debug purpose;
        auto model = ui->tableWidget->model();
        model->setData(model->index(ui->tableWidget->currentRow(), 3), readRFIDTag);
    }

    // hides listWidgetHistory
    if(item == ui->listWidgetOptions1->item(3)) {
        if(if_hidden == NOT_HIDDEN) {
            ui->listWidgetHistory->hide();
            if_hidden = HIDDEN;
        }
        else {
            ui->listWidgetHistory->show();
            if_hidden = NOT_HIDDEN;
        }
    }
}

void MainWindow::on_listWidgetSideBar2_itemClicked(QListWidgetItem *item)
{
    if(item == ui->listWidgetSideBar2->item(0)) {
        NewClientDialog = new Add_New_Dialog(this);
        NewClientDialog->setStyleSheet("QDialog {border: 2px solid #111111; "
                                       "background: no;"
                                       "background-color : #222222; "
                                       "padding: 2px }");
        NewClientDialog->show();
        // connect NewClientDialog with MainWindow to get data
        QObject::connect(NewClientDialog, SIGNAL(dataChanged(NewClientStruct &)),
                         this, SLOT(dataUse(NewClientStruct &)));
        QObject::connect(rfidreader, SIGNAL(sendRFIDtag(QString)), NewClientDialog, SLOT(readRFIDtag(QString)));
    }
    if(item == ui->listWidgetSideBar2->item(1)) {

        searchDialog = new SearchDialog(this);
        searchDialog->setStyleSheet("QDialog {border: 2px solid #111111; "
                                      "background: no;"
                                      "background-color : #222222; "
                                      "padding: 2px }");
        searchDialog->show();
        QObject::connect(searchDialog, SIGNAL(commandClicked(search_t &)),
                         this, SLOT(commandUse(search_t &)));
    }
    if(item == ui->listWidgetSideBar2->item(2)) {

        settingsDialog = new SettingsDialog(this);
        settingsDialog->setStyleSheet("QDialog {border: 2px solid #111111; "
                                      "background: no;"
                                      "background-color : #222222; "
                                      "padding: 2px }");
        settingsDialog->show();
    }
}

void MainWindow::commandUse(search_t &searchTable) {
    ui->tableWidget->clearSelection();
    if(searchTable.cmd == SEARCH){
        unsigned int cnt = 0;
        for(int i = 0; i < ui->tableWidget->rowCount(); ++i) {
            // if any of conditions is true cnt++ else countinue to next iteration.
            if(searchTable.firstName == ui->tableWidget->item(i, 0)->text() && searchTable.lastName == ui->tableWidget->item(i, 1)->text() && searchTable.emailAddress == ui->tableWidget->item(i, 2)->text());
            else
            if(searchTable.lastName == ui->tableWidget->item(i, 1)->text() && searchTable.emailAddress == ui->tableWidget->item(i, 2)->text() && searchTable.firstName.isEmpty());
            else
            if(searchTable.firstName == ui->tableWidget->item(i, 0)->text() && searchTable.emailAddress == ui->tableWidget->item(i, 2)->text() && searchTable.lastName.isEmpty());
            else
            if(searchTable.firstName == ui->tableWidget->item(i, 0)->text() && searchTable.lastName == ui->tableWidget->item(i, 1)->text() && searchTable.emailAddress.isEmpty());
            else
            if(searchTable.firstName == ui->tableWidget->item(i, 0)->text() && searchTable.lastName.isEmpty() && searchTable.emailAddress.isEmpty());
            else
            if(searchTable.lastName == ui->tableWidget->item(i, 1)->text() && searchTable.firstName.isEmpty() && searchTable.emailAddress.isEmpty());
            else
            if(searchTable.emailAddress == ui->tableWidget->item(i, 2)->text() && searchTable.firstName.isEmpty() && searchTable.lastName.isEmpty());
            else
                continue;
            cnt++;
            searchTable.foundItems.push_back(i);
        }
        searchTable.numRows = cnt;
        if(cnt)
            ui->tableWidget->selectRow(searchTable.foundItems[0]);
    }
    else
    if(searchTable.cmd == NEXT && searchTable.numRows) {
        if(searchTable.currentItem < searchTable.numRows - 1)
            searchTable.currentItem++;
    }
    else
    if(searchTable.cmd == PREVIOUS && searchTable.numRows) {
        if(searchTable.currentItem > 0)
            searchTable.currentItem--;
    }
    if(searchTable.numRows)
        ui->tableWidget->selectRow(searchTable.foundItems[searchTable.currentItem]);
}

// reads Table from the file
void MainWindow::on_pushButtonLoad_clicked()
{
    QString DBdataPath = QFileDialog::getOpenFileName(this, "Open DataBase", "../config/", tr("XML files (*.xml);;Text files (*.txt)"));
    if(DBdataPath == NULL)
        return;
    QByteArray byteDataPath = DBdataPath.toUtf8();
    readXmlData(byteDataPath.data());
}

void MainWindow::on_pushButtonSaveData_clicked()
{
    QString DBdataPath = QFileDialog::getSaveFileName(this, "Save DataBase", "../config/config.xml", tr("XML files (*.xml);;Text files (*.txt)"));
    if(DBdataPath == NULL)
        return;
    QByteArray byteDataPath = DBdataPath.toUtf8();
    writeXmlData(byteDataPath.data());
}

// very simple function for reading data
// TODO: if enough time make lexer for XML file.
void MainWindow::readXmlData(char *path){
    FILE *fp;

    fp = fopen(path, "r");
    if(fp == NULL) return; // todo: ADD ERROR BOX JUMPS
    char firstName[50];
    char lastName[50];
    char emailAddress[70];
    char RFIDTag[70];
    char imagePath[100];
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    while(fscanf(fp, "<user><name> %s </name><lastname> %s </lastname><email> %s </email><rfid> %s </rfid><imgpath> %s </imgpath></user>\n", firstName, lastName, emailAddress, RFIDTag, imagePath) == 5)
    {
        auto model = ui->tableWidget->model();
        //if(ui->tableWidget->rowCount() <= 0) ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        model->setData(model->index(ui->tableWidget->rowCount()-1, 0), firstName);
        model->setData(model->index(ui->tableWidget->rowCount()-1, 1), lastName);
        model->setData(model->index(ui->tableWidget->rowCount()-1, 2), emailAddress);
        model->setData(model->index(ui->tableWidget->rowCount()-1, 3), RFIDTag);
        model->setData(model->index(ui->tableWidget->rowCount()-1, 4), imagePath);
    }
    fclose(fp);
}

void MainWindow::writeXmlData(char *path){
    FILE *fp;

    fp = fopen(path, "w+");
    if(fp == NULL) return; // todo: ADD ERROR BOX JUMPS
    int numberRows = ui->tableWidget->rowCount();
    for(int i = 0; i < numberRows; ++i) {
        for(int j = 0; j < 5; ++j) {
            if(ui->tableWidget->item(i, j)->text().isNull()) break;
            QTableWidgetItem *item = ui->tableWidget->item(i, j);
            QString temp = item->text();
            QByteArray byteTemp = temp.toUtf8();
            if(j == 0)
                fprintf(fp, "<user><name> %s </name>", byteTemp.data());
            if(j == 1)
                fprintf(fp, "<lastname> %s </lastname>", byteTemp.data());
            if(j == 2)
                fprintf(fp, "<email> %s </email>", byteTemp.data());
            if(j == 3)
                fprintf(fp, "<rfid> %s </rfid>", byteTemp.data());
            if(j == 4)
                fprintf(fp, "<imgpath> %s </imgpath></user>\n", byteTemp.data());
        }
    }
    fclose(fp);
}

/*
 * MenuBar trigger functions...
 */

void MainWindow::on_actionFull_Screen_triggered()
{
    this->showFullScreen();
}


void MainWindow::on_actionNormal_triggered()
{
    this->showMaximized();
}


void MainWindow::on_actionMinimize_triggered()
{
    this->showMinimized();
}


void MainWindow::on_actionShow_Right_Sidebar_triggered()
{
    if(if_hidden == NOT_HIDDEN) {
        ui->listWidgetHistory->hide();
        if_hidden = HIDDEN;
    }
    else {
        ui->listWidgetHistory->show();
        if_hidden = NOT_HIDDEN;
    }
}


void MainWindow::on_actionShow_Left_Sidebar_triggered()
{
        if(leftSideBarIfHidden == NOT_HIDDEN) {
            ui->listWidgetSideBar2->hide();
            leftSideBarIfHidden = HIDDEN;
        }
        else {
            ui->listWidgetSideBar2->show();
            leftSideBarIfHidden = NOT_HIDDEN;
        }
}


void MainWindow::on_actionSearch_triggered()
{
    searchDialog = new SearchDialog(this);
    searchDialog->setStyleSheet("QDialog {border: 2px solid #111111; "
                                  "background: no;"
                                  "background-color : #222222; "
                                  "padding: 2px }");
    searchDialog->show();
    QObject::connect(searchDialog, SIGNAL(commandClicked(search_t &)),
                     this, SLOT(commandUse(search_t &)));
}


void MainWindow::on_actionMonitor_triggered()
{
    ui->listWidget->item(1)->setSelected(true);
    ui->stackedWidget->setCurrentWidget(ui->page_Monitor);
}


void MainWindow::on_actionAdd_New_Client_triggered()
{
    NewClientDialog = new Add_New_Dialog(this);
    NewClientDialog->setStyleSheet("QDialog {border: 2px solid #111111; "
                                   "background: no;"
                                   "background-color : #222222; "
                                   "padding: 2px }");
    NewClientDialog->show();
    // connect NewClientDialog with MainWindow to get data
    QObject::connect(NewClientDialog, SIGNAL(dataChanged(NewClientStruct &)),
                     this, SLOT(dataUse(NewClientStruct &)));
}


void MainWindow::on_actionGithub_source_triggered()
{
    QUrl url("https://github.com/catan2001/RFID_security");
    QDesktopServices::openUrl(url);
}


void MainWindow::on_actionReadMe_triggered()
{
    QUrl url("https://github.com/catan2001/RFID_security/blob/main/README.md");
    QDesktopServices::openUrl(url);
}


void MainWindow::on_actionDeveloper_triggered()
{
    QUrl url("https://catan2001.github.io/");
    QDesktopServices::openUrl(url);
}


void MainWindow::on_actionLicense_triggered()
{
    QUrl url("https://github.com/catan2001/RFID_security/blob/main/LICENSE");
    QDesktopServices::openUrl(url);
}


void MainWindow::on_actionContents_2_triggered()
{
    QUrl url("https://mail.google.com/mail/u/1/?ogbl#inbox?compose=DmwnWrRqjKxFxsPxBVStDdCvNWmFJgqSkSmgxdkjLsKkFQrvzMJzcGCFgWvwkWsbzcLBDSjJHdLQ");
    QDesktopServices::openUrl(url);
}

void MainWindow::on_actionContents_triggered()
{
    QUrl url("https://github.com/catan2001/RFIDSecurity/blob/main/CONTENTS.md");
    QDesktopServices::openUrl(url);
}


void MainWindow::resizeEvent(QResizeEvent *event) {
    // TODO: change picture to the one needed
    QPixmap pmap;
    pmap.load(foundPersonImgPath);
    if (!pmap.isNull()) {
        // Scale the pixmap to fit within the label while keeping the aspect ratio
        pmap = pmap.scaled(ui->LabelReadImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

        // Set the pixmap to the label
        ui->LabelReadImage->setPixmap(pmap);
        ui->LabelReadImage->setAlignment(Qt::AlignCenter);
    }

    QWidget::resizeEvent(event); // Call the base class implementation
}


void MainWindow::readRFIDtag(QString rfidtag) {
    int numberRows = ui->tableWidget->rowCount();
    QPixmap pmap;
    QPixmap pmapScaled;
    QString personEntered;
    QString foundPersonImgPath;

    std::time_t result = std::time(nullptr);

    readRFIDTag = rfidtag;

    for(int i = 0; i < numberRows; ++i) {
        QTableWidgetItem *item = ui->tableWidget->item(i, 3);

        //TODO: resize as window gets resized

        if(rfidtag == item->text()) {

            personEntered = ui->tableWidget->item(i, 0)->text() + " " + ui->tableWidget->item(i, 1)->text();
            foundPersonImgPath = ui->tableWidget->item(i, 4)->text();

            ui->listWidgetHistory->insertItem(0, personEntered);
            ui->labelReadEmail->setText(ui->tableWidget->item(i, 2)->text());
            ui->labelReadLastName->setText(ui->tableWidget->item(i, 1)->text());
            ui->labelReadName->setText(ui->tableWidget->item(i, 0)->text());
            ui->labelReadTime->setText(QString::fromUtf8(asctime(std::localtime(&result))));

            pmap.load(foundPersonImgPath);
            if(!pmap.isNull()){
            pmap = pmap.scaled(ui->LabelReadImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

            ui->LabelReadImage->resize(pmap.width(), pmap.height());
            ui->LabelReadImage->setPixmap(pmap);
            ui->LabelReadImage->setScaledContents(false);
            }
            return;
        }
    }
    ui->listWidgetHistory->insertItem(0, "Warning, false access!");
 }
