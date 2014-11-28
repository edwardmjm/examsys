#include "Record.h"

Record::Record(const Problem &problem, int answer):_problem(problem), _answer(answer) {
}

Problem Record::getProblem() const {
    return _problem;
}

int Record::getAnswer() const {
    return _answer;
}
