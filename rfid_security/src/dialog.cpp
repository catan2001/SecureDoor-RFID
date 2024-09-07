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

#include "include/dialog.h"
#include "ui_dialog.h"
#include "QDebug"
#include "include/authenticate.h"

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

    if(mkdir("../config", 0777) < 0)
        qDebug() << "error in mkdir\n";
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_acceptLoginPushButton_clicked()
{
    const QString login_password = ui->passwordLineEdit->text();
    if(authenticate(login_password.toStdString().data()) == SUCCESS_PASS) {
        ui->passwordLineEdit->clear();
        this->close();
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
}

