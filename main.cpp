#include <QApplication>
#include <QtQml>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <string>
#include <QObject>
#include <QString>
#include <cstdio>
#include <iostream>
#include "Message.h"
QQmlContext *context;
QQmlApplicationEngine *engine;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    ::engine = &engine;
    Message myObject;
    context = engine.rootContext();
    context->setContextProperty("MyText", "gogogo");
    context->setContextProperty("gao", &myObject);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
