#include <string>
#include <iostream>
#include "../include/not_gate.h"
#include "../include/pin.h"

using namespace std;

NOTGate::NOTGate(const std::string &id)
    : Gate(id, 1)
{
}
void NOTGate::evaluate()
{
    bool evaluation;

    if (inputs[0]->getSignal())
    {
        evaluation = 0;
    }
    else
    {
        evaluation = 1;
    }
    this->output->setSignal(evaluation);
}