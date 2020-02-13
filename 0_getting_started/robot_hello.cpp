#include "ev3dev/ev3dev.h"
#include <iostream>
#include <chrono>
#include <thread>


using namespace std;
using namespace ev3dev;

int main()
{
    motor m_left(OUTPUT_B);
    cerr << "m_left.connected(): " << m_left.connected() << endl;

    motor m_right(OUTPUT_C);
    cerr << "m_right.connected(): " << m_right.connected() << endl;

    touch_sensor ts(INPUT_4);
    cerr << "ts.connected(): " << ts.connected() << endl;
    
    m_left. set_position_sp(100).set_speed_sp(200).run_to_rel_pos();
    m_right. set_position_sp(-100).set_speed_sp(200).run_to_rel_pos();
    while (m_left.state().count("running") || m_right.state().count("running"))
        this_thread::sleep_for(chrono::milliseconds(10));
    m_left. set_position_sp(-100).set_speed_sp(200).run_to_rel_pos();
    m_right. set_position_sp(100).set_speed_sp(200).run_to_rel_pos();
    while (m_left.state().count("running") || m_right.state().count("running"))
        this_thread::sleep_for(chrono::milliseconds(10));

    cerr << "Nyomd meg a touch sensort!" << endl;
    sound::speak("Give me a five!", true);
    sound::speak("Push the push sensor!", true);

    while(0 == ts.value()){
        this_thread::sleep_for(chrono::milliseconds(10));
    }

    sound::speak("Bye! See you soon!", true);
    cerr << "Viszlat!" << endl;
}