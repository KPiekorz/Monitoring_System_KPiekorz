//
// Created by kpiek on 4/16/2020.
//

#ifndef MONITORING_SYSTEM_KPIEKORZ_ALARM_H
#define MONITORING_SYSTEM_KPIEKORZ_ALARM_H

#include "Packet.h"



class Alarm : protected Packet {

private:
    int channelNr;
    long long xthreshold;
    int direction;


protected:



public:
    Alarm() : channelNr(0), xthreshold(0), direction(0) {}

    string toString();

};


#endif //MONITORING_SYSTEM_KPIEKORZ_ALARM_H
