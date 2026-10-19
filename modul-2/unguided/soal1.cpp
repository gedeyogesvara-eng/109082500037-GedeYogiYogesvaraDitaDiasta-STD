#include <iostream>
using namespace std;

int main() {
    int matrikA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrikB[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    for (int i=0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            cout << "Hasil penjumlahan dari " << matrikA[i][j] << " dan " << matrikB[i][j] << " = " << matrikA[i][j] + matrikB[i][j] << endl;
        }
    }

    cout << endl;

    for (int k =0; k < 3; k++) {
        for (int l =0; l < 3; l++) {
            cout << "Hasil pengurangan dari " << matrikA[k][l] << " dan " << matrikB[k][l] << " = " << matrikA[k][l] -matrikB[k][l] << endl;
        }
    }

    cout << endl;

    for (int m = 0; m < 3; m++){
        for (int n = 0; n < 3; n++) {
            int hasil = 0;
            for (int o = 0; o < 3; o++) {
                hasil += matrikA[m][o] * matrikB[o][n];
            }
            cout << "Hasil perkalian dari baris " << m << " dan kolom " << n << " = " << hasil << endl;
        }
    }

    return 0;
}