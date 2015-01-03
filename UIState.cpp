#include "UIState.h"
#include <QDebug>

UIState::UIState() {
    showProbPage = 1;
    genPaperStep = 1;
    genPaperPage = 1;
    genPaperName = "";
    genPaperIdx.clear();
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

