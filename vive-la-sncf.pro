TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    utile.cpp \
    entity.cpp \
    property.cpp \
    entry.cpp \
    value.cpp \
    bdd.cpp

HEADERS += \
    utile.h \
    entity.h \
    property.h \
    entry.h \
    value.h \
    bdd.h
