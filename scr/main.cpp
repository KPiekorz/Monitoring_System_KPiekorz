#include <iostream>
#include "../inc/TimeHistory.h"
#include "../inc/Spectrum.h"
#include "../inc/Alarm.h"

using namespace std;

int main() {

    TimeHistory <int> time;
    cout << time.toString() << endl;

    Spectrum <int> spec;
    cout << spec.toString() << endl;

    Alarm ala;
    cout << ala.toString() << endl;

    return 0;
}
