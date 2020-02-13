#include<iostream>
#include "ev3dev/ev3dev.h"

#include<chrono>
#include<thread>

#include<string>

using namespace std;
using namespace ev3dev;

int main(){    
    cerr << "Initializing...\n";

    motor m_left(OUTPUT_B); // Left motor object is instantiated.
    cerr << "m_left.connected(): " << m_left.connected() << endl; // Checking connection.
    motor m_right(OUTPUT_C); // Right motor object is instantiated.
    
    cerr << "m_right.connected(): " << m_right.connected() << endl; // Checking connection.

    cerr << "Starting test...\n";

    // cerr << "m_left.position(): " << m_left.position() << endl;

    while(true){
        if( m_left.position() > m_right.position() ){
            m_left.set_speed_sp(-100);
            m_left.run_forever();
        }
        else if (m_left.position() < m_right.position()){
            m_left.set_speed_sp(100);
            m_left.run_forever();
        }
        else{
            m_left.set_speed_sp(0);
            m_left.run_forever();
        }

    }

    cerr << "Test succesfully completed.";

    cerr << endl << endl;
    return 0;
}