//
// Created by kpiek on 4/16/2020.
//

#ifndef MONITORING_SYSTEM_KPIEKORZ_SPECTRUM_H
#define MONITORING_SYSTEM_KPIEKORZ_SPECTRUM_H

#include "Sequence.h"
#include "TimeHistory.h"

enum Scaling_type{
    linear,
    logritm
};

enum FFT_type{
    Complex,
    Ampitude
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

    // zapis do pliku
    void operator <<(string filename);

    //widmo amplitudowe lub zespolone z time history
    void FFT(TimeHistory<T> time_hist, FFT_type fft_t);

};

#include "../scr/Spectrum.tpp"

#endif //MONITORING_SYSTEM_KPIEKORZ_SPECTRUM_H


