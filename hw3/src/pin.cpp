#include <string>
#include <iostream>
#include "../include/pin.h"

using namespace std;

Pin::Pin(const std::string &id)
    : Component(id)
{
}

void Pin::setSignal(bool val)
{
    this->value = val;
}

bool Pin::getSignal() const
{
    return this->value;
}

// I did not implement evaluate, do it later if it is necessary
void Pin::evaluate()
{
}
