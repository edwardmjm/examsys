TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    Result.cpp \
    Record.cpp \
    Problem.cpp \
    Controller.cpp \
    Interacter.cpp \
    Caller.cpp \
    UIState.cpp \
    Util.cpp \
    Paper.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Result.h \
    Record.h \
    Problem.h \
    Controller.h \
    Interacter.h \
    Caller.h \
    UIState.h \
    Util.h \
    Paper.h
