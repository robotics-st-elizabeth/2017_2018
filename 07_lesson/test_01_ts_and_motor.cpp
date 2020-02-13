#include"ev3dev/ev3dev.h"
#include<iostream>

#include<chrono>
#include<thread>

using namespace std;
using namespace ev3dev;

int main(){
    //  ####################################
    //  # Example 1 (touch sensor & motor) #
    //  ####################################
    
    touch_sensor ts(INPUT_4);
    cerr << "ts.connected(): " << ts.connected() << endl;
    
    large_motor m(OUTPUT_B);
    cerr << "m.connected(): " << m.connected() << endl;

    m.set_position_sp(400);
    m.set_speed_sp(400);
    m.run_to_rel_pos();
    
    while ( m.state().count("running") )
        this_thread::sleep_for(chrono::milliseconds(10));

    while ( !ts.is_pressed() )
        this_thread::sleep_for(chrono::milliseconds(10));
    
    cerr << "Bye!" << endl;

}