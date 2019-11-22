// Defining function.
#include<iostream>

using namespace std;

bool functionIsLeapYear(const int inputYear)
{
    bool outputIsLeapYear;
    if ( inputYear % 4 != 0 ){
        outputIsLeapYear = false;
    }
    else if ( inputYear % 400 == 0 )
        outputIsLeapYear = true;
    else if ( inputYear % 100 == 0 )
        outputIsLeapYear = false;
    else
        outputIsLeapYear = true;
    
    return outputIsLeapYear;
}

int main(){
    int year;
    bool isLeapYear;

    cout << "What year are you curious about?" << endl;
    cin >> year;

    // isLeapYear = functionIsLeapYear( year);

    // if (isLeapYear)
    if (functionIsLeapYear( year))
        cout << "Year " << year << " IS leap year!" << endl;
    else
        cout << "Year " << year << " is NOT leap year!" << endl;
        
    return 0;
}