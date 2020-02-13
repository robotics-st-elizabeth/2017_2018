#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double r, dist, tolerance = 0.5;
    int x, y, originJ, originI;
    
    cout << "Give me the radius of the circle!" << endl;
    cin >> r;
    cout << "Give me the tolerance!" << endl;
    cin >> tolerance;
    originJ = int(r);
    originI = int(r);

    for(int i=-1; i <= 2 * int(r) + 1; i++){
        y = originI - i;
        for(int j=-1; j <= 2 * int(r) + 1; j++){
            x = j - originJ;
            dist = pow(double(x), 2.) + pow(double(y), 2.);
            dist = sqrt(dist);
            if (abs(dist - r) < tolerance){
                cout << "[]";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;

    }

    
    cout << endl << endl;
    return 0;
}