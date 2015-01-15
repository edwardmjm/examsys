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

void Result::printInfo() const {
    qDebug() << _res.size();
    for (Record it : _res) {
        qDebug() << it.getProblem().getProblem();
        qDebug() << it.getAnswer();
    }
}

int Result::getScore() {
    return _score;
}

int Result::size() const {
    return _paper.getProb().size();
}

Result::Result(const std::map <int, Record> &mp, const Paper &paper, QString id) {
    _res = vector <Record> ();
    _score = -1;
    _paper = paper;
    for (std::map <int, Record>::const_iterator it = mp.begin(); it != mp.end(); it++) {
        _res.push_back(it->second);
    }
    _studentId = id;

}

QVariantList Result::toQVL(int idx) const {
    QVariantList ret = _paper.getProb()[idx].toQVL();
    bool found = false;
    for (Record r : _res) {
        if (r.getProblem() == _paper.getProb()[idx]) {
            found = true;
            ret.append(QString(QChar((char)('A' + r.getAnswer()))));
        }
    }
    if (!found) {
        ret.append(QString(""));
    }
    return ret;
}

QString Result::getStudentId() const {
    return _studentId;
}

QString Result::getPaperTitle() const {
    return _paper.getTitle();
}


QDataStream & operator << (QDataStream &stream, const Result &p) {
    stream << p._score << QVector <Record>::fromStdVector(p._res) << p._paper << p._studentId;
    return stream;
}

QDataStream & operator >> (QDataStream &stream, Result &p) {
    QVector <Record> r;
    stream >> p._score >> r;
    p._res = r.toStdVector();
    stream >> p._paper >> p._studentId;
    return stream;
}
