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

    m_left.set_speed_sp(400);
    m_left.set_time_sp(1000);
    m_left.run_timed();
    
    cerr << "run_timed started.\n";

    // while(true);
    //     cerr << m_left.state().count("running") << endl;

    this_thread::sleep_for(chrono::milliseconds(2000));

    cerr << "Test succesfully completed.";

    cerr << endl << endl;
    return 0;
}