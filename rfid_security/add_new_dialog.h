#ifndef ADD_NEW_DIALOG_H
#define ADD_NEW_DIALOG_H
#pragma pack(push) // corrupted-size-vs-prev-size
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

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
signals:
    void dataChanged(NewClientStruct &structure);

private:
    QPixmap pmap;
    QString dataPath;
    Ui::Add_New_Dialog *ui;
};

//#pragma pack(pop)
#endif // ADD_NEW_DIALOG_H
