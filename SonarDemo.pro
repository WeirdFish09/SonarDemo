#-------------------------------------------------
#
# Project created by QtCreator 2019-10-18T08:29:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SonarDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    renderer.cpp \
    renderingarea.cpp \
    fixeddatasource.cpp

HEADERS  += mainwindow.h \
    renderer.h \
    renderingarea.h \
    datasourceinteface.h \
    fixeddatasource.h

FORMS    += mainwindow.ui
QMAKE_CXXFLAGS = -std=c++11
