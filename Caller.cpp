#include "Caller.h"
#include <QDebug>
#include "Util.h"
using namespace std;


void Caller::setController(Controller *ctrl) {
    this->ctrl = ctrl;
}

void Caller::setUIState(UIState *state) {
    this->state = state;
}

void Caller::submitProblem(const QString &prob, const QString &answer0, const QString &answer1, const QString &answer2, const QString &answer3, const bool &checked) const {
    ctrl->addProblem(Problem(prob, answer0, answer1, answer2, answer3, checked));
    refresh();
}

void Caller::editProblem(const QString &prob, const QString &answer0, const QString &answer1, const QString &answer2, const QString &answer3, const bool &checked) const {
    int idx = state->getShowProbPage();
    if (idx >= 1 && idx <= (int)ctrl->getQuestionBank().size()) {
        ctrl->editProblem(idx - 1, Problem(prob, answer0, answer1, answer2, answer3, checked));
    }
    refresh();
}

void Caller::removeProblem() const {
    int idx = state->getShowProbPage();
    if (idx >= 1 && idx <= (int)ctrl->getQuestionBank().size()) {
        ctrl->removeProblem(idx - 1);
    }
    refresh();
}

QVariantList Caller::showProb() const {
    QVariantList res;
    int currentPage = state->getShowProbPage();
    int allPage = ctrl->getQuestionBank().size();
    if (currentPage < 1 || currentPage > allPage) {
        res = Problem::emptyQVL();
    } else {
        res = ctrl->getQuestionBank()[currentPage - 1].toQVL();
    }
    return res;
}

QString Caller::showProbPageNumber() const {
    int currentPage = state->getShowProbPage();
    int allPage = ctrl->getQuestionBank().size();
    if (allPage == 0) {
        state->setShowProbPage(1);
    } else if (currentPage < 1 || currentPage > allPage) {
        state->setShowProbPage(1);
    }
    return Util::toString(state->getShowProbPage()) + "/" + Util::toString(ctrl->getQuestionBank().size());
}

void Caller::showProbPrev() const {
    state->setShowProbPage(state->getShowProbPage() - 1);
    refresh();
}

void Caller::showProbNext() const {
    state->setShowProbPage(state->getShowProbPage() + 1);
    refresh();
}


void Caller::refresh() const {
    showProbRefresh();
}

void Caller::showProbRefresh() const {
    int cur = state->getShowProbPage();
    cur = min(cur, (int)ctrl->getQuestionBank().size());
    cur = max(cur, 1);
    state->setShowProbPage(cur);
}
