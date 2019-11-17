// Arithmetic operators: +, -, *, /, %
// Integer variables
#include<iostream>

using namespace std;

int main(){
    int i;         // Declaration
    int j=17, k(5); // Declaration and initialization

    cout << "j = " << j << endl << "k = " << k << endl;

    i = j + k;
    cout << "j + k = " << i << endl;

    i = 23 - j + 5 * k;
    cout << "23 - j + 5 * k =  " << i << endl;

    i = j / k;
    cout << "j / k = " << i << endl;

    i = j % k;
    cout << "j % k = " << i << endl;

    return 0;
}