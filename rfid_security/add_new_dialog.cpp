#include "add_new_dialog.h"
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
//                                     "{background: url(../person2.png);"
//                                     "background-repeat: no-repeat;"
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
                                         //"border-radius: 10px;"
                                         "background-color : #3f3f3f;"
                                         "padding: 6px;"
                                         "min-width: 3em;"
                                         "color: #A9A9A9; }"
                                         "QPushButton:pressed"
                                         "{background-color: #900C3F;"
                                         "color: #eeeeee;}");

    ui->ToolButtonInfoNewClient->setStyleSheet("QToolButton"
                                               "{border : 2px solid #111111;"
                                               //"border-radius: 10px;"
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
                                       //"color: #66ff00;"
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
    //pmap.load(dataPath);
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
    //todo: implement scan function here
    ui->ProgressBarTag->setValue(25);
    QString rfidTag = "3afdc96b35e60a6c3d98fc06ca8647ad5a106c862503cb64f982d260928c7285"; // admin password just for debug
    ui->ProgressBarTag->setValue(75);
    ui->labelEnterRFID->setText(rfidTag);
    ui->ProgressBarTag->setValue(100);
}

void Add_New_Dialog::on_PushButton_Cancel_clicked()
{
    //TODO implement pop-up {yes/no}
    QWidget::close();
}

void Add_New_Dialog::on_ToolButtonInfoNewClient_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Please Save an Image into Programs Folder");
    msgBox.exec();
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

