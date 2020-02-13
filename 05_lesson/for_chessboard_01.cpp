#include<iostream>

using namespace std;

int main(){
    int side;

    cout << "I make you a chessboard of stars. What side length would you like?" << endl;
    cin >> side;


    for(int i=0; i<side/2; i++){
        for(int j=0; j<side/2; j++){
            cout << " *";
        }
        cout << endl;
        for(int j=0; j<side/2; j++){
            cout << "* ";
        }
        cout << endl;
    }
    

    cout << endl << "Here you are! Now you have a chessboard of " << side << " side length!" << endl << endl;

    return 0;
}