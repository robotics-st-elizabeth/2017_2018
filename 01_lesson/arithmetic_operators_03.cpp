#include<iostream>

using namespace std;

// Compound assignments : +=, -=
// Increment, decrement
int main(){
    int i(0);
    double x(0);

    cout << "i = " << i << endl << "x = " << x << endl;

    i += 2;
    cout << "i += 2 = " << i << endl;
    i += 4;
    cout << "i += 4 = " << i << endl;

    x -=2.5;
    cout << "x -= 2.5 = " << x << endl;
    x += 5;
    cout << "x += 5 = " << x << endl;

    i = 0;
    cout << "i = " << i << endl;
    i++;
    cout << "i++ = " << i << endl;
    i++;
    cout << "i++ = " << i << endl;
    i--;
    cout << "i-- = " << i << endl;
    i--;
    cout << "i-- = " << i << endl;
}