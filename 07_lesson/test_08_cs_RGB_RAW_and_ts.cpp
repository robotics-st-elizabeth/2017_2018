#include"ev3dev/ev3dev.h"
#include<iostream>

#include<chrono>
#include<thread>

using namespace std;
using namespace ev3dev;

int main(){
    //  ################################################################
    //  # Example 8: EV3 color sensor in RGB-RAW mode and touch sensor #
    //  ################################################################

    color_sensor cl(INPUT_1);
    touch_sensor ts(INPUT_4);

    cerr << "cl.connected(): " << cl.connected() << endl;
    cerr << "ts.connected(): " << ts.connected() << endl;

    cl.set_mode("RGB-RAW");
    
    int red, green, blue;

    while( !ts.value() ){
        red = cl.value(0);
        green = cl.value(1);
        blue = cl.value(2);

        cerr << "red: " << red << "; green: " << green << "; blue: " << blue << endl;

        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    sound::beep();
}