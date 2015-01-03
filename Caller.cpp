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
    if (currentPage > allPage) {
        res = Problem::emptyQVL();
    } else {
        res = ctrl->getQuestionBank()[currentPage - 1].toQVL();
    }
    return res;
}

QString Caller::showProbPageNumber() const {
    refresh();
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
    genPaperRefresh();
}

void Caller::showProbRefresh() const {
    int cur = state->getShowProbPage();
    cur = min(cur, (int)ctrl->getQuestionBank().size());
    cur = max(cur, 1);
    state->setShowProbPage(cur);
}

void Caller::genPaperRefresh() const {
    int cur = state->getGenPaperPage();
    cur = min(cur, (int)ctrl->getQuestionBank().size());
    cur = max(cur, 1);
    state->setGenPaperPage(cur);
}

void Caller::genPaperSetTitle() const {
    state->setGenPaperStep(1);
}

void Caller::genPaperChooseProblem(QString title) const {
    state->setGenPaperStep(2);
    state->setGenPaperName(title);
    state->genPaperIdxClear();
}

void Caller::genPaperFinish() const {
    state->setGenPaperStep(3);
    ctrl->addPaper(Paper(state->getGenPaperName(), state->getGenPaperIdx(), ctrl->getQuestionBank()));
}

void Caller::genPaperAddToPaper() const {
    if (state->getGenPaperPage() <= (int)ctrl->getQuestionBank().size()) {
        state->genPaperIdxInsert(state->getGenPaperPage());
    }
}

void Caller::genPaperNext() const {
    state->setGenPaperPage(state->getGenPaperPage() + 1);
    refresh();
}

void Caller::genPaperPrev() const {
    state->setGenPaperPage(state->getGenPaperPage() - 1);
    refresh();
}

QString Caller::genPaperPageNumber() const {
    refresh();
    return Util::toString(state->getGenPaperPage()) + "/" + Util::toString(ctrl->getQuestionBank().size());
}

int Caller::genPaperStep() const {
    return state->getGenPaperStep();
}

QVariantList Caller::genPaperProb() const {
    QVariantList res;
    refresh();
    int cur = state->getGenPaperPage();
    if (cur > (int)ctrl->getQuestionBank().size()) {
        res = Problem::emptyQVL();
    } else {
        res = ctrl->getQuestionBank()[cur - 1].toQVL();
    }
    return res;
}

QStringList Caller::comboBoxModel() const {
    return ctrl->getPaperQStringList();
}
