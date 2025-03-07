#include <string>
#include <iostream>
#include "../include/component.h"

using namespace std;

Component::Component(const string &id)
{
    this->id = id;
}

Component::~Component()
{
    cout << "component's destructor is invoked" << endl;
}
