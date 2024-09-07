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

#include "include/settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    ui->lineEditCurrentPassword->setStyleSheet("QLineEdit"
                                     "{background-color : #3f3f3f;"
                                     "border : 2px solid #111111;"
                                     "padding : 6px;"
                                     "color : #A9A9A9;"
                                     "min-width : 10em;}");

    ui->lineEditNewPassword->setStyleSheet("QLineEdit"
                                     "{background-color : #3f3f3f;"
                                     "border : 2px solid #111111;"
                                     "padding : 6px;"
                                     "color : #A9A9A9;"
                                     "min-width : 10em;}");

    ui->lineEditConfirmPassword->setStyleSheet("QLineEdit"
                                     "{background-color : #3f3f3f;"
                                     "border : 2px solid #111111;"
                                     "padding : 6px;"
                                     "color : #A9A9A9;"
                                     "min-width : 10em;}");

    ui->labelSettings->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->labelChangePassword->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->labelCurrentPassword->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->labelNewPassword->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->labelConfirmPassword->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->labelCurrentPasswordInfo->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->labelNewPasswordInfo->setStyleSheet("QLabel {color: #A9A9A9;}");

    ui->pushButtonConfirm->setStyleSheet("QPushButton"
                                       "{border : 2px solid #111111;"
                                       "background-color : #3f3f3f;"
                                       "padding: 6px;"
                                       "min-width: 3em;"
                                       "color: #A9A9A9;}"
                                       "QPushButton:pressed"
                                       "{background-color: #7393B3;"
                                       "color: #eeeeee;}");

    ui->pushButtonSave->setStyleSheet("QPushButton"
                                       "{border : 2px solid #111111;"
                                       "background-color : #3f3f3f;"
                                       "padding: 6px;"
                                       "min-width: 3em;"
                                       "color: #A9A9A9;}"
                                       "QPushButton:pressed"
                                       "{background-color: #7393B3;"
                                       "color: #eeeeee;}");

    ui->pushButtonCancel->setStyleSheet("QPushButton "
                                         "{border : 2px solid #111111;"
                                         "background-color : #3f3f3f;"
                                         "padding: 6px;"
                                         "min-width: 3em;"
                                         "color: #A9A9A9; }"
                                         "QPushButton:pressed"
                                         "{background-color: #900C3F;"
                                         "color: #eeeeee;}");
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_pushButtonConfirm_clicked()
{
    const QString login_password = ui->lineEditCurrentPassword->text();
    if(authenticate(login_password.toStdString().data()) == SUCCESS_PASS) {
        ui->labelCurrentPasswordInfo->setStyleSheet("QLabel {color: #008000;}");
        ui->labelCurrentPasswordInfo->setText("Success!");
    }
    else {
        ui->labelCurrentPasswordInfo->setStyleSheet("QLabel {color: #bf1206;}");
        ui->labelCurrentPasswordInfo->setText("Password is incorrect!");
        correct = INCORRECT;
        return;
    }
    if(ui->lineEditNewPassword->text().isEmpty())
    {
        ui->labelNewPasswordInfo->setStyleSheet("QLabel {color: #bf1206;}");
        ui->labelNewPasswordInfo->setText("New Password is not entered!");
        correct = INCORRECT;
        return;
    }
    if(ui->lineEditNewPassword->text() == ui->lineEditConfirmPassword->text()) {
        ui->labelNewPasswordInfo->setStyleSheet("QLabel {color: #008000;}");
        ui->labelNewPasswordInfo->setText("Success!");
    }
    else {
        ui->labelNewPasswordInfo->setStyleSheet("QLabel {color: #bf1206;}");
        ui->labelNewPasswordInfo->setText("Passwords are not same!");
        correct = INCORRECT;
        return;
    }
    correct = CORRECT;
}


void SettingsDialog::on_pushButtonSave_clicked()
{
    //TODO: THERES A BUG IN SHA256
    const char salt[] = "89ZhK$#!__)9mjjjk"; // CHANGE FOR SECURITY REASONS!
    char newPassword[100];
    unsigned int newPasswordSha[8];
    size_t salt_len = strlen(salt);
    size_t qNewPasswordLen = ui->lineEditNewPassword->text().size();

    strcpy(newPassword,ui->lineEditNewPassword->text().toStdString().data());

    if(correct == CORRECT) { // salt add
        FILE *fp = fopen("../config/config", "w");
        if(fp == NULL) return;
        for(unsigned int i = 0; i < strlen(newPassword); ++i) {
            newPassword[i] = newPassword[i]/2 + salt[i%salt_len]; //salting
        }
        if(sha_256(newPassword, newPasswordSha) != 0) {
            return;
        }
        for(unsigned char i = 0; i < 8; ++i)
          fprintf(fp, "%04x", newPasswordSha[i]);
        fclose(fp);
    }
    else {
        ui->labelNewPasswordInfo->setStyleSheet("QLabel {color: #bf1206;}");
        ui->labelNewPasswordInfo->setText("Please Confirm New Password!");
        ui->labelCurrentPasswordInfo->setStyleSheet("QLabel {color: #bf1206;}");
        ui->labelCurrentPasswordInfo->setText("Please Confirm New Password!");
        return;
    }
}

void SettingsDialog::on_pushButtonCancel_clicked()
{
    QWidget::close();
    //this->close(); // any difference?
}

