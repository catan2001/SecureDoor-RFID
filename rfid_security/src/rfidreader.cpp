#include <include/rfidreader.h>

RFIDReader::RFIDReader() : QObject()
{

}

RFIDReader::~RFIDReader() {
    //delete this;
}

void RFIDReader::readingProcess(void) {
    QString rfidtag;

    mfrc.PCD_Init();
    while(true) {
        delay(500);

        if(!mfrc.PICC_IsNewCardPresent())
            continue;
        if(!mfrc.PICC_ReadCardSerial())
            continue;
        rfidtag.clear();
        for(int i = 0; i < mfrc.uid.size; ++i) {
            rfidtag = rfidtag + QString::number(mfrc.uid.uidByte[i]);
            //printf("%X", mfrc.uid.uidByte[i]);
            //if(mfrc.uid.uidByte[i] < 0x10) {
                //printf(" 0");
                //printf("%X", mfrc.uid.uidByte[i]);
            //}
            //else {
                //printf(" ");
                //printf("%X", mfrc.uid.uidByte[i]);
            //}
        }
        //printf("\n");

        //rfidtag = "3afdc96b35e60a6c3d98fc06ca8647ad5a106c862503cb64f982d260928c7286";
        //printf("tester\n");
        //qDebug() << "help";
        sendRFIDtag(rfidtag);
        emit finished();
    }
}

void RFIDReader::delay(int ms){
    QThread::usleep(ms*1000);
}
