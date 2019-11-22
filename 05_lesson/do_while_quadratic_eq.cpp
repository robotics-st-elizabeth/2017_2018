// Cycle: while <do>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(){
    double a, b, c;
    double x1, x2, discriminant;
    char ch='y'; // Char type, initialized.
    string str;

    do {
        cout << "Let us solve a quadratic equation! \nFormula for equation: a*x^2 + b*x + c\n";
        cout << "a = ?";
        cin >> a;    
        cout << "b=?";
        cin >> b;
        cout << "c=?";
        cin >> c;
        cout << "Equation: " << a << "*x^2 + " << b << "*x + " << c << endl;

        discriminant = pow(b, 2) - 4 * a * c;
        cout << "Discriminant: " << discriminant << endl;

        if (discriminant > 0){
            x1 = (-b + sqrt(discriminant) ) / 2 / a;
            x2 = (-b - sqrt(discriminant) ) / 2 / a;
            cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
        }
        else if (discriminant == 0){
            x1 = -b / 2 / a;
            cout << "There is only one real solution." << endl << "x = " << x1 << endl;
        }
        else
            cout << "There is no real solution!\n";

        // cout << "Wanna continue? (y/n)" << endl;
        // cin >> str;
        // ch = str[0];

        cout << "Wanna continue? ";
        do{
            cout << "(y/n)" << endl;
            cin >> str;
            ch = str[0];
        } while (ch != 'y' and ch != 'n');

    } while(ch != 'n');
    
    return 0;
}