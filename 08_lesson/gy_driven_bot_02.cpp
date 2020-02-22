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
    gyro_sensor gy_steering(INPUT_3);
    gyro_sensor gy_speed(INPUT_2);
    motor m_left(OUTPUT_B);
    motor m_right(OUTPUT_C);

    cerr << "ts.connected(): " << ts.connected() << endl;
    cerr << "gy_steering.connected(): " << gy_steering.connected() << endl;
    cerr << "gy_speed.connected(): " << gy_speed.connected() << endl;
    cerr << "m_left.connected(): " << m_left.connected() << endl;
    cerr << "m_right.connected(): " << m_right.connected() << endl;

    cerr << "Done. Starting process.\n";

    int steering(0), angle_steering(0), angle_steering_offset(0);
    int steering_factor = 2;
    int steering_max = 300;

    int speed_sp(0), angle_speed(0), angle_speed_offset;
    int speed_sp_left(0), speed_sp_right(0);
    int speed_factor = 2;
    int speed_max = 300;

    angle_steering_offset = gy_steering.value();
    angle_speed_offset = gy_speed.value();

    while ( !ts.is_pressed() ){
        // cerr << gy_steering.value() << " " << gy_speed.value() << endl;

        angle_steering = gy_steering.value() - angle_steering_offset;
        angle_speed = gy_speed.value() - angle_speed_offset;

        // steering = angle_steering * steering_factor;
        // steering = max(steering, -steering_max);
        // steering = min(steering, steering_max);
        steering = limit_speering(angle_steering * steering_factor, steering_max);

        // speed_sp = angle_speed * speed_factor;
        // speed_sp = max(speed_sp, -speed_max);
        // speed_sp = min(speed_sp, speed_max);
        speed_sp = limit_speering(angle_speed * speed_factor, speed_max);

        speed_sp_left = speed_sp - steering;
        speed_sp_right = speed_sp + steering;        

        m_left.set_speed_sp(speed_sp_left).run_forever();            
        m_right.set_speed_sp(speed_sp_right).run_forever();            
    }

    cerr << "Bye!\n";
    return 0;
}