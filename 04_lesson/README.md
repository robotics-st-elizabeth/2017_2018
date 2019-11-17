# 4. óra

## Az if-else elágazás

A programstruktúra egyik legfontosabb alapeleme az elágazás. A `quadratic_eq_if_junction_01.cpp` programban látható az `if-else` elágazásra példa, ahol a programot elágaztatjuk aszerint, hogy a másodfokú egyenletnek vane-e valós megoldása:

```c++
if (discriminant >= 0){
    x1 = (-b + sqrt(discriminant) ) / 2 / a;
    x2 = (-b - sqrt(discriminant) ) / 2 / a;
    cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
}
// if (discriminant < 0){
else {
    cout << "There is no real solution!\n";
}
```

Az `if` elágazás szintaktikája és működése:
- `if (logikai kifejezés)`: Az `if` után szereplő zárójel tartalmazza azt a logikai kifejezést, aminek eredménye - `true`, vagy `false` - dönti el, hogy a program belép-e az if ágba.
- Ha a logikai kifejezés értéke `true`, akkor az `if` utáni programblokk (a `{}` kapcsos zárójelen belüli utasítások) kerül sorra. Ennek elvégzése után az `else` ágban lévő programblokkot a program átugorja.
- Ha a logikai kifejezés értéke `false`, akkor az `if` utáni programblokkot ugorja át a program, és az `else` utáni blokkot hajtja végre.

A `quadratic_eq_if_junction_02.cpp` programban már háromfelé ágaztatjuk a programot, külön esetként kezeljük, ha csak egy valós megoldás van. A példaprogramban ezt három darab `if`-fel oldottuk meg.

```c++
if (discriminant > 0){
    x1 = (-b + sqrt(discriminant) ) / 2 / a;
    x2 = (-b - sqrt(discriminant) ) / 2 / a;
    cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
}
if (discriminant == 0){
    // x1 = (-b + sqrt(discriminant) ) / 2 / a;
    x1 = -b / 2 / a;
    cout << "There is only one real solution." << endl << "x = " << x1 << endl;
}
if (discriminant < 0){
    cout << "There is no real solution!\n";
}

Ezt a megoldást nem tekintjük optimálisnak, mert:
- Nem hatékony, akkor is megvizsgálja az `if`-ek logikai feltételeit, ha már korábban bement egy ágba.
- Nem biztos, hogy a program mindig bemegy egy ágba és mindig csak egy ágba megy be. Kézenfekvő lehetőség, ha pl. az elő feltételnél a `>` operátor helyett `>=` szerepel véletlenül. Egy megfelelő megoldás látható a `quadratic_eq_if_junction_03.cpp` programban, ahol ugyanezt a feladatot egymásba ágyazott `if` - `else` párokkal oldottuk meg.

```c++
if (discriminant > 0){
    x1 = (-b + sqrt(discriminant) ) / 2 / a;
    x2 = (-b - sqrt(discriminant) ) / 2 / a;
    cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
}
else{
    if (discriminant == 0){
        x1 = -b / 2 / a;
        cout << "There is only one real solution." << endl << "x = " << x1 << endl;
    }
    else{
        cout << "There is no real solution!\n";
    }
}
```
## Az elseif, vagy elif szerkezet

Amennyiben akár az `if`, akár az `else` ág csak egy utasítást tartalmaz, akkor a kapcsos zárójelek elhagyhatóak. A fenti programrészlet ekkor így alakul:

```c++
if (discriminant > 0){
    x1 = (-b + sqrt(discriminant) ) / 2 / a;
    x2 = (-b - sqrt(discriminant) ) / 2 / a;
    cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
}
else  // {
    if (discriminant == 0){
        x1 = -b / 2 / a;
        cout << "There is only one real solution." << endl << "x = " << x1 << endl;
    }
    else // {
        cout << "There is no real solution!\n";
    // }
//}
```

Ez letisztázva így néz ki:

```c++
if (discriminant > 0){
    x1 = (-b + sqrt(discriminant) ) / 2 / a;
    x2 = (-b - sqrt(discriminant) ) / 2 / a;
    cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
}
else
    if (discriminant == 0){
        x1 = -b / 2 / a;
        cout << "There is only one real solution." << endl << "x = " << x1 << endl;
    }
    else
        cout << "There is no real solution!\n";
```

Ha itt a hierarchiában az `else-if` párt azonos szintre hozzuk, akkor jön létre a `quadratic_eq_if_junction_04.cpp` állományban szereplő megoldás:

```c++
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
}
```

## Gyakorló feladat

Írjon programot, amely bekér egy évszámot, és visszadja, hogy az adott év szökőév-e? Minden 4-gyel osztható évszám szökőév, kivéve, ha 100-zal is osztható. Amennyiben 400-zal is osztható, akkor az mégis szökőév.