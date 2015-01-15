#include "UIState.h"
#include <QDebug>
using namespace std;

UIState::UIState() {
    showProbPage = 1;
    genPaperStep = 1;
    genPaperPage = 1;
    genPaperName = "";
    genPaperIdx.clear();
    checkPage = 1;
    checkId = 0;
    examPaperId = 0;
    examProbPage = 1;
    studentId = "";
    recMp.clear();
}

int UIState::getShowProbPage() const {
    return showProbPage;
}

void UIState::setShowProbPage(int page) {
    showProbPage = page;
}

int UIState::getGenPaperStep() const {
    return genPaperStep;
}

void UIState::setGenPaperStep(int step) {
    genPaperStep = step;
}

int UIState::getGenPaperPage() const {
    return genPaperPage;
}

void UIState::setGenPaperPage(int page) {
    genPaperPage = page;
}


QString UIState::getGenPaperName() const {
    return genPaperName;
}

void UIState::setGenPaperName(QString name) {
    genPaperName = name;
}


void UIState::genPaperIdxClear() {
    genPaperIdx.clear();
}

void UIState::genPaperIdxInsert(int idx) {
    qDebug() << idx;
    genPaperIdx.insert(idx);
    qDebug() << "idx size = " << genPaperIdx.size();
}

std::set <int> UIState::getGenPaperIdx() {
    return genPaperIdx;
}

int UIState::getExamPaperId() const {
    return examPaperId;
}

void UIState::setExamPaperId(int id) {
    examPaperId = id;
}

QString UIState::getStudentId() const {
    return studentId;
}

void UIState::setStudentId(QString id) {
    studentId = id;
}

int UIState::getExamProbPage() const {
    return examProbPage;
}

void UIState::setExamProbPage(int page) {
    examProbPage = page;
}

map <int, Record> &UIState::getRecord() {
    return recMp;
}

int UIState::getCheckPage() const {
    return checkPage;
}

void UIState::setCheckPage(int p) {
    checkPage = p;
}

int UIState::getCheckId() const {
    return checkId;
}

void UIState::setCheckId(int id) {
    checkId = id;
}

