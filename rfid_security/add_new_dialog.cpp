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
    ui->Label_RFIDTag->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->LableClientInfo->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->LableTitle->setStyleSheet("QLabel {color: #A9A9A9;}");

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
    pmap = pmap.scaledToHeight(330);
    pmap = pmap.scaledToWidth(330);
    ui->Label_Picture->setPixmap(pmap);
}

