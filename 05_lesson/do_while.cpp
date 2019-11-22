// Cycle: while <do>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(){

    /*int i = 0;
    do {
        cout << i << endl;
        i++;
    } while (i < 5);*/
    
    /*int i = 0;
    char ch='y';
    do {
        cout << i << "th cycle. Wanna continue? (y/n)" << endl;
        cin >> ch;
        i++;    
    } while (ch != 'n');*/

    /*int i = 0;
    char ch='y';
    do {
        cout << i << "th cycle. Wanna continue? (y/n)" << endl;
        do{
            cin >> ch;
        } while (ch != 'y' and ch != 'n');
        i++;    
    } while (ch != 'n');*/
    
    int i = 0;
    char ch='y';
    string str;
    do {
        cout << i << "th cycle. Wanna continue? (y/n)" << endl;
        cin >> str;
        ch = str[0];
        i++;    
    } while (ch != 'n');

    return 0;
}