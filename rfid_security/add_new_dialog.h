#ifndef ADD_NEW_DIALOG_H
#define ADD_NEW_DIALOG_H
#pragma pack(push) // corrupted-size-vs-prev-size
#include <QDialog>
#include <QFileDialog>

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

private:
    QPixmap pmap;
    QString dataPath;
    Ui::Add_New_Dialog *ui;
};

//#pragma pack(pop)
#endif // ADD_NEW_DIALOG_H
