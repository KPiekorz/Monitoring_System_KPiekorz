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

// save to file
template <class T>
void Spectrum<T>::operator <<(string filename){


    ofstream time_history_file; //(file_name, ios::out | ios::in);

    time_history_file.open(filename);

    try{

        if (time_history_file.is_open()) {
            cout << "File open" << endl;
        } else {
            throw "cant open file";
        }

    }catch(const char * msg){
        cerr << msg << endl;
    }

    for(int i = 0; i < Sequence<T>::buffer.size(); i++){
        time_history_file << Sequence<T>::buffer.at(i) << "\n";
    }


    time_history_file.close();

}

template <class T>
void Spectrum<T>::FFT(TimeHistory<T> time_hist, FFT_type fft_t) {

    if(fft_t == Complex){


    }else if(fft_t == Ampitude){

    }

}
