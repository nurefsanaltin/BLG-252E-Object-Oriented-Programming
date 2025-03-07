#include <iostream>
#include <string>
#include <fstream>
#include "../include/simulation.hpp"

using namespace std;

void Simulation::printWelcomeMessage() const
{
    cout << "Welcome to the Car Factory!" << endl;
    cout << "You have " << m_total_days << " days to make as much money as possible" << endl;
    cout << "You can add workers, machines, and fast forward days" << endl;

    cout << "Available commands:" << endl;
    cout << "    wX: adds X workers" << endl;
    cout << "    mX: adds X machines" << endl;
    cout << "    pX: passes X days" << endl;
    cout << "    q: exit the game properly" << endl;
}

// read and put them into vectors
Simulation::Simulation(Factory &factory, int total_days, string workers_list_path, string machines_list_path)
{
    this->m_factory = &factory;
    this->m_total_days = total_days;

    fstream workers_file;
    workers_file.open(workers_list_path, ios::in);
    if (workers_file.is_open())
    {

        string w1, w2, w3;
        workers_file >> w1 >> w2 >> w3;
        int i = 0;
        while (!workers_file.eof())
        {
            if (i == 100)
            {
                break;
            }

            string name;
            string daily_cost_s;
            string daily_return_s;

            float daily_cost;
            float daily_return;

            workers_file >> name >> daily_cost_s >> daily_return_s;

            daily_cost = stof(daily_cost_s);
            daily_return = stof(daily_return_s);

            Worker new_worker(name, daily_cost, daily_return);

            m_labor_market.push_back(new_worker);
            i++;
        }
    }
    else
    {
        cout << "Workers file cannot be opened successfully\n";
    }

    fstream machines_file;
    machines_file.open(machines_list_path, ios::in);
    if (machines_file.is_open())
    {

        string w1, w2, w3, w4, w5, w6, w7;
        machines_file >> w1 >> w2 >> w3 >> w4 >> w5 >> w6 >> w7;
        int i = 0;

        while (!machines_file.eof())
        {

            if (i == 100)
            {
                break;
            }
            string name, price_s, daily_cost_s, daily_return_s, fail_prob_s, repair_cost_s, repair_time_s;
            float price, daily_cost, daily_return, fail_prob, repair_cost, repair_time;

            machines_file >> name >> price_s >> daily_cost_s >> daily_return_s >> fail_prob_s >> repair_cost_s >> repair_time_s;

            price = stof(price_s);
            daily_cost = stof(daily_cost_s);
            daily_return = stof(daily_return_s);
            fail_prob = stof(fail_prob_s);
            repair_cost = stof(repair_cost_s);
            repair_time = stof(repair_time_s);

            Machine new_machine(name, price, daily_cost, daily_return, fail_prob, repair_time, repair_cost);
            m_machines_market.push_back(new_machine);

            i++;
        }
    }
    else
    {
        cout << "Machines file cannot be opened successfully\n";
    }
    workers_file.close();
    machines_file.close();
}

// When you want to hire or buy a unit, you will randomly pick one from the corresponding vector
Machine Simulation::buyRandomMachine()
{
    int index = rand() % m_machines_market.size();
    Machine b_machine(m_machines_market[index]);
    m_factory->addUnit(b_machine);
    cout << m_machines_market[index].getName() << " is bought\n";
    m_machines_market.erase(m_machines_market.begin() + index);
    return b_machine;
}
Worker Simulation::hireRandomWorker()
{
    int index = rand() % m_labor_market.size();
    // Worker b_worker(m_labor_market[index].getName(), m_labor_market[index].getCostPerDay(), m_labor_market[index].getReturnPerDay());
    Worker b_worker(m_labor_market[index]);
    m_factory->addUnit(b_worker);

    cout << m_labor_market[index].getName() << " is hired\n";
    m_labor_market.erase(m_labor_market.begin() + index);
    return b_worker;
}

void Simulation::run()
{
    string command;
    int total_day = m_total_days;
    float initial_capital = m_factory->getCapital();

    while (true)
    {
        cout << "Enter command: ";
        cin >> command;
        int number_of_workers;
        int number_of_machines;
        int days_passed;
        if (command[0] == 'w')
        {
            number_of_workers = stoi(command.substr(1));
            for (int i = 0; i < number_of_workers; i++)
            {
                hireRandomWorker();
            }
        }
        else if (command[0] == 'm')
        {
            number_of_machines = stoi(command.substr(1));
            for (int i = 0; i < number_of_machines; i++)
            {
                buyRandomMachine();
            }
        }
        else if (command[0] == 'p')
        {
            days_passed = stoi(command.substr(1));
            for (int i = 0; i < days_passed; i++)
            {
                cout << "--- Day: " << total_day + 1 - m_total_days << "\n";
                m_factory->passOneDay();
                cout << "[C: " << m_factory->getCapital() << ", W: " << m_factory->getWorkerCount() << ", M: " << m_factory->getMachineCount() << ", HW: " << m_factory->getHeadWorkerCount() << "]\n";
                m_total_days--;
                if (m_factory->getCapital() < 0 || m_total_days == 0)
                {
                    break;
                }
            }
            if (m_factory->getCapital() < 0)
            {
                cout << "You went bankrupt!\n";
                break;
            }
            if (m_total_days == 0)
            {
                break;
            }
        }
        else if (command[0] == 'q')
        {
            break;
        }
        else
        {
            cout << "Invalid input!\n";
        }
    }
    cout << "Congrats! You have earned " << m_factory->getCapital() - initial_capital << " in " << total_day << " days\n";
}