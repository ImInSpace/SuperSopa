TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    solver.cpp \
    patro.cpp

HEADERS += \
    solver.h \
    patro.h \
    wordsolver.cpp
