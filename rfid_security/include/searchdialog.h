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
