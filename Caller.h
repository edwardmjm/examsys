#ifndef CALLER_H
#define CALLER_H
#include <cstdio>
#include <iostream>
#include <QApplication>
#include <QtQml>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QObject>
#include <QDebug>
#include <QString>
#include "Controller.h"
#include "UIState.h"
#include "Paper.h"

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

    Q_INVOKABLE void genPaperSetTitle() const ;
    Q_INVOKABLE void genPaperChooseProblem(QString) const ;
    Q_INVOKABLE void genPaperFinish() const ;
    Q_INVOKABLE void genPaperAddToPaper() const ;
    Q_INVOKABLE void genPaperNext() const ;
    Q_INVOKABLE void genPaperPrev() const ;
    Q_INVOKABLE QString genPaperPageNumber() const ;
    Q_INVOKABLE int genPaperStep() const ;
    Q_INVOKABLE QVariantList genPaperProb() const ;

    Q_INVOKABLE QStringList comboBoxModel() const ;

    Q_INVOKABLE void save() const ;
    Q_INVOKABLE void load() const ;

private:
    void refresh() const ;
    void showProbRefresh() const ;
    void genPaperRefresh() const ;

    Controller *ctrl;
    UIState *state;
};

#endif // CALLER_H
