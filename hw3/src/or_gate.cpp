#include <string>
#include <iostream>
#include "../include/or_gate.h"
#include "../include/pin.h"

using namespace std;

ORGate::ORGate(const std::string &id)
    : Gate(id, 2)
{
}
void ORGate::evaluate()
{
    bool evaluation = 0;
    for (int i = 0; i < this->inputs.size(); i++)
    {
        evaluation = evaluation || this->inputs[i]->getSignal();
    }
    this->output->setSignal(evaluation);
}