// Mathematical functions and expressions.
#include<iostream>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::pow;
using std::sqrt;


int main(){
    double a, b, c;
    double x1, x2, discriminant;

    cout << "Let us solve a quadratic equation! \n Form of equation: a*x^2 + b*x + c\n";
    cout << "a = ?";
    cin >> a;
    
    cout << "b=?";
    cin >> b;

    cout << "c=?";
    cin >> c;
    cout << endl;

    discriminant = pow(b, 2) - 4 * a * c;

    /*if (discriminant >= 0){
        x1 = (-b + sqrt(discriminant) ) / 2 / a;
        x2 = (-b - sqrt(discriminant) ) / 2 / a;

        cout << "Equation: " << a << "*x^2 + " << b << "*x + " << c << endl;
        cout << "Discriminant: " << discriminant << endl;
        cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else {
        cout << "There is no real solution!\n";
    }*/

    if (discriminant < 0)
        cout << "There is no real solution!\n";
    else{
        cout << "Equation: " << a << "*x^2 + " << b << "*x + " << c << endl;
        cout << "Discriminant: " << discriminant << endl;
        
        if (discriminant == 0){
            x1 = -b / 2 / a;
            cout << "There is only one real solution: x = " << x1 << endl;
        }
        else{
        x1 = (-b + sqrt(discriminant) ) / 2 / a;
        x2 = (-b - sqrt(discriminant) ) / 2 / a;

        cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
        }
    }    

}