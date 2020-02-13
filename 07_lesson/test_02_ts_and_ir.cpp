#include"ev3dev/ev3dev.h"
#include<iostream>

#include<chrono>
#include<thread>

using namespace std;
using namespace ev3dev;

int main(){
    //  ########################################
    //  # Example 2 (touch sensor & IR sensor) #
    //  ########################################

    touch_sensor ts(INPUT_4);
    infrared_sensor ir(INPUT_3);
    motor m(OUTPUT_B);

    cerr << "ts.connected(): " << ts.connected() << endl;
    cerr << "ir.connected(): " << ir.connected() << endl;
    cerr << "m.connected(): " << m.connected() << endl;
    
    ir.set_mode("IR-PROX");

    while ( !ts.is_pressed() ){
        int distance = ir.value();
        cerr << distance << endl;

        if ( distance<60 ){
            m.set_speed_sp(100).run_forever();
        }
        else {
            m.set_speed_sp(-100).run_forever();            
        }
    }
}