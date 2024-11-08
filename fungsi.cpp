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
            
            long double hasilmega = hasil_ohm / pow(1000, 2);
            long double hasilmikro = hasil_ohm * pow(1000, 2);
    }

    
}