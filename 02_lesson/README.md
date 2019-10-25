# Második  oktatási blokk

## Értékadás, operátorok

Az alábbi kód demonstrálja az egész számokon végezhető aritmetikai műveleteket.

```c++
/* arithmetic_operators_01.cpp */
// Arithmetic operators: +, -, *, /, %
// Integer variables
#include<iostream>

using namespace std;

int main(){
    int i;         // Declaration
    int j=17, k(5); // Declaration and initialization

    cout << "j = " << j << endl << "k = " << k << endl;

    i = j + k;
    cout << "j + k = " << i << endl;

    i = 23 - j + 5 * k;
    cout << "23 - j + 5 * k =  " << i << endl;

    i = j / k;
    cout << "j / k = " << i << endl;

    i = j % k;
    cout << "j % k = " << i << endl;
}
```

A futás eredménye pedig:

```c++
j = 17
k = 5
j + k = 22
23 - j + 5 * k =  31
j / k = 3
j % k = 2
```

Érdemes észrevenni, hogy integer változók esetében 17 / 5 = 3.

A következő kódban az osztást double változóval végezzük el:

```c++
/* arithmetic_operators_02.cpp */
// Double variables
// Assignment, leftvalue, rightvalue
#include<iostream>

using namespace std;

int main(){
    double x;             // Declaration
    double y=17.5, z(5.); // Declaration and initialization

    cout << "y = " << y << endl << "z = " << z << endl;
    x = y / z;
    cout << "y / z = " << x << endl;

    // x = y % z; // ERROR! Check error message!
    // cout << "y % z = " << x << endl;

    cout << "x = " << x << endl;
    x = x + 1; // Seems to be paradox. 
    // First, right hand side is calculated and then the result is assigned to left-hand-side variable.
    cout << "x = x + 1; \n And then x = " << x << endl;
}
```

A fenti kód legérdekesebb sora ez:

`x = x + 1;` 

Matematikai egyenletként a fenti sor értelmezhetetlen. A programozásban viszont az `=` egy operátor, ami a következőket csinálja:
- A jobb oldalon található kifejezés értékét kiszámolja.
- Az így kapott eredményt jobbértéknek, angolul `rightvalue`nak hívjuk.
- A bal oldalon szereplő változónak a `rightvalue` értékét átadja.

A kód futásának eredménye:

```c++
y = 17.5
z = 5
y / z = 3.5
x = 3.5
x = x + 1; 
And then x = 4.5
```

Az x = x +, -, *, / valami típusó értékadásokra vannak külön operátorok, amelyek működését az alábbi kód demonstrálja:

```c++
/* arithmetic_operators_03.cpp */
// Compound assignments: +=, -=
// Increment, decrement: ++, --
#include<iostream>

using namespace std;

int main(){
    int i(0);
    double x(0);

    cout << "i = " << i << endl << "x = " << x << endl;

    i += 2;
    cout << "i += 2 = " << i << endl;
    i -= 4;
    cout << "i -= 4 = " << i << endl;

    x -=2.5;
    cout << "x -= 2.5 = " << x << endl;
    x += 5;
    cout << "x += 5 = " << x << endl;

    x /= 0.5;
    cout << "x /= 0.5 = " << x << endl;
    x *= 2.;
    cout << "x *= 2.0 = " << x << endl;

    i = 0;
    cout << "i = " << i << endl;
    i++;
    cout << "i++ = " << i << endl;
    i++;
    cout << "i++ = " << i << endl;
    i--;
    cout << "i-- = " << i << endl;
    i--;
    cout << "i-- = " << i << endl;
}
```

A futás eredménye pedig:

```c++
i = 0
x = 0
i += 2 = 2
i -= 4 = -2
x -= 2.5 = -2.5
x += 5 = 2.5
x /= 0.5 = 5
x *= 2.0 = 10
i = 0
i++ = 1
i++ = 2
i-- = 1
i-- = 0
```

## Kifejezések, matematikai függvények

git bash reset global username

AskUbuntu git config global file - remove settings

git config --global --unset-all user.name

git config --list