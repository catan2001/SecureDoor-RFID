#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setStyleSheet("QListWidget"
                                  "{background-color : #1a1a1a;" // darker gray-black
                                  "color: #eeeeee;}"); // white
    ui->statusbar->setStyleSheet("QStatusBar"
                                 "{color: #eeeeee}"); // white
    ui->statusbar->showMessage("Welcome! SecureDoor greets you!");
    ui->stackedWidget->setCurrentWidget(ui->page_AddNew);

    ui->tableWidget->insertRow(2);
    ui->tableWidget->setRowCount(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void startUp() {

}



void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if(item == ui->listWidget->item(0)) // TODO: define for each list
        ui->stackedWidget->setCurrentWidget(ui->page_AddNew);
    if(item == ui->listWidget->item(1))
        ui->stackedWidget->setCurrentWidget(ui->page_Clients);
    if(item == ui->listWidget->item(2))
        ui->stackedWidget->setCurrentWidget(ui->page_Monitor);
    if(item == ui->listWidget->item(3))
        ui->stackedWidget->setCurrentWidget(ui->page_Settings);
}

