#ifndef PROBLEMLIST_H
#define PROBLEMLIST_H
#include <vector>
#include "Problem.h"
//试题集合
class ProblemList {
public:
    ProblemList(const std::vector <Problem> &l);
    std::vector <Problem> &get();
private:
    std::vector <Problem> _l;
};

#endif // PROBLEMLIST_H
