//
// Created by kpiek on 4/16/2020.
//

#include "../inc/Spectrum.h"

template <class T>
string Spectrum<T>::toString() {

    string parameter = "Spectrum:\n";
    parameter += "Channel number: "; parameter+= to_string(Sequence<T>::channelNr); parameter += "\n";
    parameter += "Unit: "; parameter += Sequence<T>::unit; parameter += "\n";
    parameter += "Resolution: "; parameter+= to_string(Sequence<T>::resolution); parameter += "\n";
    parameter += "Scaling: "; parameter+= to_string(scaling); parameter += "\n";
    parameter += "Buffer: \n";

    if(Sequence<T>::buffer.size() == 0){
        parameter += "buffer empty!!!\n";
    }else{
        for(int i = 0; i < Sequence<T>::buffer.size(); i++){
            parameter+= to_string(Sequence<T>::buffer[i]); parameter += "  ";
        }
        parameter += "\n\n";
    }

    return parameter;
}