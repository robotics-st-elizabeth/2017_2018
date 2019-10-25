# Első oktatási blokk

## Ismerkedés a Visual Studio Codedal

A részletek szóban. Tömören a legfontosabbak:

- VSC: Visual Studio Code.
    - A projektkönyvtárban kell, hogy legyen egy `".vscode"` és egy `ev3dev` könyvtár, amelyeket a `/home/code/work/project_template` könyvtárból másoltunk be. A `project_template` könyvtár a virtuális gép létrehozásakor már eleve felkerült.
    - `File -> Open Folder...`: Itt lehet projekt könyvtárat megadni. A projektkönyvtárnak ezt írjuk elő: `/home/code/work/<hallgató vezetékneve>_<hallgató keresztneve>/cpp_lessons/<01, 02, 03, stb>_lesson/`. Ez például egy helyes projektkönyvtár: `/home/code/work/gipsz_jakab/cpp_lessons/01_lesson/`.
    - Bal oldalon felül a fájl ikonnal nyitható `Explorer` fájl manager lesz az egyik legyakrabban használt felület. `Ctrl + Shift + E` kombinációval is elérhető.
    - Másik nagyon gyakran használt felület a `Debug` manager. Bal oldalon a bogár ikon megnyomásával, vagy a `Ctrl + Shift + D` kombinációval érhető el.
    - Gyakran használjuk még majd a `TERMINAL` ablakot, ami alul található.
- Kód buildelése és futtatása.
    - A kódot tartalmazó fájl létrehozása: Az `Explorer`ben a projektkönyvtár gyökerében jobb egérgombbal klikkelünk, és kiválasztjuk, hogy `New File`. Ekkor megadhatjuk a fájl nevét.
    - A VSC a `*.cpp` kiterjesztésű fájlokat tekinti `C++` kódnak. Egy megfelelő fájlnév lehet például ez: `hello_world.cpp`.
    - Az elkészült kódot a `Ctrl + Shift + B` kombinációval tudjuk megbuildelni. (Vagy felül a menüben: `Terminal -> Run Build Task...`.)
    - A billentyűkombináció lenyomása után legördül egy ablak, amiben Válaszd ki a `g++ build debug executable` taskot.
    - Az elkészült futtatható állományt a `Debug` managerben tudjuk elindítani. Felül a kis zöld play gomb (`Start Debugging`)  melletti legördülőben állítsuk be a `C++: Debug Executable` launch modeot, majd nyomjuk meg a zöld play gombot. Fontos, hogy a kód (`*.cpp` fájl) legyen az aktívan editált fájl, ugyanis a debugger azt a futtatható állományt fogja futtatni, aminek azonos a neve a `*.cpp` kódot tartalmazó fájllal.


## Hello World!

Ismerkedjünk meg a klasszikus első programmal, ami terminálban üdvözöl minket!

```c++
/* hello_world_01.cpp */
#include<iostream>

int main(){
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```

- Az `#include` azt jelenti, hogy mások által már alaposan megírt eszközöket tartalmazó kódot illesztesz a programodba. Az előfordító dolga, hogy ezeket beillessze a buildelés során. Ha jobb gombbal ráklikkelsz az `<iostream>` szövegrészre, és a legördülőben kiválasztod, hogy `Go to Definition`, akkor a VSC fel fogja dobni az `iostream` úgynevezett header fájlját. Erről később beszélünk részletesebben.
- Az `int main(){}` egy speciális függvény. Az `int` a visszatérési érték típusa - jelen esetben `integer`, vagyis egész szám. A `main` az a függvény neve, jelen esetben ez azt jelenti, hogy a fő függvényről van szó, amiből minden `C++` programban kell lennie egynek és maximum egynek. A zárójel: `()` az argumentumlistát tartalmazza, ez jelenleg üres. Vagyis mindenféle bemenet nélkül hívódik meg a `main` függvény. A kapcsos zárójelben: `{}` található a `main` függvény által végrehajtandó utasítások sorozata, vagyis a programtörzs.
- A `return 0;` sor azt jelenti, hogy miután a főprogramunk lefutott, 0 értékkel tér vissza. Ez a konvenciók szerint azt jelenti, hogy minden rendben volt. Tipikusan különböző negatív egész visszatérési értékekkel jelezzük a különféle programhibák miatti leállást.
- Az `std::cout` a legkezesebb output csatorna, amivel a terminálon keresztül tudunk kommunikálni a programmal. A `<<` operátort úgy a legegyszerűbb értelmezni, hogy a `cout` utáni operandusokat jobbról balra *eteti* a `cout`ba. A Jelen esetben először a `"Hello World!"` stringet, majd ezt követően az `std::endl` szimbólumot, ami a soremelést jelenti.
- A `cout` az `iostream` include `std`, vagyis standard eszköztárában található meg. Ha a kódban a `cout`ra klikkelsz jobb gombbal, és a `Go to Definition`t választod, akkor az `iostream`-en belül találod magad a `cout` deklarációjánál. Ezt a kódot egyelőre nem érthetjük meg. Azt viszont érdemes észrevenni, hogy az egész kód bele van ágyazva egy `namespace std _BLABLABLA{}` névtérbe (minden a kapcsos zárójelen belül van). Az `endl` az `ostream` includeban található, amiről megint csak úgy tudunk meggyőződni, ha jobb gombbal az `endl` szimbólumra klikkelünk, és aztán a `Go to Definition`ra. Mi ugyan nem includeáltuk be az `ostream` includeot, de az `iostream` include magában foglalja. Az `iostream`ról elmondottakkal azt akarjuk megmutatni, hogy amikor `C++` nyelven programozunk, akkor nagyon sok olyan eszközt használunk, amelyeket jellemzően szintén `C++` nyelven írtak meg, és ezek elérhetőek a különböző könyvtárakban (`library`kben).

Ezzel túl is jutottunk a kezdet igazán fájdalmas szakaszán. A fenti pontokban írtakat egyelőre nem érthetjük, csak tudomásul kell venni, hogy egy `C++` kódban vannak `include`álások, meg egy `int main(){}` fő függvény. A továbbiakban a programtörzsben fogunk tevékenykedni, és ezt már úgy fogjuk csinálni, hogy értjük is, amit csinálunk.

## Ismerkedés az `std` névtérrel

A `cout` és az `endl` egyaránt az `std` névtér részei, amit abból láthatunk, hogy az első kódban így szerepeltek: `std::cout`, illetve `std::endl`. Ha meg akarjuk kímélni magunkat attól, hogy mindig be kelljen gépelni a névteret (`std::`), akkor a fő függvény előtt meg kell adnunk ezt a sort: `using namespace std;` A kód ekkor így néz ki:

```c++
/* hello_world_02 */
#include<iostream>

using namespace std;

int main(){
    cout << "Hello World!" << endl;
    return 0;
}
```

Egy másik lehetőség, hogy külön megadjuk, hogy mit kívánunk az `std` névtérből natív módon használni:

```c++
/* hello_world_03.cpp */
##include<iostream>

using std::cout;
using std::endl;

int main(){
    cout << "Hello World!" << endl;
    return 0;
}
```

## Egy kis Linux

Miután a VSCvel megbuildeltük (`Ctrl + Shift + B`) a programot, az explorerben láthatjuk, hogy megjelent egy `hello_world.pc.dbg.out` nevű fájl. A terminálablakban megkeressük a projektkönyvtárat, és ott is megfuttatjuk. A felhasznált Linux utasítások:

- `ls`: list
- `ls -a`: list all (ekkor a hidden fileok és hidden directoryk is látszanak).
- `cd dir_name`: change directory.
- `cd ..`: Kilépés felfelé a directoryból.
- `cd<Enter>`: Vissza a `home`ba. Jelen esetben ez a `/home/code/`.
- `clear`: Terminál ablak kitakarítása.
- `./executabele_filename`: Futtatható állomány futtatása.

Fontos kényelmi eszközök:

- Utasítás beírásakor a `Tab` nyomogatásával kiegészíteni a könyvtár és fájlneveket.
- A felfelé nyíl nyomkodásával elő lehet varázsolni a korábbi utasításokat.

## Interakció terminálon keresztül, string, integer és double típusok, első találkozás a debuggerrel

```c++
/* cin_cout_interaction_04.cpp */
// Debugger is demonstrated with this code.
#include<iostream>
#include<string>

using namespace std;

int main(){
    string something; // Declaration of string type variable.
    int int_number; // Declaration of integer number.
    double float_number; // Declaration of floating point number.

    cout << "Write something!" << endl;
    cin >> something;
    cout << "Thanks! And now, tell me a ROUND number!" << endl;
    cin >> int_number;
    cout << "Great! Now tell me a non-round number!" << endl;
    cin >> float_number; 
    cout << "Your string is \"" << something << "\", your round number is " << int_number;
    cout << " and your floating point number is " << float_number << endl;
    // Now, we can understand what "stream" means in iostream.
}
```

A fenti kódban találkozunk a 3 leggyakrabban használt típussal. Fontos észben tartani, hogy az `int` (integer) és a `double` típusok alaptípusok, míg a `string` típus objektum, amit az `#include<string>` includeolással emeltünk be a kódba.

## Ismerkedés a GitHubbal

Az első alkalom végén mindenkivel csinálunk GitHub accountot, és feltöltjük az első órai anyagokat.