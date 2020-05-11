#include <iostream>
#include "../inc/TimeHistory.h"
#include "../inc/Spectrum.h"
#include "../inc/Alarm.h"

using namespace std;

int main() {

    TimeHistory <double> time_trzy(0.01, 1, "Volt", 0.01);
    TimeHistory <double> time_jeden(0.01, 2, "Volt", 0.01);

    gauss_generator(3., 0.3, time_trzy);
    gauss_generator(1., 0.3, time_jeden);

    cout << "RMS: " << calculate_RMS(time_trzy) << endl;

    time_trzy << "time_trzy.txt";
    time_jeden << "time_jeden.txt";

//    TimeHistory<double> wynik = time_jeden/time_trzy;

//    wynik << "hej.txt";

//    cout << time.toString() << endl;
//
//    cout << calculate_RMS(time) << endl;


//    Spectrum <double> spec(linear, 2, "Volt", 0.001);
//    cout << spec.toString() << endl;
//
//    Alarm ala;
//    cout << ala.toString() << endl;

    return 0;
}
