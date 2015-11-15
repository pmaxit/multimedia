#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T14:03:20
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Opengl3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myglwidget.cpp \
    mystream.cpp

HEADERS  += mainwindow.h \
    myglwidget.h \
    mystream.h

FORMS    += mainwindow.ui

DISTFILES += \
    simple_fragment_shader.fsh \
    simple_vertex_shader.vsh \
    ../../../../Downloads/opengl_rt0.png

RESOURCES += \
    opengl.qrc
