#include <iostream>
#include "../inc/TimeHistory.h"
#include "../inc/Spectrum.h"
#include "../inc/Alarm.h"

using namespace std;

int main() {

    TimeHistory <double> time(0.01, 1, "Volt", 0.01);

    gauss_generator(3., 0.3, time);

    cout << time.toString() << endl;

    cout << calculate_RMS(time) << endl;


//    Spectrum <double> spec(linear, 2, "Volt", 0.001);
//    cout << spec.toString() << endl;
//
//    Alarm ala;
//    cout << ala.toString() << endl;

    return 0;
}
