#include"ev3dev/ev3dev.h"
#include<iostream>

#include<chrono>
#include<thread>

using namespace std;
using namespace ev3dev;

int main(){
    //  ##################################################################
    //  # Example 7: EV3 color sensor in COL-COLOR mode and touch sensor #
    //  ##################################################################
    
    color_sensor cl(INPUT_1);
    touch_sensor ts(INPUT_4);

    cerr << "cl.connected(): " << cl.connected() << endl;
    cerr << "ts.connected(): " << ts.connected() << endl;

    cl.set_mode("COL-COLOR");

    vector<string> colors = {"unknown", "black", "blue", "green", "yellow", "red", "white", "brown"};
    //colors.push_back("unknown");
    //colors.push_back("black");
    //colors.push_back("blue");
    //colors.push_back("green");
    //colors.push_back("yellow");
    //colors.push_back("red");
    //colors.push_back("white");
    //colors.push_back("brown");
    
    string color;

    while( !ts.is_pressed() ){
        color = colors[cl.value()];
        cerr << color << endl;
        sound::speak(color);  // .wait?
        // #Sound.speak(colors[cl.value()]).wait()
        this_thread::sleep_for(chrono::milliseconds(1500));
    }
    sound::beep();
}