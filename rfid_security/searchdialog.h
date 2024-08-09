#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>

enum COMMAND {SEARCH, NEXT, PREVIOUS};
typedef COMMAND command_t;

typedef struct SEARCH_T {
    unsigned int numRows = 0;
    unsigned int currentItem = 0;
    std::vector<unsigned int> foundItems;
    command_t cmd;
    QString firstName;
    QString lastName;
    QString emailAddress;
} search_t;

extern search_t searchTable;

Q_DECLARE_METATYPE(search_t)

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
    void on_pushButtonSearch_clicked();
    void on_pushButtonNext_clicked();
    void on_pushButtonPrevious_clicked();

signals:
    void commandClicked(search_t &searchTable);

private:
    Ui::SearchDialog *ui;
};

#endif // SEARCHDIALOG_H
