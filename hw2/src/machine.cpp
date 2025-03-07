#include <iostream>
#include <string>
#include "../include/machine.hpp"

using namespace std;

Machine::Machine(std::string name, float price, float cost_per_day, float base_return_per_day, float failure_probability, int repair_time, float repair_cost)
    : Unit(name, cost_per_day, base_return_per_day), m_failure_probability{failure_probability}, m_repair_time{repair_time}, m_price{price}, m_repair_cost{repair_cost}, m_days_until_repair{0}
{
}
float Machine::getReturnPerDay()
{
    if (m_days_until_repair > 0)
    {
        // broken
        cout << "broken\n";
        m_days_until_repair--;
        return 0;
    }

    float is_failed = rand() / RAND_MAX;
    if (m_failure_probability > is_failed)
    {
        // failed
        cout << "failed\n";
        m_days_until_repair = m_repair_time;
        return -m_repair_cost;
    }
    else
    {
        // not failed
        return Unit::getReturnPerDay();
    }
}
float Machine::getPrice() const
{
    return this->m_price;
}