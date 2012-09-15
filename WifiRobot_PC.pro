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

DEFINES += _WIN32_WINNT=0x0501
DEFINES += WINVER=0x0501

win32:INCLUDEPATH += $$(BOOST_ROOT) $$(VLC_SDK)/include

unix:LIBS += -L/usr/lib -lboost_system -lpthread -lvlc -g
win32:LIBS += -L$$(BOOST_ROOT)/stage/lib $$(VLC_SDK)/lib/libvlc.lib
