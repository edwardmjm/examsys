#ifndef INTERACTER_H
#define INTERACTER_H

#include "Caller.h"
#include "Controller.h"
#include "UIState.h"

class Interacter {
public:
    Interacter(QQmlContext *context);

private:
    Caller call;
    Controller ctrl;
    UIState state;
    QQmlContext *context;
};

#endif // INTERACTER_H
