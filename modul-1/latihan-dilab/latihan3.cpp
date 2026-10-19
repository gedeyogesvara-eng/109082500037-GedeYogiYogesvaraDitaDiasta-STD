#include <iostream>
using namespace std;

int main() {
    int w, x, y;
    float z;

    x = 7;
    y = 3;
    w = 1;

    z = (float) (x + y) / (y + w);
    cout << "z = " << z << endl;
    return 0;
}