#include "UIState.h"

UIState::UIState() {
    showProbPage = 1;
}

int UIState::getShowProbPage() const {
    return showProbPage;
}

void UIState::setShowProbPage(int page) {
    showProbPage = page;
}
