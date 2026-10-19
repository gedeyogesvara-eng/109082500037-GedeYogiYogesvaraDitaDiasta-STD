#include <iostream>
using namespace std;

void tampilkanArray(int arr[], int size) {
    cout << "Isi array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void cariMaksimum(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "Nilai maksimum: " << max << endl;
}

void cariMinimum(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    cout << "Nilai minimum: " << min << endl;
}

void hitungRataRata(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    double rataRata = static_cast<double>(sum) / size;
    cout << "Nilai rata-rata: " << rataRata << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int menu;

   cout << "--- Menu Program Array ---" << endl;
   cout << "1. Tampilkan isi array" << endl;
   cout << "2. Cari nilai maksimum" << endl;
   cout << "3. Cari nilai minimum" << endl;
   cout << "4. Hitung nilai rata-rata" << endl;
   cout << "Pilih menu: ";
   cin >> menu;

   switch(menu) {
    case 1: {
        tampilkanArray(arrA, sizeof(arrA) / sizeof(arrA[0]));
    }
    case 2: {
        cariMaksimum(arrA, sizeof(arrA) / sizeof(arrA[0]));
    }
    case 3: {
        cariMinimum(arrA, sizeof(arrA) / sizeof(arrA[0]));
    }
    case 4: {
        hitungRataRata(arrA, sizeof(arrA) / sizeof(arrA[0]));
    }
   }
}