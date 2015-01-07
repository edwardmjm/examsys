#ifndef PROBLEM_H
#define PROBLEM_H
#include <vector>
#include <QString>
#include <QVariant>
const int JUDGE_PROB_ANS_NUM = 0;
const int CHOOSE_PROB_ANS_NUM = 4;

//一道试题
class Problem {
public:
    Problem();

    Problem(QString problem, std::vector<QString> answer);

    Problem(const QString &prob, const QString &answer0, const QString &answer1, const QString &answer2, const QString &answer3, const bool &checked);

    void setProblem(const QString &problem);

    QString getProblem() const;

    void setAnswer(const std::vector <QString> &answer);

    std::vector <QString> getAnswer() const ;

    QVariantList toQVL() const ;

    static QVariantList emptyQVL();

    friend QDataStream & operator << (QDataStream &, const Problem &);
    friend QDataStream & operator >> (QDataStream &, Problem &);

private:
    bool isJudge() const ;

    bool isChoose() const ;

    QString _problem;
    std::vector <QString> _answer; //_answer里的元素要么为0个，要么为4个。分别代表判断题以及选择题
};

#endif // PROBLEM_H
