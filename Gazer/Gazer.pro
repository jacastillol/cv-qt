TEMPLATE = app

TARGET = Gazer

INCLUDEPATH += .

QT += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += QT_DEPRECATED_WARNINGS

unix: !mac {
INCLUDEPATH += /home/jackmaster/programs/opencv/4.1.2/include/opencv4
LIBS += -L/home/jackmaster/programs/opencv/4.1.2/lib -lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_video -lopencv_videoio
}
 
unix: mac {
# INCLUDEPATH += /path/to/opencv/include/opencv4
# LIBS += -L/path/to/opencv/lib -lopencv_world
}
 
win32 {
# INCLUDEPATH += c:/path/to/opencv/include/opencv4
# LIBS += -lc:/path/to/opencv/lib/opencv_world
}

# Input
SOURCES += main.cpp \
  mainwindow.cpp \
  capture_thread.cpp

HEADERS += mainwindow.h \
  capture_thread.h
