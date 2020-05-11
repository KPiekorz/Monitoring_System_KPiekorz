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

    string file_amp = "widmo_amp_"+filename;
    string file_comp = "widmo_zesp_"+filename;

    ofstream aplitudowy_file; //(file_name, ios::out | ios::in);
    ofstream zespolony_file;

    aplitudowy_file.open(file_amp);
    zespolony_file.open(file_comp);

    try{

        if (aplitudowy_file.is_open()) {
            cout << "File open" << endl;
        } else {
            throw "cant open file";
        }

        if (zespolony_file.is_open()) {
            cout << "File open" << endl;
        } else {
            throw "cant open file";
        }

    }catch(const char * msg){
        cerr << msg << endl;
    }

    // zapis amplitud
    for(int i = 0; i < widmo_amplitudowe.size(); i++){
        aplitudowy_file << widmo_amplitudowe.at(i) << "\n";
    }

    // zapis zespolonych
    for(int i = 0; i < widmo_zespolone.size(); i++){
        zespolony_file << widmo_zespolone.at(i) << "\n";
    }


    aplitudowy_file.close();
    zespolony_file.close();

}
