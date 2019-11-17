# 3. óra

## Egyszerű matematikai függvények, cmath könyvtár

Az órán megismerkedünk a legalapvetőbb matematikai függvények használatával. A C++ nyelvben ezeket a `cmath` standard könyvtár be`include`olásával lehet elérni.

Az `sqrt` - SQuare RooT - függvény egyetlen argumentumot vár, vagyis ez egy egyváltozós függvény: `y = sqrt(x)`, vagyis `y`-nak értékként adjuk az `x` változó értékének négyzetgyökét.

A `pow` - power - függvény két argumentumot vár, vagyis ez egy kétváltozós függvény. Első argumentuma az alap, második argumentuma a kitevő: `y = pow(x, n)`, vagyis `y`-nak értékként adjuk az `x` változó értékének `n`-edik hatványát. Az alábbi kód demonstrálja ezek használatát.

A `cmath` könyvtár további függvényei találhatóak meg [ezen a linken](http://www.cplusplus.com/reference/cmath/).

```c++
// math_expressions.cpp
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
```

Fontos észrevenni, hogy a PI értékét a fő függvényen kívül létrehozott konstansban (const double) tároljuk.

## Másodfokú egyenlet megoldása

A `quadratic_eq_01.cpp` kód tartalmazza a másodfokú egyenlet megoldásának egyik lehetséges módját. Itt a lényegi számítás két sorba tömörül:

```c++
x1 = ( -b + sqrt( pow(b, 2) - 4 * a * c ) ) / 2 / a;
x2 = ( -b - sqrt( pow(b, 2) - 4 * a * c ) ) / (2 * a);
```

Fontos észrevenni, hogy a zárójelezéssel tehető egyértelművé a műveletek hierarchiája. Különösen a nevező számításánál szokott az a hiba felbukkani, hogy a "per 2a" műveletet így szerepeltetik a kódban: `/ 2a`, vagy `/ 2*a`. Helyesen ezt kétféleképpen kódolhatjuk: `/ 2 / a`, vagy `/ (2 * a)`.

A `quadratic_eq_02.cpp` egy sokkal átláthatóbb megoldást ad:

```c++
discriminant = pow(b, 2) - 4 * a * c;
divider = 2 * a * b;
numerator1 = -b + sqrt(discriminant);
numerator2 = -b - sqrt(discriminant);
x1 = numerator1 / divider;
x2 = numerator2 / divider;

```

Természetesen a fenti kódok nem kezelik azt az esetet, amikor nincs valós megoldás. Ilyenkor a kiíratott eredménynél azt látjuk, hogy `x1` és `x2 = -nan`. A `-nan` a `Not A Number` akronimja. A nem valós megoldások kezelését a következő alkalommal tanuljuk meg.
