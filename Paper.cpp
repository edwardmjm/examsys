#include "Paper.h"
#include <QDebug>
#include <QVector>
using namespace std;

Paper::Paper()
    :_title(""), _l(vector <Problem> ()) {

}

Paper::Paper(QString title, const vector <Problem> &l): _title(title), _l(l) {
}

Paper::Paper(QString title, const std::set <int> &s, const vector <Problem> &v): _title(title) {
    _l.clear();
    for (set <int>::const_iterator it = s.begin(); it != s.end(); it++) {
        _l.push_back(v[*it - 1]);
    }
}

QString Paper::getTitle() {
    return _title;
}

vector <Problem> &Paper::getProb() {
    return _l;
}

QDataStream & operator << (QDataStream &stream, const Paper &p) {
    stream << p._title << QVector <Problem>::fromStdVector(p._l);
    return stream;
}

QDataStream & operator >> (QDataStream &stream, Paper &p) {
    QString title;
    QVector <Problem> prob;
    stream >> title;
    stream >> prob;
    p = Paper(title, prob.toStdVector());
    return stream;
}
