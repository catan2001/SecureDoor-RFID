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

#include "include/add_new_dialog.h"
#include "ui_add_new_dialog.h"

Add_New_Dialog::Add_New_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_New_Dialog)
{
    ui->setupUi(this);

    pmap.load("../person2.png");
    ui->Label_Picture->setPixmap(pmap);
    ui->Label_Picture->setAlignment(Qt::AlignCenter);
    ui->Label_Picture->setStyleSheet("QLabel"
                                     "{background-position: center;}");

    ui->LineEdit_Path->setStyleSheet("QLineEdit"
                                     "{background-color : #3f3f3f;"
                                     "border : 2px solid #111111;"
                                     "padding : 6px;"
                                     "color : #A9A9A9;"
                                     "min-width : 10em;}");

    ui->LineEdit_Email->setStyleSheet("QLineEdit"
                                      "{background-color : #3f3f3f;"
                                      "border : 2px solid #111111;"
                                      "padding : 6px;"
                                      "color : #A9A9A9;"
                                      "min-width : 10em;}");

    ui->LineEdit_LastName->setStyleSheet("QLineEdit"
                                         "{background-color : #3f3f3f;"
                                         "border : 2px solid #111111;"
                                         "padding : 6px;"
                                         "color : #A9A9A9;"
                                         "min-width : 10em;}");

    ui->LineEdit_Name->setStyleSheet("QLineEdit"
                                     "{background-color : #3f3f3f;"
                                     "border : 2px solid #111111;"
                                     "padding : 6px;"
                                     "color : #A9A9A9;"
                                     "min-width : 10em;}");

    ui->labelEmail->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->labelLastName->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->labelName->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->labelPath->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->labelRFID->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->labelEnterRFID->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->LableClientInfo->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->LableTitle->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->labelInfo->setStyleSheet("QLabel {color: #A9A9A9;}");

    ui->PushButton_Save->setStyleSheet("QPushButton"
                                       "{border : 2px solid #111111;"
                                       "background-color : #3f3f3f;"
                                       "padding: 6px;"
                                       "min-width: 3em;"
                                       "color: #A9A9A9;}"
                                       "QPushButton:pressed"
                                       "{background-color: #7393B3;"
                                       "color: #eeeeee;}");

    ui->PushButton_ScanTag->setStyleSheet("QPushButton"
                                          "{border : 2px solid #111111;"
                                          "background-color : #3f3f3f;"
                                          "padding: 6px;"
                                          "min-width: 3em;"
                                          "color: #A9A9A9;}"
                                          "QPushButton:pressed"
                                          "{background-color: #7393B3;"
                                          "color: #eeeeee;}");

    ui->PushButton_LoadNewImage->setStyleSheet("QPushButton"
                                               "{border : 2px solid #111111;"
                                               "background-color : #3f3f3f;"
                                               "padding: 6px;"
                                               "min-width: 3em;"
                                               "color: #A9A9A9;}"
                                               "QPushButton:pressed"
                                               "{background-color: #7393B3;"
                                               "color: #eeeeee;}");

    ui->PushButton_Cancel->setStyleSheet("QPushButton "
                                         "{border : 2px solid #111111;"
                                         "background-color : #3f3f3f;"
                                         "padding: 6px;"
                                         "min-width: 3em;"
                                         "color: #A9A9A9; }"
                                         "QPushButton:pressed"
                                         "{background-color: #900C3F;"
                                         "color: #eeeeee;}");

    ui->ToolButtonInfoNewClient->setStyleSheet("QToolButton"
                                               "{border : 2px solid #111111;"
                                               "background-color : #3f3f3f;"
                                               "padding: 6px;"
                                               "min-width: 3em;"
                                               "color: #A9A9A9; }"
                                               "QPushButton:pressed"
                                               "{background-color: #900C3F;"
                                               "color: #eeeeee;}");

    ui->ProgressBarTag->setStyleSheet("QProgressBar"
                                       "{border : 2px solid #111111;"
                                       "background-color : #3f3f3f;"
                                       "padding: 6px;}"
                                       "QProgressBar::Chunk"
                                       "{background-color : #66ff00;}");

}

Add_New_Dialog::~Add_New_Dialog()
{
    delete ui;
}

void Add_New_Dialog::on_PushButton_LoadNewImage_clicked()
{
    dataPath = QFileDialog::getOpenFileName(this, "Open Image", "../");
    ui->LineEdit_Path->insert(dataPath);
}

void Add_New_Dialog::on_LineEdit_Path_textEdited(const QString &arg1)
{
    pmap.load(arg1);
    if(!pmap.isNull()){
    pmap = pmap.scaledToHeight(330);
    pmap = pmap.scaledToWidth(330);
    ui->Label_Picture->setPixmap(pmap);
    }
}

void Add_New_Dialog::on_PushButton_ScanTag_clicked()
{
    ui->ProgressBarTag->setValue(25);
    ui->ProgressBarTag->setValue(75);
    ui->labelEnterRFID->setText(rfidTag);
    ui->ProgressBarTag->setValue(100);
}

void Add_New_Dialog::on_PushButton_Cancel_clicked()
{
    QWidget::close();
}

void Add_New_Dialog::on_ToolButtonInfoNewClient_clicked()
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setStyleSheet("QLabel {color: #eeeeee;}");
    msgBox->setText("Please Save an Image into Programs Folder");
    msgBox->exec();
    delete msgBox;
}

void Add_New_Dialog::on_PushButton_Save_clicked()
{
    NewClientStruct structure;
    if(ui->LineEdit_Name->text().isEmpty()) {
        ui->labelInfo->setStyleSheet("QLabel {color: #bf1206;}");
        ui->labelInfo->setText("Name is required!");
        return;
    }
    structure.firstName = ui->LineEdit_Name->text();

    if(ui->LineEdit_LastName->text().isEmpty()) {
        ui->labelInfo->setStyleSheet("QLabel {color: #bf1206;}");
        ui->labelInfo->setText("Last Name is required!");
        return;
    }
    structure.lastName = ui->LineEdit_LastName->text();

    if(ui->labelEnterRFID->text() == "RFID is not scanned") { // TODO: add another condition!
        ui->labelInfo->setStyleSheet("QLabel {color: #bf1206;}");
        ui->labelInfo->setText("RFID Tag is required!");
        return;
    }
    structure.RFIDTag = ui->labelEnterRFID->text();

    if(ui->LineEdit_Email->text().isEmpty())
        structure.emailAddress = "<empty>";
    else
        structure.emailAddress = ui->LineEdit_Email->text();

    if(ui->LineEdit_Path->text().isEmpty())
        structure.imagePath = "<empty>";
    else
        structure.imagePath = ui->LineEdit_Path->text();

    dataChanged(structure); // signal changes to MainWindow
    QWidget::close(); // close current Dialog
}

void Add_New_Dialog::readRFIDtag(QString rfidtag) {
    rfidTag = rfidtag;
}

