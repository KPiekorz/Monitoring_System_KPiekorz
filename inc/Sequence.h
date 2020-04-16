//
// Created by kpiek on 4/16/2020.
//

#ifndef MONITORING_SYSTEM_KPIEKORZ_SEQUENCE_H
#define MONITORING_SYSTEM_KPIEKORZ_SEQUENCE_H

#include "Packet.h"
#include <iostream>
#include <vector>

using namespace std;

typedef int buffer_type;

class Sequence : protected Packet{

private:


protected:
    int channelNr;
    string unit;
    double resolution;
    vector < buffer_type > buffer;

public:
    Sequence(): channelNr(0), unit("empty"), resolution(0){
        buffer.clear();
    }

};


#endif //MONITORING_SYSTEM_KPIEKORZ_SEQUENCE_H
