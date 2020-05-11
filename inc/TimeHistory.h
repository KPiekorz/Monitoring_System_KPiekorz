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

    // dodanie dwoch przebiegow czasowych
    template <typename TE> friend TimeHistory<TE> operator +(const TimeHistory<TE> &a, const TimeHistory<TE> &b);

    // dzielnie dwoch przebiegow czasowych
    template <typename TE> friend TimeHistory<TE> operator /(const TimeHistory<TE> &a, const TimeHistory<TE> &b);


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

    // overloading operator
    TimeHistory<T> operator = (const TimeHistory<T> &a);
    void operator <<(string filename);


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

    TE square = 0;
    TE mean = 0.0, root = 0.0;

    // Calculate square.
    for (int i = 0; i < time_run.buffer.size(); i++) {
        square += pow(time_run.buffer.at(i), 2);
    }

    // Calculate Mean.
    mean = (square / (float)(time_run.buffer.size()));

    // Calculate Root.
    root = sqrt(mean);

    return root;
}

#endif //MONITORING_SYSTEM_KPIEKORZ_TIMEHISTORY_H
