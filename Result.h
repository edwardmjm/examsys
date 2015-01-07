#ifndef RESULT_H
#define RESULT_H

#include <vector>
#include "Record.h"

//一张答卷
class Result {
public:
    Result();

    Result(const std::vector <Record> &res);

    Result(const std::vector <Record> &res, int score);

    std::vector <Record> &get();

    void setScore(int score);

    int getScore();

    friend QDataStream & operator << (QDataStream &, const Result &);
    friend QDataStream & operator >> (QDataStream &, Result &);

private:
    std::vector <Record> _res;   //答案记录
    int _score;                  //-1表示未批改
};

#endif // RESULT_H
