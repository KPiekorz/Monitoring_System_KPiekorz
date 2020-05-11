//
// Created by kpiek on 4/16/2020.
//

#ifndef MONITORING_SYSTEM_KPIEKORZ_SPECTRUM_H
#define MONITORING_SYSTEM_KPIEKORZ_SPECTRUM_H

#include "Sequence.h"
#include "TimeHistory.h"
#include "fft.h"

enum Scaling_type{
    linear,
    logritm
};

enum FFT_type{
    Comp,
    Amp
};

template <class T>
class Spectrum : protected Sequence<T> {

private:
    Scaling_type scaling;

    template <typename TE>
    friend void calculate_FFT(TimeHistory<TE> & time_run, Spectrum<TE> & spec_run, FFT_type t);

protected:

    vector<T> widmo_amplitudowe;
    vector<complex<T>> widmo_zespolone;

public:
    Spectrum() : scaling(linear), Sequence<T>::Sequence() {}
    Spectrum(Scaling_type s, int ch, string u, double res) : scaling(s) {
        Sequence<T>::channelNr = ch;
        Sequence<T>::unit = u;
        Sequence<T>::resolution = res;
        Sequence<T>::buffer.clear();

        widmo_zespolone.clear();
        widmo_amplitudowe.clear();

    }



    string toString();

    // zapis do pliku
    void operator <<(string filename); // zapisz do pliku widmo apmlitudowe lub zespolone

};

#include "../scr/Spectrum.tpp"

// function to calculate widmo amplitudowe i zespolone of given signal
template <typename TE>
void calculate_FFT(TimeHistory<TE> & time_run, Spectrum<TE> & spec_run,FFT_type t){

    TE amplitude = 0;
    int samples = time_run.get_buffer_length();

    // The Fast Fourier Transform
    complex<double>* s = new complex<double>[samples];


    /* sample over a function */
    for (int t = 0; t < samples; t++)
    {
        /* === SIGNAL === */
        /* change for different signal */
        amplitude = time_run.get_buffer_value(t);

        /* set only the real parts */
        s[t].real(amplitude);
        s[t].imag(0);
    }

//    printlist(s, samples, FALSE);

    // calculate fourier transform
    fast_fourier(s,samples);

//    cout << "Output array: " << endl;
//    printlist(s,samples,TRUE);

    // make buffer empty
    spec_run.widmo_amplitudowe.clear();
    spec_run.widmo_zespolone.clear();

    for (int i = 0; i < samples; i++){
        spec_run.widmo_zespolone.push_back(s[i]);
    }

    double mag = 0;
    double phase = 0;

        for (int i = 0; i < samples; i++)
        {
            mag = magnitude(s[i], samples);
//            phase = atan(s[i].imag()/s[i].real());

            spec_run.widmo_amplitudowe.push_back(mag);

        }

}

#endif //MONITORING_SYSTEM_KPIEKORZ_SPECTRUM_H


