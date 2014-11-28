TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    Result.cpp \
    Record.cpp \
    ProblemList.cpp \
    Problem.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Result.h \
    Record.h \
    ProblemList.h \
    Problem.h \
    Message.h \
    Controller.h
