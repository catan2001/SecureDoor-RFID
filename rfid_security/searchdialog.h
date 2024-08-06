#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>

enum OPTIONS {SEARCH, NEXT, PREVIOUS};
typedef OPTIONS options_t;

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = nullptr);
    ~SearchDialog();

private slots:
    void on_pushButtonCancel_clicked();

private:
    Ui::SearchDialog *ui;
};

#endif // SEARCHDIALOG_H
