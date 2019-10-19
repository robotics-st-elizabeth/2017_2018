#include<iostream>

using namespace std;

// Double variables
int main(){
    double x;             //Declaration
    double y=17.5, z(5.); //Declaration and initialization

    cout << "y = " << y << endl << "z = " << z << endl;
    x = y / z;
    cout << "y / z = " << x << endl;

    // x = y % z; // ERROR! Check error message!
    // cout << "y % z = " << x << endl;
}