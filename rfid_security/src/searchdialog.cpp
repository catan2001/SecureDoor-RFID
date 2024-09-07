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

#include "include/searchdialog.h"
#include "ui_searchdialog.h"

search_t searchTable;

SearchDialog::SearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);

    ui->lineEditEmail->setStyleSheet("QLineEdit"
                                     "{background-color : #3f3f3f;"
                                     "border : 2px solid #111111;"
                                     "padding : 6px;"
                                     "color : #A9A9A9;"
                                     "min-width : 10em;}");

    ui->lineEditFirstName->setStyleSheet("QLineEdit"
                                     "{background-color : #3f3f3f;"
                                     "border : 2px solid #111111;"
                                     "padding : 6px;"
                                     "color : #A9A9A9;"
                                     "min-width : 10em;}");

    ui->lineEditLastName->setStyleSheet("QLineEdit"
                                     "{background-color : #3f3f3f;"
                                     "border : 2px solid #111111;"
                                     "padding : 6px;"
                                     "color : #A9A9A9;"
                                     "min-width : 10em;}");

    ui->pushButtonSearch->setStyleSheet("QPushButton"
                                       "{border : 2px solid #111111;"
                                       "background-color : #3f3f3f;"
                                       "padding: 6px;"
                                       "min-width: 3em;"
                                       "color: #A9A9A9;}"
                                       "QPushButton:pressed"
                                       "{background-color: #7393B3;"
                                       "color: #eeeeee;}");

    ui->pushButtonPrevious->setStyleSheet("QPushButton"
                                       "{border : 2px solid #111111;"
                                       "background-color : #3f3f3f;"
                                       "padding: 6px;"
                                       "min-width: 3em;"
                                       "color: #A9A9A9;}"
                                       "QPushButton:pressed"
                                       "{background-color: #C49102;"
                                       "color: #eeeeee;}");

    ui->pushButtonNext->setStyleSheet("QPushButton"
                                       "{border : 2px solid #111111;"
                                       "background-color : #3f3f3f;"
                                       "padding: 6px;"
                                       "min-width: 3em;"
                                       "color: #A9A9A9;}"
                                       "QPushButton:pressed"
                                       "{background-color: #C49102;"
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

    ui->labelSearchTitle->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->labelFirstName->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->labelLastName->setStyleSheet("QLabel {color: #A9A9A9;}");
    ui->labelEmail->setStyleSheet("QLabel {color: #A9A9A9;}");
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::on_pushButtonCancel_clicked()
{
    QWidget::close();
}

void SearchDialog::on_pushButtonSearch_clicked()
{
    searchTable.numRows = 0;
    searchTable.currentItem = 0;
    searchTable.foundItems.clear();
    searchTable.cmd = SEARCH;
    searchTable.firstName = ui->lineEditFirstName->text();
    searchTable.lastName = ui->lineEditLastName->text();
    searchTable.emailAddress = ui->lineEditEmail->text();
    commandClicked(searchTable);
}

void SearchDialog::on_pushButtonNext_clicked()
{
    searchTable.cmd = NEXT;
    commandClicked(searchTable);
}

void SearchDialog::on_pushButtonPrevious_clicked()
{
    searchTable.cmd = PREVIOUS;
    commandClicked(searchTable);
}

