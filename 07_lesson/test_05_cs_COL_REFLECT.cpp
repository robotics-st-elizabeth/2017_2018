#include"ev3dev/ev3dev.h"
#include<iostream>

#include<chrono>
#include<thread>

using namespace std;
using namespace ev3dev;

int main(){
    //  ###############################################
    //  # Example 5: Color sensor in COL-REFLECT mode #
    //  ###############################################
    
    color_sensor cl(INPUT_1);
    cerr << "cl.connected(): " << cl.connected() << endl;
    cl.set_mode("COL-REFLECT");

    while(true){
        cerr << cl.value() << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}