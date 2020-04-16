//
// Created by kpiek on 4/15/2020.
//

#ifndef MONITORING_SYSTEM_KPIEKORZ_PACKET_H
#define MONITORING_SYSTEM_KPIEKORZ_PACKET_H

#include <string>

using namespace std;

class Packet {

private:



protected:
    string device;
    string description;
    long date; // amount of second from begining


public:
    Packet():device("empty"), description("empty"), date(0){}

};


#endif //MONITORING_SYSTEM_KPIEKORZ_PACKET_H
