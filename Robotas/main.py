#!/usr/bin/env pybricks-micropython
from pybricks.hubs import EV3Brick
from pybricks.ev3devices import (Motor, TouchSensor, ColorSensor,
                                 InfraredSensor, UltrasonicSensor, GyroSensor)
from pybricks.parameters import Port, Stop, Direction, Button, Color
from pybricks.tools import wait, StopWatch, DataLog
from pybricks.robotics import DriveBase
from pybricks.media.ev3dev import SoundFile, ImageFile


# This program requires LEGO EV3 MicroPython v2.0 or higher.
# Click "Open user guide" on the EV3 extension tab for more information.


# Create your objects here.
ev3 = EV3Brick()


left_motor = Motor(Port.A)
right_motor = Motor(Port.B)

ultrasonicSensor = UltrasonicSensor(Port.S4)
colorSensor = ColorSensor(Port.S1)

robot = DriveBase(left_motor, right_motor, wheel_diameter=56, axle_track=104)

# Write your program here.

while True:
    if colorSensor.reflection() > 13:
        if ultrasonicSensor.distance() > 300:
            robot.drive(5000,0)
        else:
            robot.turn(-210)
    else:
        robot.turn(-210)




ev3.speaker.beep()
