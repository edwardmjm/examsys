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
    examRefresh();
    checkRefresh();
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

void Caller::examRefresh() const {
    int cur = state->getExamProbPage();
    int all = (int)ctrl->getPaper().size() > state->getExamPaperId() ? ctrl->getPaper()[state->getExamPaperId()].getProb().size() : 0;
    cur = min(cur, all);
    cur = max(cur, 1);
    state->setExamProbPage(cur);
}

void Caller::checkRefresh() const {
    int cur = state->getCheckPage();
    std::vector <Result> &res = ctrl->getResult();
    int all = (int)res.size() > state->getCheckId() ? res[state->getCheckId()].size() : 0;
    cur = min(cur, all);
    cur = max(cur, 1);
    state->setCheckPage(cur);
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


void Caller::save() const {
    ctrl->save();
}

void Caller::load() const {
    ctrl->load();
}

void Caller::enterExamMode(QString studentId, int paperId) const {
    state->setStudentId(studentId);
    state->setExamPaperId(paperId);
    state->getRecord().clear();
}


QVariantList Caller::examProb() const {
    refresh();
    QVariantList res;
    int currentPage = state->getExamProbPage();
    int allPage = (int)ctrl->getPaper().size() > state->getExamPaperId() ? ctrl->getPaper()[state->getExamPaperId()].getProb().size() : 0;
    if (currentPage > allPage) {
        res = Problem::emptyQVL();
    } else {
        res = ctrl->getPaper()[state->getExamPaperId()].getProb()[currentPage - 1].toQVL();
    }
    return res;
}

QString Caller::examProbPageNumber() const {
    refresh();
    int currentPage = state->getExamProbPage();
    int allPage = (int)ctrl->getPaper().size() > state->getExamPaperId() ? ctrl->getPaper()[state->getExamPaperId()].getProb().size() : 0;
    return Util::toString(currentPage) + "/" + Util::toString(allPage);
}

void Caller::examProbNext() const {
    state->setExamProbPage(state->getExamProbPage() + 1);
    refresh();
}

void Caller::examProbPrev() const {
    state->setExamProbPage(state->getExamProbPage() - 1);
    refresh();
}

void Caller::examAddRecord(QString answer) {
    int v = Util::toInt(answer);
    if (0 <= v && v < 4) {
        Problem &pr = ctrl->getPaper()[state->getExamPaperId()].getProb()[state->getExamProbPage() - 1];
        state->getRecord()[state->getExamProbPage()] = Record(pr, v);
    }
}

void Caller::submitSolution() {
    ctrl->addResult(Result(state->getRecord(), ctrl->getPaper()[state->getExamPaperId()], state->getStudentId()));
}

QVariantList Caller::checkProb() const {
    QVariantList ret;
    int cur = state->getCheckPage();
    std::vector <Result> &res = ctrl->getResult();
    int all = (int)res.size() > state->getCheckId() ? res[state->getCheckId()].size() : 0;
    if (cur > all) {
        ret = Problem::emptyQVL();
        ret.append(QString(""));
    } else {
        ret = res[state->getCheckId()].toQVL(state->getCheckPage() - 1);
    }
    return ret;
}

QString Caller::checkProbPageNumber() const {
    refresh();
    int cur = state->getCheckPage();
    std::vector <Result> &res = ctrl->getResult();
    int all = (int)res.size() > state->getCheckId() ? res[state->getCheckId()].size() : 0;
    return Util::toString(cur) + "/" + Util::toString(all);
}

void Caller::setCheckId(int idx) const {
    state->setCheckId(idx);
}

void Caller::checkProbPrev() const {
    state->setCheckPage(state->getCheckPage() - 1);
    refresh();
}

void Caller::checkProbNext() const {
    state->setCheckPage(state->getCheckPage() + 1);
    refresh();
}

QStringList Caller::resultComboBoxModel() const {
    QStringList ret;
    for (Result &u : ctrl->getResult()) {
        ret.append(QString(u.getStudentId() + " - " + u.getPaperTitle()));
    }
    return ret;
}
