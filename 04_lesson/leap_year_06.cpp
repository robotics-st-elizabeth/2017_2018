// Mastering logical expressions.
#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int year;
    // bool isLeapYear;
    cout << boolalpha;

    cout << "What year are you curious about?" << endl;
    cin >> year;
    
    // isLeapYear = ! ( (year % 4 != 0) || (year % 100 == 0) && (year % 400 != 0) );
    // cout << "Is year " << year << " a leap year? Answer: " << isLeapYear << endl;

    cout << "Is year " << year << " a leap year? Answer: " 
        << ! ( (year % 4 != 0) || (year % 100 == 0) && (year % 400 != 0) ) << endl;

    return 0;
}