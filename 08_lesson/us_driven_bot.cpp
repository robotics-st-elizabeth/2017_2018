#include"ev3dev/ev3dev.h"
#include<iostream>

#include<cmath>
// #include<chrono>
// #include<thread>

using namespace std;
using namespace ev3dev;

int main(){

    cerr << "Initializing...\n";

    touch_sensor ts(INPUT_4);
    ultrasonic_sensor us(INPUT_3);
    motor m_left(OUTPUT_B);
    motor m_right(OUTPUT_C);

    cerr << "ts.connected(): " << ts.connected() << endl;
    cerr << "us.connected(): " << us.connected() << endl;
    cerr << "m_left.connected(): " << m_left.connected() << endl;
    cerr << "m_right.connected(): " << m_right.connected() << endl;
    
    us.set_mode("US-DIST-CM");

    cerr << "Done. Starting process.\n";

    int distance(0), speed_sp(0);
    int ref_dist = 300;
    int speed_factor = 2;
    int speed_max = 300;

    while ( !ts.is_pressed() ){
        distance = us.value();
        // cerr << distance << endl;
        speed_sp = (ref_dist - distance) * speed_factor;
        speed_sp = max(speed_sp, -speed_max);
        speed_sp = min(speed_sp, speed_max);

        m_left.set_speed_sp(speed_sp).run_forever();            
        m_right.set_speed_sp(speed_sp).run_forever();            
    }

    cerr << "Bye!\n";
    return 0;
}