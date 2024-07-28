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
                                  "color: #C0C0C0;}" // white

                                  "QListWidget::item"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:hover"
                                  "{background-color: #152238;"
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:selected"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0}");

    ui->listWidgetSideBar2->setStyleSheet("QListWidget"
                                  "{background-color : #1a1a1a;" // darker gray-black
                                  "color: #C0C0C0;}" // white

                                  "QListWidget::item"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:hover"
                                  "{background-color: #152238;"
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:selected"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0}");

    ui->listWidgetOptions1->setStyleSheet("QListWidget"
                                  "{background-color : transparent;" //
                                  "color: #C0C0C0;}" // white

                                  "QListWidget::item"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:hover"
                                  "{background-color: #152238;"
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:selected"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0}");

    ui->listWidgetHistory->setStyleSheet("QListWidget"
                                  "{background-color : #444444;" // darker gray-black
                                  "color: #C0C0C0;"
                                  "border: 3px solid #1a1a1a;}" // dark gray/blue

                                  "QListWidget::item"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:hover"
                                  "{background-color: #152238;"
                                  "color: #C0C0C0;}"

                                  "QListWidget::item:selected"
                                  "{background-color: transparent;"
                                  "color: #C0C0C0}");

    ui->statusbar->setStyleSheet("QStatusBar"
                                 "{color: #eeeeee}"); // white

    ui->tableWidget->setStyleSheet("QTableWidget"
                                   "{background-color : #444444;"
                                   "border: 1px solid #1a1a1a;"
                                   "gridline-color: #1a1a1a;"
                                   "color: #eeeeee;"
                                   "outline : 0;}"

                                   "QTableView::disabled"
                                   "{background-color: #242526;"
                                   "border: 1px solid #32414B;"
                                   "color: #656565;"
                                   "gridline-color: #656565;"
                                   "outline : 0;}"

                                   "QTableView::item:hover"
                                   "{background-color: #C0C0C0;" //233040
                                   "color: #eeeeee;}"

                                   "QTableView::item:selected"
                                   "{background-color: #404040;"
                                   "border: 2px solid #808080;"
                                   "color: #eeeeee;}"

                                   "QLineEdit"
                                   "{background-color: #404040;"
                                   "border: 2px solid #808080;"
                                   "color: #eeeeee;}"

                                   "QTableView::item:selected:disabled"
                                   "{background-color: #1a1b1c;"
                                   "border: 2px solid #525251;"
                                   "color: #656565;}");

    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section"
                                   "{background-color: #242526;"
                                   "color: #eeeeee;"
                                   "padding: 4px;}"

                                    "QHeaderView::section:hover"
                                    "{background-color: #4969ff;"
                                    "color: #eeeeee;}"

                                   "QHeaderView::section:selected"
                                   "{background-color: #eeeeee;"
                                   "color: #656565;}"

                                   "QHeaderView::section:checked"
                                   "{color: #fff;"
                                   "background-color: #4969ff;}");

    ui->labelSettings->setStyleSheet("QLabel{color: #eeeeee;}");

    ui->pushButtonLoad->setStyleSheet("QPushButton"
                                     "{border : 2px solid #111111;"
                                     "background-color : #3f3f3f;"
                                     "padding: 6px;"
                                     "min-width: 4em;"
                                     "color: #A9A9A9;}"
                                     "QPushButton:pressed"
                                     "{background-color: #7393B3;"
                                     "color: #eeeeee;}");

    ui->pushButtonSaveData->setStyleSheet("QPushButton"
                                     "{border : 2px solid #111111;"
                                     "background-color : #3f3f3f;"
                                     "padding: 6px;"
                                     "min-width: 4em;"
                                     "color: #A9A9A9;}"
                                     "QPushButton:pressed"
                                     "{background-color: #7393B3;"
                                     "color: #eeeeee;}");

    QIcon icon;
    QPixmap pixmap;
    pixmap.load("../icons/ClientsOff.png"); // when not selected
    icon.addPixmap(pixmap, QIcon::Normal);
    pixmap.load("../icons/ClientsOn.png"); // when selected
    icon.addPixmap(pixmap, QIcon::Selected);
    if(!icon.isNull()){
        ui->listWidget->item(0)->setIcon(icon);
    }

    pixmap.load("../icons/MonitorOff.png"); // when not selected
    icon.addPixmap(pixmap, QIcon::Normal);
    pixmap.load("../icons/MonitorOn.png"); // when selected
    icon.addPixmap(pixmap, QIcon::Selected);
    if(!icon.isNull()){
        ui->listWidget->item(1)->setIcon(icon);
    }

    icon = QIcon("../icons/AddIconOff.png");
    if(!icon.isNull()){
        ui->listWidgetSideBar2->item(0)->setIcon(icon);
    }

    icon = QIcon("../icons/SearchIconOff.png");
    if(!icon.isNull()){
        ui->listWidgetSideBar2->item(1)->setIcon(icon);
    }

    icon = QIcon("../icons/SettingsIconOff.png");
    if(!icon.isNull()){
        ui->listWidgetSideBar2->item(2)->setIcon(icon);
    }

    icon = QIcon("../icons/AddClientOff.png");
    if(!icon.isNull()){
        ui->listWidgetOptions1->item(0)->setIcon(icon);
    }

    icon = QIcon("../icons/GarbageOff.png");
    if(!icon.isNull()){
        ui->listWidgetOptions1->item(1)->setIcon(icon);
    }

    icon = QIcon("../icons/RFIDOff.png");
    if(!icon.isNull()){
        ui->listWidgetOptions1->item(2)->setIcon(icon);
    }

    icon = QIcon("../icons/ShowHideOff.png");
    if(!icon.isNull()){
        ui->listWidgetOptions1->item(3)->setIcon(icon);
    }

    ui->statusbar->showMessage("Welcome! SecureDoor greets you!");
    ui->stackedWidget->setCurrentWidget(ui->page_Clients);
    ui->listWidget->setCurrentRow(0);
    ui->tableWidget->setRowCount(1);
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

void MainWindow::on_listWidgetOptions1_itemClicked(QListWidgetItem *item)
{
    if(item == ui->listWidgetOptions1->item(0)) {
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
    if(item == ui->listWidgetOptions1->item(1)) {}
        // REMOVE ROW FROM TABLE
    if(item == ui->listWidgetOptions1->item(2)) {}
        //TODO: SCAN RFID
}


void MainWindow::on_pushButtonLoad_clicked()
{
    QString DBdataPath = QFileDialog::getOpenFileName(this, "Open DataBase", "../");
}

