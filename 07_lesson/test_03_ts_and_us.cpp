#include"ev3dev/ev3dev.h"
#include<iostream>

#include<chrono>
#include<thread>

using namespace std;
using namespace ev3dev;

int main(){
    //  ########################################
    //  # Example 3 (touch sensor & US sensor) #
    //  ########################################
    
    touch_sensor ts(INPUT_4);
    ultrasonic_sensor us(INPUT_3);
    motor m(OUTPUT_B);

    cerr << "ts.connected(): " << ts.connected() << endl;
    cerr << "us.connected(): " << us.connected() << endl;
    cerr << "m.connected(): " << m.connected() << endl;
    
    us.set_mode("US-DIST-CM");

    while ( !ts.is_pressed() ){
        int distance = us.value() / 10;
        cerr << distance << endl;

        if ( distance<30 ){
            m.set_speed_sp(100).run_forever();
        }
        else {
            m.set_speed_sp(-100).run_forever();            
        }
    }
}