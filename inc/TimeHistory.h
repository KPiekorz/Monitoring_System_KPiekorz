//
// Created by kpiek on 4/16/2020.
//

#ifndef MONITORING_SYSTEM_KPIEKORZ_TIMEHISTORY_H
#define MONITORING_SYSTEM_KPIEKORZ_TIMEHISTORY_H

#include "Sequence.h"
#include <iostream>
#include <string>
#include <random>
#include <cmath>

using namespace std;

template <class T>
class TimeHistory : protected Sequence<T>{

private:
    double sensitivity;

    template <typename TE>
    friend void gauss_generator(TE mean, TE stddev, TimeHistory<TE> & time_run);

    template <typename TE>
    friend TE calculate_RMS(TimeHistory<TE> & time_run);


protected:


public:
    TimeHistory() : sensitivity(0) {}
    TimeHistory(double s, int ch, string u, double res) : sensitivity(s){ //Sequence<T>::channelNr(ch), Sequence<T>::unit(u), Sequence<T>::resolution(res) {
        Sequence<T>::channelNr = ch;
        Sequence<T>::unit = u;
        Sequence<T>::resolution = res;
        Sequence<T>::buffer.clear();
    }

    string toString();



};

#include "../scr/TimeHistory.tpp"

template <typename TE>
void gauss_generator(TE mean, TE stddev, TimeHistory<TE> & time_run){

    default_random_engine generator;
    normal_distribution<TE> dist(mean, stddev);

    for(int i = 0; i < 4000; i++){
        time_run.buffer.push_back(dist(generator));
    }

}

template <typename TE>
TE calculate_RMS(TimeHistory<TE> & time_run){

    TE rms;

    TE ux = 0;
    for(int i=0; i < time_run.buffer.size(); i++){
        ux += time_run.buffer.at(i);
    }
    ux = ux/time_run.buffer.size();

    for(int i=0; i < time_run.buffer.size(); i++){
        rms += (time_run.buffer.at(i)-ux)*(time_run.buffer.at(i)-ux);
    }

    cout << rms << endl;

    rms = rms/(time_run.buffer.size()-1);
    rms = sqrt(rms);

    return rms;
}

#endif //MONITORING_SYSTEM_KPIEKORZ_TIMEHISTORY_H
