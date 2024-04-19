QT       += core gui openglwidgets opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    coordgrid.cpp \
    griddot.cpp \
    main.cpp \
    mainwindow.cpp \
    mapcoords.cpp \
    myglwidget.cpp \
    node.cpp

HEADERS += \
    coordgrid.h \
    griddot.h \
    mainwindow.h \
    mapcoords.h \
    myglwidget.h \
    node.h \
    stb_image.h \
    stb_image_resize2.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    textures.qrc

LIBS += -lopengl32

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
