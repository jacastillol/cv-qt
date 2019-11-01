TEMPLATE = lib
  
TARGET = CartoonPlugin

COPNFIG += plugin

INCLUDEPATH += . ../ImageEditor

unix: !mac {
  INCLUDEPATH += /home/jackmaster/programs/opencv/4.1.2/include/opencv4
  LIBS += -L/home/jackmaster/programs/opencv/4.1.2/lib -lopencv_core -l opencv_imgproc
}
 
unix: mac {
#INCLUDEPATH += /path/to/opencv/include/opencv4
#LIBS += -L/path/to/opencv/lib -lopencv_world
}
 
win32 {
#INCLUDEPATH += c:/path/to/opencv/include/opencv4
#LIBS += -lc:/path/to/opencv/lib/opencv_world
}

# Input
HEADERS += cartoon_plugin.h
SOURCES += cartoon_plugin.cpp
