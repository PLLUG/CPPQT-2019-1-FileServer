TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++17
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        configuration.cpp \
        dataview.cpp \
        filesystemmodel.cpp \
        filewebserver.cpp \
        httpconnection.cpp \
        main.cpp

HEADERS += \
    configurable.h \
    configuration.h \
    configurationreader.h \
    filewebserver.h \
    datamodel.h \
    filesystemmodel.h \
    dataview.h \
    fsizeenum.h \
    generator.h \
    htmlcontentgenerator.h \
    httpconnection.h


LIBS += -L/mingw64/lib/ -lwsock32 -lws2_32
INCLUDEPATH += /mingw64/include/
CONFIG(debug, debug|release) {
LIBS += \
    -lboost_system-mt \
    -lboost_program_options-mt \
}
CONFIG(release, debug|release) {
    DEFINES += NDEBUG
}
