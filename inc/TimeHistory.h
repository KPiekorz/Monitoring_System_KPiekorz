//
// Created by kpiek on 4/16/2020.
//

#ifndef MONITORING_SYSTEM_KPIEKORZ_TIMEHISTORY_H
#define MONITORING_SYSTEM_KPIEKORZ_TIMEHISTORY_H

#include "Sequence.h"
#include <iostream>
#include <string>

using namespace std;


class TimeHistory : protected Sequence{

private:
    double sensitivity;

protected:


public:
    TimeHistory() : sensitivity(0) {}

    string toString();

};


#endif //MONITORING_SYSTEM_KPIEKORZ_TIMEHISTORY_H
