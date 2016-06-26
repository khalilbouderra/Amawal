#-------------------------------------------------
#
# Project created by QtCreator 2016-06-11T16:45:31
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Amawal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
CONFIG += static

win32:RC_ICONS += Amawal_Icon.ico
