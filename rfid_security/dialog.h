#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPixmap>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_acceptLoginPushButton_clicked();

    void on_cancelLoginPushButton_clicked();

private:
    Ui::Dialog *ui;
    MainWindow *mainWin;
};
#endif // DIALOG_H
