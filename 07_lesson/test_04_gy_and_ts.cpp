#include"ev3dev/ev3dev.h"
#include<iostream>

#include<chrono>
#include<thread>

using namespace std;
using namespace ev3dev;

int main(){
    //  ############################################
    //  # Example 4 (gyro sensor and touch sensor) #
    //  ############################################
    
    int angle(0), angle_offset(0);
    gyro_sensor gy(INPUT_3);
    touch_sensor ts(INPUT_4);
    motor m(OUTPUT_B);

    cerr << "ts.connected(): " << ts.connected() << endl;
    cerr << "gy.connected(): " << gy.connected() << endl;
    cerr << "m.connected(): " << m.connected() << endl;

    gy.set_mode("GYRO-ANG");

    angle_offset = gy.value();
    while ( !ts.is_pressed() ){
        angle = gy.value() - angle_offset;
        cerr << angle << " ";
        sound::tone({{float(angle) * 10 + 10, 1000, 0.0f}}, true);
    }
}