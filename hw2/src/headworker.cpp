#include <iostream>
#include <string>
#include "../include/headworker.hpp"

using namespace std;

HeadWorker::HeadWorker(Worker &worker)
    : Worker(worker)
{
    Worker::increaseHeadWorkerCount();
}

float HeadWorker::getReturnPerDay()
{
    float daily_return;
    daily_return = (Unit::getReturnPerDay()) + (this->getExperience()) * 5;

    m_experience++;
    cout << this->m_experience << endl;
    return daily_return;
}