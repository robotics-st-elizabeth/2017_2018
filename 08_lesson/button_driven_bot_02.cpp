#include<iostream>
#include "ev3dev/ev3dev.h"

#include<cmath>
#include<chrono>
#include<thread>

using namespace std;
using namespace ev3dev;

void sleep(int millsec){
    this_thread::sleep_for(chrono::milliseconds(millsec));
}

int change_speering(int speering, int speering_max, int speering_step){

    speering += speering_step;
    speering = max(speering, -speering_max);
    speering = min(speering, speering_max);

    return speering;
}

int main (){
    cerr << "Initializing...\n";

    motor m_left(OUTPUT_B);
    motor m_right(OUTPUT_C);
    cerr << "m_left.connected(): " << m_left.connected() << endl;
    cerr << "m_right.connected(): " << m_right.connected() << endl;

    cerr << "Done. Starting process.\n";

    bool esc(false), fwd(false), back(false), left(false), right(false), stop(false);
    int speed_left(0), speed_right(0), speed_sp(0), steering(0);
    int speed_max = 200, speed_step = 40, steering_max = 100, steering_step = 20;

    while (!esc){
        esc = button::back.pressed();
        stop = button::enter.pressed();
        fwd = button::up.pressed();
        back = button::down.pressed();
        left = button::left.pressed();
        right = button::right.pressed();
        
        if(stop){
            speed_sp = 0;
            steering = 0;
        }
        else if(fwd){
            // speed_sp += speed_step;
            // speed_sp = max(speed_sp, -speed_max);
            // speed_sp = min(speed_sp, speed_max);
            speed_sp = change_speering(speed_sp, speed_max, speed_step);
        }
        else if(back){
            // speed_sp -= speed_step;
            // speed_sp = max(speed_sp, -speed_max);
            // speed_sp = min(speed_sp, speed_max);
            speed_sp = change_speering(speed_sp, speed_max, -speed_step);
        }
        else if(left){
            // steering += steering_step;
            // steering = max(steering, -steering_max);
            // speed_sp = min(steering, steering_max);
            steering = change_speering(steering, steering_max, steering_step);
        }
        else if(right){
            // steering += steering_step;
            // steering = max(steering, -steering_max);
            // speed_sp = min(steering, steering_max);
            steering = change_speering(steering, steering_max, -steering_step);
        }

        if(fwd || back || left || right)
            // this_thread::sleep_for(chrono::milliseconds(300));
            sleep(300);

        speed_left = speed_sp + steering;
        speed_right = speed_sp - steering;

        m_left.set_speed_sp(speed_left).run_forever();
        m_right.set_speed_sp(speed_right).run_forever();
    }

    cerr << "Bye!\n";
    return 0;
}
