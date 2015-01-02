#include "Controller.h"
#include <QDebug>
using namespace std;

//修改题库
void Controller::addProblem(const Problem &p) {
    qDebug() << p.getProblem() << "\n";
    questionBank.push_back(p);
}

void Controller::editProblem(int index, const Problem &p) {
    questionBank[index] = p;
}

void Controller::removeProblem(int index) {
    questionBank.erase(questionBank.begin() + index);
}

//修改试卷
void Controller::addPaper(const ProblemList &l) {
    paper.push_back(l);
}

void Controller::editPaper(int index, const ProblemList &l) {
    paper[index] = l;
}

void Controller::removePaper(int index) {
    paper.erase(paper.begin() + index);
}

//修改答卷
void Controller::addResult(const Result &res) {
    result.push_back(res);
}

void Controller::editResult(int index, const Result &res) {
    result[index] = res;
}

void Controller::removeResult(int index) {
    result.erase(result.begin() + index);
}

std::vector <Problem> & Controller::getQuestionBank() {
    return questionBank;
}

std::vector <ProblemList> & Controller::getPaper() {
    return paper;
}

std::vector <Result> & Controller::getResult() {
    return result;
}
