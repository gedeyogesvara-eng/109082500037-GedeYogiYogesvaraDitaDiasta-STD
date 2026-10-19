#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarIsiArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

int main() {
    int arrayA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int arrayB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int var1 = 100;
    int var2 = 999;
    int *ptr1 = &var1;
    int *ptr2 = &var2;

    cout << "Array A:" << endl;
    tampilArray(arrayA);
    cout << "Array B:" << endl;
    tampilArray(arrayB);

    cout << "Tukar isi array pada posisi (2,2):" << endl;
    tukarIsiArray(arrayA, arrayB, 2, 2);
    
    cout << "Array A setelah ditukar:" << endl;
    tampilArray(arrayA);
    cout << "Array B setelah ditukar:" << endl;
    tampilArray(arrayB);

    cout << "Tukar isi pointer:" << endl;
    cout << "Sebelum ditukar: *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;
    tukarPointer(ptr1, ptr2);
    
    cout << "Setelah ditukar: *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;

    return 0;
}