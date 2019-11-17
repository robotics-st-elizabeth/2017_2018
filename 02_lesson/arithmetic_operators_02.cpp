// Double variables
// Assignment, leftvalue, rightvalue
#include<iostream>

using namespace std;

int main(){
    double x;             // Declaration
    double y=17.5, z(5.); // Declaration and initialization

    cout << "y = " << y << endl << "z = " << z << endl;
    x = y / z;
    cout << "y / z = " << x << endl;

    // x = y % z; // ERROR! Check error message!
    // cout << "y % z = " << x << endl;

    cout << "x = " << x << endl;
    x = x + 1; // Seems to be paradox. 
    // First, right hand side is calculated and then the result is assigned to left-hand-side variable.
    cout << "x = x + 1; \nAnd then x = " << x << endl;

    return 0;
}