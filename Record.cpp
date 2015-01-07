#include "Record.h"
using namespace std;
Record::Record():_problem(Problem("", vector<QString> ())), _answer(-1) {

}

Record::Record(const Problem &problem, int answer):_problem(problem), _answer(answer) {
}

Problem Record::getProblem() const {
    return _problem;
}

int Record::getAnswer() const {
    return _answer;
}

QDataStream & operator << (QDataStream &stream, const Record &r) {
    stream << r._answer << r._problem;
    return stream;
}

QDataStream & operator >> (QDataStream &stream, Record &r) {
    stream >> r._answer >> r._problem;
    return stream;
}
