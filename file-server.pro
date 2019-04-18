TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++17
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        configuration.cpp \
        main.cpp

HEADERS += \
    configurable.h \
    configuration.h \
    filewebserver.h \
    datamodel.h \
    filesystemmodel.h \
    dataview.h \
    fsizeenum.h \
    generator.h \
    htmlcontentgenerator.h
