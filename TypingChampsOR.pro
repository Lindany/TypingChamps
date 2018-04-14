#-------------------------------------------------
#
# Project created by QtCreator 2017-04-10T20:42:47
#
#-------------------------------------------------
CONFIG += resources_big
QT       += core gui\
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TypingChampsOR
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    caurse.cpp \
    review.cpp \
    typingtest.cpp \
    games.cpp \
    statistics.cpp \
    settings.cpp \
    welcome.cpp \
    login.cpp \
    player.cpp \
    playgame.cpp \
    stage.cpp

HEADERS  += mainwindow.h \
    caurse.h \
    review.h \
    typingtest.h \
    games.h \
    statistics.h \
    settings.h \
    welcome.h \
    login.h \
    player.h \
    playgame.h \
    stage.h

FORMS    += mainwindow.ui \
    login.ui \
    multiplayer.ui \
    example.ui \
    stage.ui

DISTFILES +=

RESOURCES += \
    resource.qrc
