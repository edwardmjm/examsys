#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include "Problem.h"
#include "ProblemList.h"
#include "Record.h"
#include "Result.h"

class Controller {
public:
    //修改题库
    void addProblem(const Problem &p);

    void editProblem(int index, const Problem &p);

    void removeProblem(int index);
    //修改试卷
    void addPaper(const ProblemList &l);

    void editPaper(int index, const ProblemList &l);

    void removePaper(int index);
    //修改答卷
    void addResult(const Result &res);

    void editResult(int index, const Result &res);

    void removeResult(int index);

    std::vector <Problem> &getQuestionBank();

    std::vector <ProblemList> &getPaper();

    std::vector <Result> &getResult();

    void save();

    void load();

private:
    std::vector <Problem> questionBank; //题库
    std::vector <ProblemList> paper;    //试卷库
    std::vector <Result> result;        //答卷库
};

#endif // CONTROLLER_H
