#ifndef UISTATE_H
#define UISTATE_H

#include <set>
#include <map>
#include <QString>
#include "Record.h"

class UIState {
public:
    UIState();

    int getShowProbPage() const;
    void setShowProbPage(int);

    int getExamProbPage() const;
    void setExamProbPage(int);

    int getGenPaperStep() const ;
    void setGenPaperStep(int);

    int getGenPaperPage() const ;
    void setGenPaperPage(int);


    QString getGenPaperName() const ;
    void setGenPaperName(QString);

    int getExamPaperId() const ;
    void setExamPaperId(int);

    int getCheckPage() const ;
    void setCheckPage(int);

    int getCheckId() const ;
    void setCheckId(int);

    QString getStudentId() const ;
    void setStudentId(QString);

    void genPaperIdxClear();
    void genPaperIdxInsert(int);
    std::set <int> getGenPaperIdx();

    std::map <int, Record> &getRecord();


private:
    int showProbPage;
    int genPaperStep;
    int genPaperPage;
    int examPaperId;
    int examProbPage;
    int checkPage;
    int checkId;
    QString studentId;
    QString genPaperName;
    std::set <int> genPaperIdx;
    std::map <int, Record> recMp;
};

#endif // UISTATE_H
