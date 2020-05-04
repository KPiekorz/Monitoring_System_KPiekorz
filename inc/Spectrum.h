//
// Created by kpiek on 4/16/2020.
//

#ifndef MONITORING_SYSTEM_KPIEKORZ_SPECTRUM_H
#define MONITORING_SYSTEM_KPIEKORZ_SPECTRUM_H

#include "Sequence.h"

enum Scaling_type{
    linear,
    logritm
};

template <class T>
class Spectrum : protected Sequence<T> {

private:
    Scaling_type scaling;


protected:



public:
    Spectrum() : scaling(linear), Sequence<T>::channelNr(0), Sequence<T>::unit("empty"), Sequence<T>::resolution(0) {}
    Spectrum(Scaling_type s, int ch, string u, double res) : scaling(s) {
        Sequence<T>::channelNr = ch;
        Sequence<T>::unit = u;
        Sequence<T>::resolution = res;
        Sequence<T>::buffer.clear();
    }



    string toString();




};

#include "../scr/Spectrum.tpp"

//template <typename TE>
//void


#endif //MONITORING_SYSTEM_KPIEKORZ_SPECTRUM_H


