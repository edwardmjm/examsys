#ifndef PROBLEMLIST_H
#define PROBLEMLIST_H
#include <vector>
#include <set>
#include <QString>
#include "Problem.h"
//试题集合
class Paper {
public:
    Paper(QString title, const std::vector <Problem> &l);
    Paper(QString title, const std::set <int> &, const std::vector <Problem> &);
    QString getTitle();
    std::vector <Problem> &getProb();
private:
    QString _title;
    std::vector <Problem> _l;
};

#endif // PROBLEMLIST_H
