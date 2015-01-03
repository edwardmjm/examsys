#include "Paper.h"
#include <QDebug>
using namespace std;

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
