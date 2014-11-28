#ifndef PROBLEM_H
#define PROBLEM_H
#include <vector>
#include <QString>

//一道试题
class Problem {
public:
    Problem(QString problem, std::vector<QString> answer);

    void setProblem(const QString &problem);

    QString getProblem() const;

    void setAnswer(const std::vector <QString> &answer);

    std::vector <QString> getAnswer() const ;
private:
    QString _problem;
    std::vector <QString> _answer; //_answer里的元素要么为0个，要么为4个。分别代表判断题以及选择题
};

#endif // PROBLEM_H
