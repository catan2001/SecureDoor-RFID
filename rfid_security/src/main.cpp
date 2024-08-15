#include "include/dialog.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog w;
    //w.setFocus();
    w.setWindowState(Qt::WindowMaximized);
    //w.setAttribute(Qt::WA_DeleteOnClose, true);
    w.setStyleSheet("QDialog {border: 2px solid #111111; "
                   // "color : blue; "
                    "background: url(../logo.png);"
                    "background-repeat: no-repeat;"
                    "background-position: center;"
                    "background-color : #222222; "
                    "padding: 2px }");

    w.show();
    return a.exec();
}
