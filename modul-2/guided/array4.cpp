#include <iostream>
using namespace std;

int main() {
    int data[2][2][2][2] = {
    {
        {
            {1, 2},
            {3, 4}
        },
        {
            {5, 6},
            {7, 8}
        },
    },
    {
        {
            {9, 10},
            {10, 11}
        },
        {
            {12, 13},
            {14, 15}
        }
    }
};
    
    cout << data[0][0][1][1] << endl;

    return 0;
}