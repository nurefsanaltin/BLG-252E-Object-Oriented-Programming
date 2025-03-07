#include <string>
#include <iostream>
#include "../include/circuit.h"

using namespace std;

void Circuit::addComponent(Component *comp)
{
    components.push_back(comp);
}

void Circuit::addWire(Wire *wire)
{
    wires.push_back(wire);
}

void Circuit::simulate()
{

    for (int i = 0; i < components.size(); i++)
    {
        components[i]->evaluate();
        for (int i = 0; i < wires.size(); i++)
        {
            wires[i]->propagateSignal();
        }
    }
}

Circuit::~Circuit()
{
    cout << "Circuit's destructor is invoked\n";
}
