#ifndef UISTATE_H
#define UISTATE_H

#include <set>
#include <QString>

class UIState {
public:
    UIState();

    int getShowProbPage() const;
    void setShowProbPage(int);

    int getGenPaperStep() const ;
    void setGenPaperStep(int);

    int getGenPaperPage() const ;
    void setGenPaperPage(int);


    QString getGenPaperName() const ;
    void setGenPaperName(QString);


    void genPaperIdxClear();
    void genPaperIdxInsert(int);
    std::set <int> getGenPaperIdx();


private:
    int showProbPage;
    int genPaperStep;
    int genPaperPage;
    QString genPaperName;
    std::set <int> genPaperIdx;
};

#endif // UISTATE_H
