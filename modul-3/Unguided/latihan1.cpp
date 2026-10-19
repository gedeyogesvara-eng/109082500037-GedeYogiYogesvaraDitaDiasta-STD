#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

struct mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    mahasiswa data[MAX];
    int n;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        cin >> data[i].nama;
        cout << "NIM   : ";
        cin >> data[i].nim;
        cout << "UTS   : ";
        cin >> data[i].uts;
        cout << "UAS   : ";
        cin >> data[i].uas;
        cout << "Tugas : ";
        cin >> data[i].tugas;

        data[i].nilaiAkhir = hitungNilaiAkhir(data[i].uts, data[i].uas, data[i].tugas);
    }

    cout << "Daftar Nilai Mahasiswa:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Mahasiswa " << i + 1 << endl;
        cout << "Nama        : " << data[i].nama << endl;
        cout << "NIM         : " << data[i].nim << endl;
        cout << "Nilai Akhir : " << data[i].nilaiAkhir << endl;
    }
    return 0;
}