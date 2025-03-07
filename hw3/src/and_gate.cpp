#include <string>
#include <iostream>
#include "../include/and_gate.h"
#include "../include/pin.h"

using namespace std;

ANDGate::ANDGate(const std::string &id)
    : Gate(id, 2)
{
}
void ANDGate::evaluate()
{
    bool evaluation = 1;
    for (int i = 0; i < this->inputs.size(); i++)
    {
        evaluation = evaluation & this->inputs[i]->getSignal();
    }
    this->output->setSignal(evaluation);
}