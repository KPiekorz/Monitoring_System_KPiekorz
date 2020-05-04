//
// Created by kpiek on 4/16/2020.
//

#ifndef MONITORING_SYSTEM_KPIEKORZ_SEQUENCE_H
#define MONITORING_SYSTEM_KPIEKORZ_SEQUENCE_H

#include "Packet.h"
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Sequence : protected Packet{

private:


protected:
    int channelNr;
    string unit;
    double resolution;
    vector <T> buffer;

public:
    Sequence(): channelNr(0), unit("empty"), resolution(0){
        buffer.clear();
    }


};

#include "../scr/Sequence.tpp"


#endif //MONITORING_SYSTEM_KPIEKORZ_SEQUENCE_H
