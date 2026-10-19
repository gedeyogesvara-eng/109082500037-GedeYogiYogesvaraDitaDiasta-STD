#include <iostream>
using namespace std;

int main() {
    int a;

    cout << "Masukkan angka : ";
    cin >> a;

    string namaangka[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas", "belas", "puluh", "seratus"};

    if (a >= 0 && a <= 10) {
        cout << a << " : " << namaangka[a] << endl;
    } else if (a == 11) {
        cout << a << " : " << namaangka[11] << endl;
    } else if (a > 11 && a < 20) {
        cout << a << " : " << namaangka[a - 10] << " belas" << endl;
    } else if (a >= 20 && a < 100) {
        int puluhan = a / 10;
        int satuan = a % 10;
        cout << a << " : " << namaangka[puluhan] << " puluh";
        if (satuan != 0) {
            cout << " " << namaangka[satuan];
        }
        cout << endl;
    } else if (a == 100) {
        cout << a << " : " << namaangka[14] << endl;
    } else {
        cout << "Angka tidak valid" << endl;
    }

    return 0;
}
