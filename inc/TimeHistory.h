//
// Created by kpiek on 4/16/2020.
//

#ifndef MONITORING_SYSTEM_KPIEKORZ_TIMEHISTORY_H
#define MONITORING_SYSTEM_KPIEKORZ_TIMEHISTORY_H

#include "Sequence.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
class TimeHistory : protected Sequence<T>{

private:
    double sensitivity;

protected:


public:
    TimeHistory() : sensitivity(0) {}

    string toString();

};

#include "../scr/TimeHistory.tpp"

#endif //MONITORING_SYSTEM_KPIEKORZ_TIMEHISTORY_H
