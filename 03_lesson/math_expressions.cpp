// Mathematical functions and expressions.
// cmath functions: http://www.cplusplus.com/reference/cmath/
#include<iostream>
#include<cmath>

using namespace std;

const double PI = 3.14159265;

int main(){
    double x, y;
    double a, b, c;
    double V, D;

    cout << "Give me a number! I'm gonna extract the root of it." << endl;
    cin >> x;
    y = sqrt(x);
    cout << "sqrt(" << x << ") = " << y << endl;

    cout << "Give me a number. I'm gonna square it." << endl;
    cin >> x;
    y = pow(x, 2);
    cout << "sqr(" << x << ") = " << y << endl;

    cout << "Give me the length of the legs for a right-angled triangle!" << endl;
    cout << "a=?" << endl;
    cin >> a;
    cout << "b=?" << endl;
    cin >> b;
    c = sqrt(pow(a, 2) + pow(b, 2) );
    cout <<  "Length of hypotenuse: c = " << c << endl;

    cout << "Give me the volume of a cube!" << endl;
    cin >> V;
    a = pow(V, 1./3.);
    cout << "Side length of the cube: " << a << endl;

    cout << "Give me the diameter of a sphere!" << endl;
    cin >> D;
    V = PI / 6. * pow(D, 3.);
    cout << "Volume of the sphere is: " << V << endl;
    
    return 0;
}