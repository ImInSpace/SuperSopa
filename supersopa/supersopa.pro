TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    solver.cpp \
    patro.cpp \
    wordsolver_allappearances.cpp \
    wordsolver.cpp

HEADERS += \
    solver.h \
    patro.h \
    wordsolver_allappearances.h \
    wordsolver.h

QMAKE_CXXFLAGS += -std=c++11
