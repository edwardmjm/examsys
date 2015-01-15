#ifndef PROBLEMLIST_H
#define PROBLEMLIST_H
#include <vector>
#include <set>
#include <QString>
#include "Problem.h"
//试题集合
class Paper {
public:
    Paper();
    Paper(QString title, const std::vector <Problem> &l);
    Paper(QString title, const std::set <int> &, const std::vector <Problem> &);
    QString getTitle() const;
    std::vector <Problem> &getProb();
    const std::vector <Problem> &getProb() const ;

    friend QDataStream & operator << (QDataStream &, const Paper &);
    friend QDataStream & operator >> (QDataStream &, Paper &);

private:
    QString _title;
    std::vector <Problem> _l;
};

#endif // PROBLEMLIST_H
