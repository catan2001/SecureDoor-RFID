#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

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
    ui->stackedWidget->setCurrentWidget(ui->page_Clients);
    ui->tableWidget->setRowCount(1);
    //ui->tableWidget->insertRow(1);

    //ui->tableWidget->setCurrentCell(1,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void startUp() {

}

void MainWindow::dataUse(NewClientStruct &structure) {
    qDebug() << structure.firstName << "\n";
    qDebug() << structure.lastName << "\n";
    qDebug() << structure.emailAddress << "\n";
    qDebug() << structure.RFIDTag << "\n";
    qDebug() << structure.imagePath << "\n";
    qDebug() << "Connected!\n";

    auto model = ui->tableWidget->model();
    model->setData(model->index(ui->tableWidget->rowCount()-1, 0), structure.firstName);
    model->setData(model->index(ui->tableWidget->rowCount()-1, 1), structure.lastName);
    model->setData(model->index(ui->tableWidget->rowCount()-1, 2), structure.emailAddress);
    model->setData(model->index(ui->tableWidget->rowCount()-1, 3), structure.RFIDTag);
    model->setData(model->index(ui->tableWidget->rowCount()-1, 4), structure.imagePath);
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);

}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if(item == ui->listWidget->item(0))
        ui->stackedWidget->setCurrentWidget(ui->page_Clients);
    if(item == ui->listWidget->item(1))
        ui->stackedWidget->setCurrentWidget(ui->page_Monitor);
}


void MainWindow::on_pushButton_4_clicked()
{
    NewClientDialog = new Add_New_Dialog(this);
    NewClientDialog->setStyleSheet("QDialog {border: 2px solid #111111; "
                                   "background: no;"
                                   "background-color : #222222; "
                                   "padding: 2px }");
    NewClientDialog->show();
    // connect NewClientDialog with MainWindow to get data
    QObject::connect(NewClientDialog, SIGNAL(dataChanged(NewClientStruct &)),
                     this, SLOT(dataUse(NewClientStruct &)));
}

