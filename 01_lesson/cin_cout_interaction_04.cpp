// Debugger is demonstrated with this code.
#include<iostream>
#include<string>

using namespace std;

int main(){
    string something; // Declaration of string type variable.
    int int_number; // Declaration of integer number.
    double float_number; // Declaration of floating point number.

    cout << "Write something!" << endl;
    cin >> something;
    cout << "Thanks! And now, tell me a ROUND number!" << endl;
    cin >> int_number;
    cout << "Great! Now tell me a non-round number!" << endl;
    cin >> float_number; 
    cout << "Your string is \"" << something << "\", your round number is " << int_number;
    cout << " and your floating point number is " << float_number << endl;
    // Now, we can understand what "stream" means in iostream.
}