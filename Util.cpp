#include "Util.h"
#include <sstream>
#include <iomanip>
using namespace std;

QString Util::toString(int value) {
    ostringstream oss;
    oss << value;
    return QString(oss.str().c_str());
}

int Util::toInt(QString s) {
    if (s == "0" || s == "1" || s == "2" || s == "3") {
        return s[0].toLatin1() - '0';
    } else {
        return -1;
    }
}
