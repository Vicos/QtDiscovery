# QtDiscovery project

QT += core
QT += gui
QT += network
QT += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtDiscovery

TEMPLATE = app

SOURCES += mainwindow.cpp \
           main.cpp \
           devicelistmodel.cpp \
           devicelist.cpp \
           device.cpp \
    devicemanager.cpp \
    udplistener.cpp \
    devicecontroller.cpp \
    xmldiscoverymessage.cpp \
    xmlsoapmessage.cpp \
    xmladdressingheader.cpp

HEADERS += mainwindow.h \
           devicelistmodel.h \
           devicelist.h \
           device.h \
    devicemanager.h \
    udplistener.h \
    devicecontroller.h \
    xmldiscoverymessage.h \
    xmlsoapmessage.h \
    xmladdressingheader.h

FORMS   += mainwindow.ui

RESOURCES += \
    schema.qrc
