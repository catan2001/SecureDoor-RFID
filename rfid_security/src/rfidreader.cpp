#include <include/rfidreader.h>

RFIDReader::RFIDReader() : QObject()
{

}

RFIDReader::~RFIDReader() {
    //delete this;
}

void RFIDReader::readingProcess(void) {
    QString rfidtag;

    while(true) {
        long int rnd = random();
        qDebug() << rnd;
        rfidtag = "3afdc96b35e60a6c3d98fc06ca8647ad5a106c862503cb64f982d260928c7286";
        sendRFIDtag(rfidtag);
        emit finished();
        QThread::usleep(1000000);
    }
}
