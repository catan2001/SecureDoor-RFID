#ifndef RFIDREADER_H
#define RFIDREADER_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QDebug>
#include <stdio.h>

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
};

#endif // RFIDREADER_H
