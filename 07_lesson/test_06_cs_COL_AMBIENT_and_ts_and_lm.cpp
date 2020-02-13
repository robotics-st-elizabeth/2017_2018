#include"ev3dev/ev3dev.h"
#include<iostream>

#include<chrono>
#include<thread>

using namespace std;
using namespace ev3dev;

int main(){
    //  #################################################################################
    //  # Example 6: EV3 color sensor in COL-AMBIENT mode, touch sensor and large motor #
    //  #################################################################################
    
    color_sensor cl(INPUT_1);
    touch_sensor ts(INPUT_4);

    large_motor m(OUTPUT_B);

    cerr << "cl.connected(): " << cl.connected() << endl;
    cerr << "ts.connected(): " << ts.connected() << endl;
    cerr << "m.connected(): " << m.connected() << endl;

    cl.set_mode("COL-AMBIENT");

    m.set_speed_sp(0);
    m.run_forever();

    while( !ts.is_pressed() ){
        m.set_speed_sp( cl.value() * 10 );
        m.run_forever();
        cerr << cl.value() << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    sound::beep();
}