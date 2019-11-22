#include<iostream>

using namespace std;

int main(){
    int year;

    cout << "What year are you curious about?" << endl;
    cin >> year;
    cout << "Year " << year;

    if ( year % 4 != 0 ){
        cout << " is NOT leap year!" << endl;
        return 0; // Very ugly solution! Using else branch is prefered.
    }
    if ( year % 400 == 0 ){
        cout << " IS leap year!" << endl;
        return 0;
    }
    if ( year % 100 == 0 ){
        cout << " is NOT leap year!" << endl;
        return 0;
    }
    cout << " IS leap year!" << endl;

    return 0;
}