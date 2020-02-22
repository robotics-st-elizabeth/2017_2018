#include<iostream>
#include "ev3dev/ev3dev.h"

using namespace std;
using namespace ev3dev;

int main (){
    cerr << "Initializing...\n";

    motor m_left(OUTPUT_B);
    motor m_right(OUTPUT_C);
    cerr << "m_left.connected(): " << m_left.connected() << endl;
    cerr << "m_right.connected(): " << m_right.connected() << endl;

    cerr << "Done. Starting process.\n";

    bool esc(false), fwd(false), back(false), left(false), right(false), stop(false);
    int speed_left(0), speed_right(0);
    int speed_max = 100;

    while (!esc){
        esc = button::back.pressed();
        stop = button::enter.pressed();
        fwd = button::up.pressed();
        back = button::down.pressed();
        left = button::left.pressed();
        right = button::right.pressed();
        
        if(stop){
            speed_left = 0;
            speed_right = 0;
        }
        else if(fwd){
            speed_left = speed_max;
            speed_right = speed_max;
        }
        else if(back){
            speed_left = -speed_max;
            speed_right = -speed_max;
        }
        else if(left){
            speed_left = -speed_max;
            speed_right = speed_max;
        }
        else if(right){
            speed_left = speed_max;
            speed_right = -speed_max;
        }
        m_left.set_speed_sp(speed_left).run_forever();
        m_right.set_speed_sp(speed_right).run_forever();
    }
}
