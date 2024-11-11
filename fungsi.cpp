#include <iostream>
#include <cmath>
#include <string>
#include <emscripten.h>

using namespace std;

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    double fungsi_konversi(int awal, int akhir, long double nilai) {
        long double hasil = 1;
        long double hasil_ohm = nilai;
        int x = awal;
        int y = akhir;

        string satuan[]={"Tera ohm (TΩ)", "Giga ohm (GΩ)", "Mega ohm (MΩ)", "kilo ohm (kΩ)", "ohm (Ω)", "mili ohm (mΩ)", "mikro ohm (μΩ)", "nano ohm (nΩ)", "pico ohm (pΩ)"};

        if (x > 5){
                int z = x - 5;
                hasil_ohm /= pow(1000, z);
            } else if (awal < 5){
                int z = 5 - x;
                hasil_ohm *= pow(1000, z);
            }
            
            if (y > 5){
                int z = y - 5;
                hasil = hasil_ohm * pow(1000, z);
            } else if (akhir < 5){
                int z = 5 - y;
                hasil = hasil_ohm / pow(1000, z);
            } else {
                hasil = hasil_ohm;
            }
            
            long double hasil_mega = hasil_ohm / pow(1000, 2);
            long double hasil_mikro = hasil_ohm * pow(1000, 2);

            cout << nilai << " " << satuan[awal - 1] << " = " << hasil << " " << satuan[akhir - 1] << endl;
            cout << nilai << " " << satuan[awal - 1] << " = " << hasil_mega << " " << satuan[2] << endl;
            cout << nilai << " " << satuan[awal - 1] << " = " << hasil_ohm << " " << satuan[4] << endl;
            cout << nilai << " " << satuan[awal - 1] << " = " << hasil_mikro << " " << satuan[6] << endl;


            return hasil;
    }

    
}