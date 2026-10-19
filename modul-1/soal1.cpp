#include <iostream>
using namespace std;

int main() {
    float a, b;
    cout << "Masukkan 2 bilangan : ";
    cin >> a >> b;

    cout << "Hasil penjumlahan " << a << " + " << b << " = " << a + b << endl;
    cout << "Hasil pengurangan " << a << " - " << b << " = " << a - b << endl;
    cout << "Hasil perkalian " << a << " x " << b << " = " << a * b << endl;
    cout << "Hasil pembagian " << a << " : " << b << " = " << a / b << endl;

    return 0;
}
