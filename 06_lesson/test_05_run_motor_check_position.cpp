#include<iostream>
#include "ev3dev/ev3dev.h"

#include<chrono>
#include<thread>

using namespace std;
using namespace ev3dev;

int main(){
    cerr << "Initializing...\n";

    motor m_left(OUTPUT_B); // Left motor object is instantiated.
    cerr << "m_left.connected(): " << m_left.connected() << endl; // Checking connection.

    cerr << "Starting test...\n";

    cerr << "position: " << m_left.position() << endl;

    // Running forward.
    m_left.set_speed_sp(400);
    m_left.set_position_sp(1000);
    m_left.run_to_rel_pos();

    while( m_left.state().count("running") )
        this_thread::sleep_for(chrono::milliseconds(10));

    cerr << "position: " << m_left.position() << endl;

    // Running backward.
    m_left.set_speed_sp(400);
    m_left.set_position_sp(-900);
    m_left.run_to_rel_pos();

    while( m_left.state().count("running") )
        this_thread::sleep_for(chrono::milliseconds(10));

    cerr << "position: " << m_left.position() << endl;

    cerr << "Test succesfully completed.";

    cerr << endl << endl;
    return 0;
}