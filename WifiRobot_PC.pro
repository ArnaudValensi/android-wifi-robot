#-------------------------------------------------
#
# Project created by QtCreator 2011-04-29T16:21:40
#
#-------------------------------------------------

QT       += core gui

TARGET = WifiRobot_PC
TEMPLATE = app


SOURCES += main.cpp\
        Gui.cpp \
    Socketudp.cpp \
    Video.cpp

HEADERS  += Gui.h \
    Socketudp.h \
    Video.h

FORMS    += Gui.ui

unix:LIBS += -L/usr/lib -lboost_system -lpthread -lvlc -g
