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

