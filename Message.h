#ifndef MESSAGE_H
#define MESSAGE_H
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
extern QQmlContext *context;
extern QQmlApplicationEngine *engine;

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author READ author WRITE setAuthor)
public:
    void setAuthor(const QString &a) {
        if (a != m_author) {
            m_author = a;
            emit authorChanged();
        }
    }
    Q_INVOKABLE void gao() {
        engine->load(QUrl(QStringLiteral("qrc:/main2.qml")));
        std::cout << "Enter gao" << std::endl;
    }

    QString author() const {
        return m_author;
    }
signals:
    void authorChanged();
private:
    QString m_author;
};

#endif // MESSAGE_H
