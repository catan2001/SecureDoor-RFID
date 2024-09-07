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
        }
        sendRFIDtag(rfidtag);
        emit finished();
    }
}

void RFIDReader::delay(int ms){
    QThread::usleep(ms*1000);
}
