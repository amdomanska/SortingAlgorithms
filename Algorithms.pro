TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    algorithm.h \
    sorting.h

QMAKE_CXXFLAGS += -std=c++0x -pthread
LIBS += -pthread

