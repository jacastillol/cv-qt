TEMPLATE = app
TARGET = ImageEditor

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
  
INCLUDEPATH += .

DEFINES += QT_DEPRECATED_WARNINGS

# Input
SOURCES += main.cpp \
   mainwindow.cpp

HEADERS += mainwindow.h
