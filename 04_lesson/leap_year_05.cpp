// Mastering logical expressions.
#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int year;

    cout << "What year are you curious about?" << endl;
    cin >> year;
    
    // if ( (year % 4 != 0) || (year % 100 == 0)  )
    if ( (year % 4 != 0) || (year % 100 == 0) && (year % 400 != 0) ){
        cout << "Year " << year << " is NOT leap year!" << endl;
    }
    if ( (year % 4 == 0) && (year % 100 != 0) || (year % 400 ==0 ) ) // A much more elegant solution is putting else here.
        cout << "Year " << year << " IS leap year!" << endl;
    
    return 0;
}