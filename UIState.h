#ifndef UISTATE_H
#define UISTATE_H

class UIState {
public:
    UIState();

    int getShowProbPage() const;
    void setShowProbPage(int);

private:
    int showProbPage;
};

#endif // UISTATE_H
