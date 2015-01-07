#include "Result.h"
#include <QVector>
using namespace std;

Result::Result():_res(vector <Record> ()), _score(-1) {
}

Result::Result(const std::vector <Record> &res):_res(res), _score(-1) {
}

Result::Result(const std::vector <Record> &res, int score):_res(res), _score(score) {
}

vector <Record> &Result::get() {
    return _res;
}

void Result::setScore(int score) {
    _score = score;
}

int Result::getScore() {
    return _score;
}

QDataStream & operator << (QDataStream &stream, const Result &p) {
    stream << p._score << QVector <Record>::fromStdVector(p._res);
    return stream;
}

QDataStream & operator >> (QDataStream &stream, Result &p) {
    QVector <Record> r;
    stream >> p._score >> r;
    p._res = r.toStdVector();
    return stream;
}
