#include <iostream>
#include <string>
#include "../include/factory.hpp"

using namespace std;

Factory::Factory(float capital)
{
    this->m_capital = capital;
}

void Factory::passOneDay()
{
    auto it = m_workers.begin();
    while (it != m_workers.end())
    {

        if (it->getExperience() == 11)
        {
            HeadWorker new_head_worker(*it);
            m_head_workers.push_back(new_head_worker);
            cout << new_head_worker.getName() << " is promoted\n";
            it = m_workers.erase(it);
        }
        else
        {
            ++it;
        }
    }

    // calculate overall daily cost&return
    float overall_daily_cost = 0;
    float overall_daily_return = 0;
    for (Worker &a_worker : m_workers)
    {
        overall_daily_cost += a_worker.getCostPerDay();
        overall_daily_return += a_worker.getReturnPerDay();
    }
    for (Machine &a_machine : m_machines)
    {
        overall_daily_cost += a_machine.getCostPerDay();
        overall_daily_return += a_machine.getReturnPerDay();
    }
    for (HeadWorker &a_head_worker : m_head_workers)
    {
        overall_daily_cost += a_head_worker.getCostPerDay();
        overall_daily_return += a_head_worker.getReturnPerDay();
    }
    m_capital += overall_daily_return - overall_daily_cost;

    // promote workers to head workers

    /* auto it = m_workers.begin();
    while (it != m_workers.end())
    {

        if (it->getExperience() == 11)
        {
            HeadWorker new_head_worker(*it);
            m_head_workers.push_back(new_head_worker);
            cout << new_head_worker.getName() << " is promoted\n";
            it = m_workers.erase(it);
        }
        else
        {
            ++it;
        }
    } */
}

void Factory::addUnit(const Worker &rhs_worker)
{
    m_workers.push_back(rhs_worker);
}
void Factory::addUnit(const Machine &rhs_machine)
{
    m_machines.push_back(rhs_machine);
    this->m_capital -= rhs_machine.getPrice();
}

bool Factory::isBankrupt() const
{
    return this->m_is_bankrupt;
}
float Factory::getCapital() const
{
    return this->m_capital;
}

int Factory::getWorkerCount() const
{
    return m_workers.size();
}
int Factory::getMachineCount() const
{
    return m_machines.size();
}
int Factory::getHeadWorkerCount() const
{
    return m_head_workers.size();
}