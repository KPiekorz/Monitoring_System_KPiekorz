//
// Created by kpiek on 4/16/2020.
//

#include "../inc/Alarm.h"


string Alarm :: toString(){

    string parameters_values = "Alarm:\n";

    parameters_values += "Device name: ";
    parameters_values += device; parameters_values += "\n";

    parameters_values += "Description: ";
    parameters_values += description; parameters_values += "\n";

    parameters_values += "Date: ";
    parameters_values += to_string(date); parameters_values += "\n";

    parameters_values += "Chanel number: ";
    parameters_values += to_string(channelNr); parameters_values += "\n";

    parameters_values += "Treshold: ";
    parameters_values += to_string(xthreshold); parameters_values += "\n";

    parameters_values += "Direction: ";
    parameters_values += to_string(direction); parameters_values += "\n";

    return parameters_values;


}
