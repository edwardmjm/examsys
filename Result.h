#ifndef RESULT_H
#define RESULT_H

#include <vector>
#include "Record.h"
#include <QDebug>
#include "Paper.h"

//一张答卷
class Result {
public:
    Result();
    Result(const std::vector <Record> &res);
    Result(const std::vector <Record> &res, int score);
    Result(const std::map <int, Record> &, const Paper &, QString);

    std::vector <Record> &get();

    void printInfo() const;

    void setScore(int score);

    int size() const ;

    int getScore() const ;

    QString getStudentId() const ;

    QString getPaperTitle() const ;

    QVariantList toQVL(int idx) const ;

    friend QDataStream & operator << (QDataStream &, const Result &);
    friend QDataStream & operator >> (QDataStream &, Result &);

private:
    Paper _paper;
    std::vector <Record> _res;   //答案记录
    int _score;                  //-1表示未批改
    QString _studentId;
};

#endif // RESULT_H
