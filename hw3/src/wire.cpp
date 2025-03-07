#include <iostream>
#include <string>
#include "../include/wire.h"

using namespace std;

Wire::Wire(Pin *src, Pin *dest)
{
    this->source = src;
    this->destination = dest;
}

void Wire::propagateSignal()
{
    this->destination->setSignal(this->source->getSignal());
}