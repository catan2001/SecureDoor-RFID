#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setStyleSheet("QListWidget"
                                  "{background-color : #111111;"
                                  "color: #eeeeee;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void startUp() {

}
