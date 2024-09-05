#ifndef RFIDREADER_H
#define RFIDREADER_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QDebug>
#include <stdio.h>

//INCLUDE FILES FOR RFID
#include <unistd.h>
#include "MFRC522.h"


class RFIDReader : public QObject {
    Q_OBJECT
public:
    RFIDReader();
    ~RFIDReader();
public slots:
    void readingProcess(void);
signals:
    void finished(void);
    void error(QString err);
    void sendRFIDtag(QString rfidtag);
private:
    MFRC522 mfrc;
    void delay(int ms);

};

#endif // RFIDREADER_H
