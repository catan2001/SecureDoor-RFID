#include "dialog.h"
#include "ui_dialog.h"
#include "QDebug"
#include "authenticate.h"

using namespace std;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->personLabel->setStyleSheet("QLabel"
                              "{background: url(../person2.png);"
                              "background-repeat: no-repeat;"
                              "background-position: center;}");

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

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_acceptLoginPushButton_clicked()
{
    const QString login_password = ui->passwordLineEdit->text();
    const QString password = "admin";
    //char login_password_str[] = login_password.toStdString();
    qDebug() << login_password << "\n";
    if(authenticate(login_password.toStdString().data()) == SUCCESS_PASS) {
        ui->passwordLineEdit->clear();
        qDebug() << "success\n";
        this->hide();
        mainWin = new MainWindow(this);
        mainWin->showMaximized();
        mainWin->setStyleSheet("MainWindow "
                               "{border: 2px solid #111111; "
                               "background-color : #222222; "
                               "padding: 2px }");

    }
    else
        qDebug() << "fail!\n";
}




void Dialog::on_cancelLoginPushButton_clicked()
{
    ui->passwordLineEdit->clear();
    //this->destroy();
    //exit(EXIT_SUCCESS);
}

