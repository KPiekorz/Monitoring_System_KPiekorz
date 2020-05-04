//
// Created by kpiek on 4/16/2020.
//

#include "../inc/TimeHistory.h"
#include <vector>

template <class T>
string TimeHistory<T> :: toString() {

    string parameter = "Time history:\n";
    parameter += "Channel number: "; parameter+= to_string(Sequence<T>::channelNr); parameter += "\n";
    parameter += "Unit: "; parameter += Sequence<T>::unit; parameter += "\n";
    parameter += "Resolution: "; parameter+= to_string(Sequence<T>::resolution); parameter += "\n";
    parameter += "Sensitivity: "; parameter+= to_string(sensitivity); parameter += "\n";
    parameter += "Buffer: \n";

    if(Sequence<T>::buffer.size() == 0){
        parameter += "buffer empty!!!\n";
    }else{
        for(int i = 0; i < Sequence<T>::buffer.size(); i++){
            parameter+= to_string(Sequence<T>::buffer[i]); parameter += "\n";
        }
    }


    return parameter;

}