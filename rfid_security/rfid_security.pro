QT       += core gui
INCLUDEPATH += /usr/local/include
LIBS += -L"/usr/local/lib"
LIBS += -IMFRC522.h
LIBS += -IMFRC522libname
LIBS += -lbcm2835

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/MFRC522.cpp \
    src/add_new_dialog.cpp \
    src/authenticate.cpp \
    src/dialog.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/rfidreader.cpp \
    src/searchdialog.cpp \
    src/settingsdialog.cpp \
    src/sha256.cpp

HEADERS += \
    include/MFRC522.h \
    include/add_new_dialog.h \
    include/authenticate.h \
    include/bcm2835.h \
    include/dialog.h \
    include/mainwindow.h \
    include/rfidreader.h \
    include/searchdialog.h \
    include/settingsdialog.h \
    include/sha256.h

FORMS += \
    forms/add_new_dialog.ui \
    forms/dialog.ui \
    forms/mainwindow.ui \
    forms/searchdialog.ui \
    forms/settingsdialog.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
