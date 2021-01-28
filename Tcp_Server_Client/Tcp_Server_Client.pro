QT       += core gui network core5compat
QT += concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    displayform.cpp \
    ipinfodialog.cpp \
    main.cpp \
    mainwindow.cpp \
    tcpserver.cpp \
    tcpsocket.cpp \
    threadhandle.cpp

HEADERS += \
    Parameter.h \
    displayform.h \
    ipinfodialog.h \
    mainwindow.h \
    tcpserver.h \
    tcpsocket.h \
    threadhandle.h

FORMS += \
    displayform.ui \
    ipinfodialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
