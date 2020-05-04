//
// Created by kpiek on 4/16/2020.
//

#ifndef MONITORING_SYSTEM_KPIEKORZ_SPECTRUM_H
#define MONITORING_SYSTEM_KPIEKORZ_SPECTRUM_H

#include "Sequence.h"

enum Scaling_type{
    lin,
    log
};

template <class T>
class Spectrum : protected Sequence<T> {

private:
    int scaling;


protected:



public:
    Spectrum() : scaling(0) {}

    string toString();




};



#include "../scr/Spectrum.tpp"

#endif //MONITORING_SYSTEM_KPIEKORZ_SPECTRUM_H
