#include<iostream>
#include<string>

using namespace std; // Both iostream and string is part of std: Standard Library

int main(){
    string something; // Declaration of string type variable.

    cout << "Write something!" << endl;
    cin >> something;
    cout << "You have written that " << something << endl;
}