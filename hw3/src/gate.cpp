#include <string>
#include <iostream>
#include "../include/gate.h"
#include "../include/pin.h"

using namespace std;

Gate::Gate(const std::string &id, int numberOfInputs)
    : Component{id}
{
    for (int i = 0; i < numberOfInputs; i++)
    {
        string pin_id = to_string(i);
        Pin *new_pin = new Pin("PIN_" + pin_id);
        inputs.push_back(new_pin);
    }
    output = new Pin("OutputPIN");
}

Pin *Gate::getOutputPin()
{
    return this->output;
}

Pin *Gate::getInputPin(int i)
{
    return this->inputs[i];
}

Gate::~Gate()
{
    cout << "Gate's destructor is invoked\n";
}