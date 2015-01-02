#include "Interacter.h"

Interacter::Interacter(QQmlContext *context): context(context) {
    this->context->setContextProperty("call", &call);
    call.setController(&ctrl);
}

Interacter::~Interacter() {
}
