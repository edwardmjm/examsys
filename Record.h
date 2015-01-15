#ifndef RECORD_H
#define RECORD_H

#include "Problem.h"

//考生答的一道题
class Record {
public:
    Record();
    Record(const Problem &problem, int answer);

    Problem getProblem() const;

    int getAnswer() const;

    friend QDataStream & operator << (QDataStream &, const Record &);
    friend QDataStream & operator >> (QDataStream &, Record &);

private:
    Problem _problem; //题目
    int _answer; //选第几个答案 选择题取值为0~3，判断题为0~1(0为false，1为true)，-1表示没选
};
#endif // RECORD_H
