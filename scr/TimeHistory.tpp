//
// Created by kpiek on 4/16/2020.
//

#include "../inc/TimeHistory.h"
#include <vector>
#include <fstream>

/* wypisz atrybuty klasa na wyjscie standarowe */
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
            parameter+= to_string(Sequence<T>::buffer[i]); parameter += "  ";
        }
        parameter += "\n\n";
    }


    return parameter;

}


template <class T>
TimeHistory<T> TimeHistory<T>::operator = (const TimeHistory<T> &a){

    try{
        if(this->buffer.size() != a.buffer.size()){
            throw "Buffer not equal";
        }
    }catch (const char * msg){
        cerr << msg << endl;
    }

    for(int i = 0; i < a.buffer.size(); i++){
        this->buffer.at(i) = a.buffer.at(i);
    }

    return *this;
}

// save to file
template <class T>
void TimeHistory<T>::operator <<(string filename){


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



// friend function


template <typename TE> TimeHistory<TE> operator +(const TimeHistory<TE> &a, const TimeHistory<TE> &b){

    try{

        if(a.buffer.empty() || b.buffer.empty()) {
            throw "time buf empty";
        }

        if(a.buffer.size() != b.buffer.size()){
            throw "different buffer length";
        }

    }catch (const char * msg){
        cerr << msg << endl;
    }

    TimeHistory<TE> time_result;

    for(int i = 0; i < a.buffer.size(); i++){
        time_result.buffer.push_back(a.buffer.at(i)+b.buffer.at(i));
    }

    return time_result;
}

template <typename TE> TimeHistory<TE> operator /(const TimeHistory<TE> &a, const TimeHistory<TE> &b){


    try{

        if(a.buffer.empty() || b.buffer.empty()) {
            throw "time buf empty";
        }

        if(a.buffer.size() != b.buffer.size()){
            throw "different buffer length";
        }

    }catch (const char * msg){
        cerr << msg << endl;
    }

    TimeHistory<TE> time_result;

    try {

        for(int i = 0; i < a.buffer.size(); i++){

            if(a.buffer.at(i) == 0){
                throw "dzielenie przez zero";
            }

            time_result.buffer.push_back(a.buffer.at(i)/b.buffer.at(i));
        }


    }catch (const char * msg){
        cerr << msg << endl;
    }


    return time_result;

}

