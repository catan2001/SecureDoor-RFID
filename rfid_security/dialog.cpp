#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->cancelLoginPushButton->setStyleSheet("QPushButton "
                                             "{border : 2px solid #111111;"
                                             //"border-radius: 10px;"
                                             "background-color : #3f3f3f;"
                                             "padding: 6px;"
                                             "min-width: 3em;"
                                             "color: #A9A9A9; }"
                                             "QPushButton:pressed"
                                             "{background-color: #900C3F;"
                                             "color: #eeeeee;}");

    ui->acceptLoginPushButton->setStyleSheet("QPushButton"
                                             "{border : 2px solid #111111;"
                                             "background-color : #3f3f3f;"
                                             "padding: 6px;"
                                             "min-width: 3em;"
                                             "color: #A9A9A9;}"
                                             "QPushButton:pressed"
                                             "{background-color: #7393B3;"
                                             "color: #eeeeee;}");

    ui->passwordLabel->setStyleSheet("QLabel {color: #A9A9A9;}");

    ui->passwordLineEdit->setStyleSheet("QLineEdit"
                                   "{background-color : #3f3f3f;"
                                   "border : 2px solid #111111;"
                                   "padding : 6px;"
                                   "color : #A9A9A9;"
                                   "min-width : 10em;}");

    //ui->cancelLoginPushButton->fontMetrics()

    //login_label = new Qlabel(this);

    /*ui->frame->setStyleSheet("QFrame {border: 2px solid #3f3f3f; "
                             "background-color : #3f3f3f; "
                             "color : blue; "
                             "padding: 2px }");
    ui->frame->setAutoFillBackground(true);
    ui->frame->adjustSize("200x200"); */

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_acceptLoginPushButton_clicked()
{
    // TODO: implement when correct password
}

