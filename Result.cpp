#include "Result.h"
using namespace std;

Result::Result(const std::vector <Record> &res):_res(res), _score(-1) {
}

Result::Result(const std::vector <Record> &res, int score):_res(res), _score(score) {
}

vector <Record> &Result::get() {
    return _res;
}

void Result::setScore(int score) {
    _score = score;
}

int Result::getScore() {
    return _score;
}
