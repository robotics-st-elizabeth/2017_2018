#include<iostream>

using namespace std;

int main(){
    int num_stars;
    // int i;

    cout << "How many stars would you like?" << endl;
    cin >> num_stars;

    // for(i=1; i<=num_stars; i++){
    // for(int i=1; i<=num_stars; i++){ // i is local for the cycle body.
    for(int i=0; i<num_stars; i++){ // C++-ish style: starting from 0.
        cout << "*";
    }
    cout << endl << "Here you are! Now you have " << num_stars << " stars!" << endl << endl;

    return 0;
}