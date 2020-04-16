//
// Created by kpiek on 4/16/2020.
//

#include "../inc/TimeHistory.h"
#include <vector>


string TimeHistory :: toString() {

    string parameter = "";
    parameter += "Channel number: "; parameter+= to_string(channelNr); parameter += "\n";
    parameter += "Unit: "; parameter += unit; parameter += "\n";
    parameter += "Resolution: "; parameter+= to_string(resolution); parameter += "\n";
    parameter += "Sensitivity: "; parameter+= to_string(sensitivity); parameter += "\n";
    parameter += "Buffer: \n";

    if(buffer.size() == 0){
        parameter += "buffer empty!!!\n";
    }else{
        for(int i = 0; i < (int)buffer.size(); i++){
            parameter+= to_string(buffer[i]); parameter += "\n";
        }
    }


    return parameter;

}