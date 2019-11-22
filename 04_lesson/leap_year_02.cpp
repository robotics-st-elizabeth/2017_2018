// Demonstration of wrong behavior.
// Code leap_year_01.cpp was simply modified by removing return branches.
#include<iostream>

using namespace std;

int main(){
    int year;
    bool isLeapYear;

    cout << "What year are you curious about?" << endl;
    cin >> year;

    if ( year % 4 != 0 ){
        isLeapYear = false;
    }
    if ( year % 400 == 0 ){
        isLeapYear = true;
    }
    if ( year % 100 == 0 ){
        isLeapYear = false;
    }
    
    if (isLeapYear)
        cout << "Year " << year << " IS leap year!" << endl;
    if (!isLeapYear)
        cout << "Year " << year << " is NOT leap year!" << endl;
    
    return 0;
}