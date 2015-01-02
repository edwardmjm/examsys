#ifndef CALLER_H
#define CALLER_H
#include <cstdio>
#include <iostream>
#include <QApplication>
#include <QtQml>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <string>
#include <QObject>
#include <QDebug>
#include <QString>
#include "Controller.h"
#include "UIState.h"

class Caller : public QObject {
    Q_OBJECT
public:

    void setController(Controller *ctrl);
    void setUIState(UIState *state);

    Q_INVOKABLE void submitProblem(const QString &prob, const QString &answer0, const QString &answer1, const QString &answer2, const QString &answer3, const bool &checked) const ;
    Q_INVOKABLE void editProblem(const QString &prob, const QString &answer0, const QString &answer1, const QString &answer2, const QString &answer3, const bool &checked) const;
    Q_INVOKABLE void removeProblem() const ;
    Q_INVOKABLE QVariantList showProb() const ;
    Q_INVOKABLE QString showProbPageNumber() const ;
    Q_INVOKABLE void showProbNext() const ;
    Q_INVOKABLE void showProbPrev() const ;

private:
    void refresh() const ;
    void showProbRefresh() const ;

    Controller *ctrl;
    UIState *state;
};

#endif // CALLER_H
