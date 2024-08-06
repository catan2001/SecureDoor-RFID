#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <authenticate.h>
#include <QDebug>

#define CORRECT 1
#define INCORRECT 0

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

private slots:
    void on_pushButtonConfirm_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::SettingsDialog *ui;
    bool correct = INCORRECT;
};

#endif // SETTINGSDIALOG_H
