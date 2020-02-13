#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double r, absX;
    int x, y, originJ, originI;
    
    cout << "Give me the radius of the circle!" << endl;
    cin >> r;
    originJ = int(r);
    originI = int(r);

    for(int i=0; i <= 2 * int(r); i++){
        y = originI - i;
        absX = pow(r, 2.) - pow(y, 2.);
        absX = sqrt(absX);
        absX = round(absX);

        for(int j=0; j<originI-absX; j++)
            cout << "  ";
        
        cout << "[]";

       for(int j=-absX; j<absX; j++)
            cout << "  ";
        
        cout << "[]";
        cout << endl;

    }

    
    cout << endl << endl;
    return 0;
}