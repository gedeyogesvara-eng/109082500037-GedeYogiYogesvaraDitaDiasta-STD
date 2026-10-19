#include <iostream>
using namespace std;

int main() {
    int a;

    cout << "input : ";
    cin >> a;
    cout << endl;

    for (int i = a; i >= 1; i--) {
        for (int k = 1; k <= a - i; k++) {
            cout << "  ";
        }
        for (int j = i; j >= 1; j--) {
            cout << " " << j ;
        }
            for (int i = a; i <= a; i++) {
                  cout << " *";
        }
            for (int j = 1; j <= i; j++) {
            cout << " " << j ;
        }
        cout << endl;
    }
            for (int k = 1; k <= a ; k++) {
            cout << "  ";
        }
     cout << " *";
}
