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

    Sequence(int ch, string u, double res, vector<T> buf): channelNr(ch), resolution(res){
        unit.assign(u);
        buffer.assign(buf);
    }

};


#endif //MONITORING_SYSTEM_KPIEKORZ_SEQUENCE_H
