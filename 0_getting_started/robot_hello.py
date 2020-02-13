#!/usr/bin/env python3

import sys
from time import sleep
import ev3dev.ev3 as ev3

m_left = ev3.LargeMotor('outB')
print('m_left.connected:', m_left.connected, file=sys.stderr)

m_right = ev3.LargeMotor('outC')
print('m_right.connected:', m_right.connected, file=sys.stderr)

ts = ev3.TouchSensor('in4')
print('ts.connected:', ts.connected, file=sys.stderr)

m_left.run_to_rel_pos(speed_sp=200, position_sp=100)
m_right.run_to_rel_pos(speed_sp=200, position_sp=-100)
m_left.wait_while('running')
m_right.wait_while('running')

m_left.run_to_rel_pos(speed_sp=200, position_sp=-100)
m_right.run_to_rel_pos(speed_sp=200, position_sp=100)
m_left.wait_while('running')
m_right.wait_while('running')

print('Nyomd meg a touch sensort!', file=sys.stderr)
ev3.Sound.speak('Give me a five!').wait()
ev3.Sound.speak('Push the push sensor!').wait()

while 0 == ts.value():
    sleep(0.1)

ev3.Sound.speak('Bye! See you soon!').wait()
print('Viszlat!', file=sys.stderr)