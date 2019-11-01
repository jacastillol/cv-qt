TEMPLATE = app
TARGET = ImageEditor

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
  
INCLUDEPATH += .

DEFINES += QT_DEPRECATED_WARNINGS

# Input
SOURCES += main.cpp \
   mainwindow.cpp

HEADERS += mainwindow.h \
   editor_plugin_interface.h

unix: !mac {
  INCLUDEPATH += /home/jackmaster/programs/opencv/4.1.2/include/opencv4
  LIBS += -L/home/jackmaster/programs/opencv/4.1.2/lib -lopencv_core -l opencv_imgproc
}

unix: mac {
# INCLUDEPATH += /path/to/opencv/include/opencv4
# LIBS += -L/path/to/opencv/lib -lopencv_world
}

win32 {
# INCLUDEPATH += c:/path/to/opencv/include/opencv4
# LIBS += -lc:/path/to/opencv/lib/opencv_world
}
