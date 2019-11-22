// Else if series.
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
    else if ( year % 400 == 0 )
        isLeapYear = true;
    else if ( year % 100 == 0 )
        isLeapYear = false;
    else // Without this else branch code misses year 4. There must be else branch, or initialization of isLeapYear!
        isLeapYear = true;
    

    if (isLeapYear)
        cout << "Year " << year << " IS leap year!" << endl;
    else
        cout << "Year " << year << " is NOT leap year!" << endl;
        
    return 0;
}