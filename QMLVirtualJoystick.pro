#-------------------------------------------------
#
# Project created by QtCreator 2014-03-03T21:55:22
#
#-------------------------------------------------

QT += core gui quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QMLVirtualJoystick
TEMPLATE = app


SOURCES += main.cpp mainwindow.cpp

HEADERS += mainwindow.h

FORMS += mainwindow.ui

OTHER_FILES += \
    finger.png \
    background.png \
    virtual_joystick.qml

RESOURCES += \
    resources.qrc
