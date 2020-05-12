#include <iostream>
#include "../inc/TimeHistory.h"
#include "../inc/Spectrum.h"
#include "../inc/Alarm.h"

using namespace std;

int main() {
    
    // Inicjalizacja sesji pomiarowej
    TimeHistory<double> sygnal1(0.01, 1, "Dev1", 0.01);
    TimeHistory<double> sygnal2(0.01, 1, "Dev2", 0.01);
    TimeHistory<double> sygnal3(0.01, 1, "Dev3", 0.01);
    TimeHistory<double> sygnal4(0.01, 1, "Dev4", 0.01);
    Spectrum<double> widmo_sygnal1;
    Spectrum<double> widmo_sygnal2;
    Spectrum<double> widmo_sygnal3;
    Spectrum<double> widmo_sygnal4;

    // zapisane do jako sygnal dane z bialym szumem
    gauss_generator(3., 0.3, sygnal1, 4096);
    gauss_generator(6., 0.3, sygnal2, 4096);
    gauss_generator(8., 0.1, sygnal3, 4096);
    gauss_generator(3., 0.3, sygnal4, 4096);

    // zamiana kanalu 1 z 2 z uzyciem kanalu przeciazonego
    TimeHistory<double> tmp = sygnal1;
    sygnal1 = sygnal2;
    sygnal2 = tmp;

    // suma kanalow z 2 i 3 przy uzyciu opertora przeciazonego
    TimeHistory<double> suma = sygnal2+sygnal3;

    // operacja dzielenia kanalow 1 i 4
    TimeHistory<double> dziel = sygnal1/sygnal4;

    // wyzaczyc widmo zespolone oraz amplitudowe kazdego kanalu
    calculate_FFT(sygnal1, widmo_sygnal1); // funckja ta tworzy widmo amplitudowe i zespolone, nastepnie zapisuje je do zmiennych w klasie Spectrum
    calculate_FFT(sygnal2, widmo_sygnal2); // funckja ta tworzy widmo amplitudowe i zespolone, nastepnie zapisuje je do zmiennych w klasie Spectrum
    calculate_FFT(sygnal3, widmo_sygnal3); // funckja ta tworzy widmo amplitudowe i zespolone, nastepnie zapisuje je do zmiennych w klasie Spectrum
    calculate_FFT(sygnal4, widmo_sygnal4); // funckja ta tworzy widmo amplitudowe i zespolone, nastepnie zapisuje je do zmiennych w klasie Spectrum

    // zapis ciagow czasowych oraz widmowych do plikow przy pomocy operatorow przeciarzonych
    // zapis stworzonych przebiegow do plikow txt z pomoca operatorow przeciarzonych
    sygnal1 << "timehist_sig1.txt";
    sygnal2 << "timehist_sig2.txt";
    sygnal3 << "timehist_sig3.txt";
    sygnal4 << "timehist_sig4.txt";

    widmo_sygnal1 << "widmo_sig1.txt"; // operator ten tworzy dwa pliki z prefiksem oznaczajacy dany sygnal, jeden plik zawiera widmo aplitudowe, a drugi zespolone
    widmo_sygnal2 << "widmo_sig2.txt"; // operator ten tworzy dwa pliki z prefiksem oznaczajacy dany sygnal, jeden plik zawiera widmo aplitudowe, a drugi zespolone
    widmo_sygnal3 << "widmo_sig3.txt"; // operator ten tworzy dwa pliki z prefiksem oznaczajacy dany sygnal, jeden plik zawiera widmo aplitudowe, a drugi zespolone
    widmo_sygnal4 << "widmo_sig4.txt"; // operator ten tworzy dwa pliki z prefiksem oznaczajacy dany sygnal, jeden plik zawiera widmo aplitudowe, a drugi zespolone

    // wypisac na konsole RMS kazdego z kanałow
    cout << "RMS1: " << calculate_RMS(sygnal1) << endl;
    cout << "RMS2: " << calculate_RMS(sygnal2) << endl;
    cout << "RMS3: " << calculate_RMS(sygnal3) << endl;
    cout << "RMS4: " << calculate_RMS(sygnal4) << endl;


    return 0;
}
