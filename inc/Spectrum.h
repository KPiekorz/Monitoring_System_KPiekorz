//
// Created by kpiek on 4/16/2020.
//

#ifndef MONITORING_SYSTEM_KPIEKORZ_SPECTRUM_H
#define MONITORING_SYSTEM_KPIEKORZ_SPECTRUM_H

#include "Sequence.h"

enum {
    lin,
    log
};

class Spectrum : protected Sequence {

private:
    int scaling;


protected:



public:
    Spectrum() : scaling(0) {}

    string toString();


};


#endif //MONITORING_SYSTEM_KPIEKORZ_SPECTRUM_H
