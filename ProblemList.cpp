#include "ProblemList.h"
using namespace std;

ProblemList::ProblemList(const vector <Problem> &l):_l(l) {
}

vector <Problem> &ProblemList::get() {
    return _l;
}
