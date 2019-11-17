// Solution for quadratic equation.
#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double a, b, c;
    double x1, x2;

    cout << "Let us solve a quadratic equation! \n Form of equation: a*x^2 + b*x + c\n";
    cout << "a = ?";
    cin >> a;
    
    cout << "b=?";
    cin >> b;

    cout << "c=?";
    cin >> c;
    cout << endl;

    x1 = ( -b + sqrt( pow(b, 2) - 4 * a * c ) ) / 2 / a;
    x2 = ( -b - sqrt( pow(b, 2) - 4 * a * c ) ) / (2 * a);

    cout << "Equation: " << a << "*x^2 + " << b << "*x + " << c << endl;
    cout << "x1 = " << x1 << ", x2 = " << x2 << endl;

    return 0;
}
