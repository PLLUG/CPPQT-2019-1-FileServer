TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++17
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    configurable.h \
    filewebserver.h \
    datamodel.h \
    filesystemmodel.h \
    dataview.h \
    generator.h \
    htmlcontentgenerator.h
