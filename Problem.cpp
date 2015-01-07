#include "Problem.h"
#include <cassert>
#include <QVector>
using namespace std;

Problem::Problem()
    :_problem(""), _answer(vector<QString> ()) {
}

Problem::Problem(QString problem, std::vector<QString> answer)
    :_problem(problem), _answer(answer) {
    assert(_answer.size() == 0 || _answer.size() == 4);
}

Problem::Problem(const QString &prob, const QString &answer0, const QString &answer1, const QString &answer2, const QString &answer3, const bool &checked) {
    _problem = prob;
    _answer.clear();
    if (!checked) {
        _answer.push_back(answer0);
        _answer.push_back(answer1);
        _answer.push_back(answer2);
        _answer.push_back(answer3);
    }
}

void Problem::setProblem(const QString &problem) {
    _problem = problem;
}

QString Problem::getProblem() const {
    return _problem;
}

void Problem::setAnswer(const std::vector <QString> &answer) {
    _answer = answer;
    assert(_answer.size() == JUDGE_PROB_ANS_NUM || _answer.size() == CHOOSE_PROB_ANS_NUM);
}

std::vector <QString> Problem::getAnswer() const {
    return _answer;
}

QVariantList Problem::toQVL() const {
    QVariantList res;
    res.append(_problem);
    if (isJudge()) {
        res.append(QString("对"));
        res.append(QString("错"));
        res.append(QString(""));
        res.append(QString(""));
        res.append(true);
    } else if (isChoose()) {
        for (int i = 0; i < 4; i++) {
            res.append(_answer[i]);
        }
        res.append(false);
    } else {
        assert(0);
    }
    return res;
}

QVariantList Problem::emptyQVL() {
    QVariantList res;
    for (int i = 0; i < 5; i++) {
        res.append(QString(""));
    }
    res.append(true);
    return res;
}


bool Problem::isJudge() const {
    return _answer.size() == 0;
}

bool Problem::isChoose() const {
    return _answer.size() == 4;
}

QDataStream & operator << (QDataStream &stream, const Problem &p) {
    stream << p.getProblem() << QVector <QString>::fromStdVector(p.getAnswer());
    return stream;
}

QDataStream & operator >> (QDataStream &stream, Problem &p) {
    QString prob;
    QVector <QString> answer;
    stream >> prob >> answer;
    p = Problem(prob, answer.toStdVector());
    return stream;
}
