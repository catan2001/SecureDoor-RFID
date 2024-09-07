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

#ifndef ADD_NEW_DIALOG_H
#define ADD_NEW_DIALOG_H
#pragma pack(push) // corrupted-size-vs-prev-size
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include "rfidreader.h"

typedef struct{
    QString firstName;
    QString lastName;
    QString emailAddress;
    QString RFIDTag;
    QString imagePath;
}NewClientStruct;

Q_DECLARE_METATYPE(NewClientStruct)

namespace Ui {
class Add_New_Dialog;
}

class Add_New_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Add_New_Dialog(QWidget *parent = nullptr);
    ~Add_New_Dialog();

private slots:
    void on_PushButton_LoadNewImage_clicked();
    void on_LineEdit_Path_textEdited(const QString &arg1);
    void on_PushButton_ScanTag_clicked();
    void on_PushButton_Cancel_clicked();
    void on_ToolButtonInfoNewClient_clicked();
    void on_PushButton_Save_clicked();
    void readRFIDtag(QString);
signals:
    void dataChanged(NewClientStruct &structure);

private:
    QString rfidTag;
    QPixmap pmap;
    QString dataPath;
    Ui::Add_New_Dialog *ui;
};

#endif // ADD_NEW_DIALOG_H
