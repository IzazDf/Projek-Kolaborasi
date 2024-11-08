#include <iostream>
#include <cmath>
#include <string>
#include <emscripten.h>
#include "windows.h"

using namespace std;

void myprint(const wchar_t* str){
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        WriteConsoleW(h, str, wcslen(str), NULL, NULL);
    }

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    double fungsi_konversi(int awal, int akhir, long double nilai) {
        long double hasil = 1;
        long double hasil_ohm = nilai;
        int x = awal;
        int y = akhir;

        string satuan[]={"Tera ohm", "Giga ohm", "Mega ohm", "kilo ohm", "ohm", "mili ohm", "mikro ohm", "nano ohm", "pico ohm"};
        wstring st [] = {L"TΩ", L"GΩ", L"MΩ", L"kΩ", L"Ω", L"mΩ", L"μΩ", L"nΩ", L"pΩ"};

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

            cout << nilai << " " << satuan[awal - 1] << " "; wcout << "("; myprint(st[awal-1].c_str()); wcout << ")"; cout << " = " << hasil << " " << satuan[akhir - 1] << " "; wcout << "("; myprint(st[akhir-1].c_str()); wcout << ")" << endl;
            cout << nilai << " " << satuan[awal - 1] << " "; wcout << "("; myprint(st[awal-1].c_str()); wcout << ")"; cout << " = " << hasil_mega << " " << satuan[2] << " "; wcout << "("; myprint(st[2].c_str()); wcout << ")" << endl;
            cout << nilai << " " << satuan[awal - 1] << " "; wcout << "("; myprint(st[awal-1].c_str()); wcout << ")"; cout << " = " << hasil_ohm << " " << satuan[4] << " "; wcout << "("; myprint(st[4].c_str()); wcout << ")" << endl;
            cout << nilai << " " << satuan[awal - 1] << " "; wcout << "("; myprint(st[awal-1].c_str()); wcout << ")"; cout << " = " << hasil_mikro << " " << satuan[6] << " "; wcout << "("; myprint(st[6].c_str()); wcout << ")" << endl;


            return hasil;
    }

    
}