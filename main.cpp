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
#include "Interacter.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    Interacter inter(engine.rootContext());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
