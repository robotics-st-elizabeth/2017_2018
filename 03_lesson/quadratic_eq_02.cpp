// Solution for quadratic equation.
#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double a, b, c;
    double x1, x2;
    double discriminant, divider, numerator1, numerator2;

    cout << "Let us solve a quadratic equation! \n Form of equation: a*x^2 + b*x + c\n";
    cout << "a = ?";
    cin >> a;
    
    cout << "b=?";
    cin >> b;

    cout << "c=?";
    cin >> c;
    cout << endl;

    discriminant = pow(b, 2) - 4 * a * c;
    divider = 2 * a * b;
    numerator1 = -b + sqrt(discriminant);
    numerator2 = -b - sqrt(discriminant);
    x1 = numerator1 / divider;
    x2 = numerator2 / divider;

    cout << "Equation: " << a << "*x^2 + " << b << "*x + " << c << endl;
    cout << "Discriminant: " << discriminant << endl;
    cout << "x1 = " << x1 << ", x2 = " << x2 << endl;

    return 0;
}
