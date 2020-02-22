#include"ev3dev/ev3dev.h"
#include<iostream>

#include<cmath>

using namespace std;
using namespace ev3dev;

int limit_speering(int speering, int speering_max){
    speering = max(speering, -speering_max);
    speering = min(speering, speering_max);

    return speering;
}

int main(){

    cerr << "Initializing...\n";

    touch_sensor ts(INPUT_4);
    gyro_sensor gy(INPUT_3);
    motor m_left(OUTPUT_B);
    motor m_right(OUTPUT_C);

    cerr << "ts.connected(): " << ts.connected() << endl;
    cerr << "gy.connected(): " << gy.connected() << endl;
    cerr << "m_left.connected(): " << m_left.connected() << endl;
    cerr << "m_right.connected(): " << m_right.connected() << endl;

    cerr << "Done. Starting process.\n";

    int angle(0), angle_offset(0), steering(0);
    int speed_sp_left(0), speed_sp_right(0);
    int steering_factor = 2;
    int steering_max = 300;

    int speed_factor = 2;
    int speed_max = 300;

    angle_offset = gy.value();

    while ( !ts.is_pressed() ){
        angle = gy.value() - angle_offset;
        // cerr << angle << endl;

        // steering = angle * steering_factor;
        // steering = max(steering, -steering_max);
        // steering = min(steering, steering_max);
        steering = limit_speering(angle * steering_factor, steering_max);

        speed_sp_left = steering;
        speed_sp_right = - steering;

        m_left.set_speed_sp(speed_sp_left).run_forever();            
        m_right.set_speed_sp(speed_sp_right).run_forever();            
    }

    cerr << "Bye!\n";
    return 0;
}