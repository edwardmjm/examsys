#include "Util.h"
#include <sstream>
#include <iomanip>
using namespace std;

QString Util::toString(int value) {
    ostringstream oss;
    oss << value;
    return QString(oss.str().c_str());
}
