#include "Problem.h"
#include <cassert>
using namespace std;

Problem::Problem(QString problem, std::vector<QString> answer)
    :_problem(problem), _answer(answer) {
    assert(_answer.size() == 0 || _answer.size() == 4);
}

void Problem::setProblem(const QString &problem) {
    _problem = problem;
}

QString Problem::getProblem() const {
    return _problem;
}

void Problem::setAnswer(const std::vector <QString> &answer) {
    _answer = answer;
    assert(_answer.size() == 0 || _answer.size() == 4);
}

std::vector <QString> Problem::getAnswer() const {
    return _answer;
}

