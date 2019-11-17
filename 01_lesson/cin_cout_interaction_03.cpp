#include<iostream>
#include<string>

using namespace std;

int main(){
    string something; // Declaration of string type variable.
    int int_number; // Declaration of integer number.

    cout << "Write something!" << endl;
    cin >> something;
    cout << "Thanks! And now, tell me a number!" << endl;
    cin >> int_number;
    cout << "You have written that " << something << ", and then you typed in number " << int_number << endl;
    // Now, we can understand what "stream" means in "iostream".

    return 0;
}