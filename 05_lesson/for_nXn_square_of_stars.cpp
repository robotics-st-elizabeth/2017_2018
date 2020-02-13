#include<iostream>

using namespace std;

int main(){
    int side;
    // int i, j;

    cout << "I write you stars in a square. What side length would you like?" << endl;
    cin >> side;

    // for(i=1; i<=num_stars; i++){
    // for(int i=1; i<=side; i++){
    for(int i=0; i<side; i++){
        // for(j=1; j<=side; j++){
        // for(int j=1; j<=side; j++){
        for(int j=0; j<side; j++){
            cout << "*";
        }
        cout << endl;
    }

    cout << endl << "Here you are! Now you have a square of " << side << " side length!" << endl << endl;

    return 0;
}