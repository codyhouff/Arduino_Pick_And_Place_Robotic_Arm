# Arduino Pick and Place Robotic Arm 
Designed and programmed (in C++) a pick and place robot using an Arduino, sensors, circuits, and reverse engineered a Mindstorms NXT kit using an Oscilloscope

<p align="center">
  <img width="700" img src="for_readme/robot_project_pic_1.jpg">
</p>

# Motivation
This was for a Mechatronics project. Me and my partner could create anything, we weren't allowed to use most of the built in functions in the Arduino IDE so we could learn how to write code that will work directly with microprocessors. We ambitiously chose to Design and program (in C++) a pick and place robot using an Arduino, sensors, circuits, and reverse engineer a Mindstorms NXT kit using an Oscilloscope 

# Table of Contents

1. Circuit
2. Mindstroms NXT
3. IR Range Sensor 
4. Results
 



# 1. Circuit
The main circuits we will use are H bridges, a multiplexer, an inverter, and an amplifier. The H bridges will be used to protect the Arduino. The multiplexer will be used to choose one of the three motors to send the pwm signals. The multiplexer inverted the signals so we had to also use an inverter to get the correct signals. We will have to hook up the circuit to a power supply to power the motors since they run on nine volts. 

<p align="center">
  <img width="400" img src="for_readme/robot_project_pic_4.png">
</p>

### Circuit Design

<p align="center">
  <img width="600" img src="for_readme/Motor_Driver_and_Interupt_Circuit.png">
</p>

# 2. Mindstroms NXT

We reversed engineered the Mindstorms NXT using an oscilloscope and made it work with an arduino.

<p align="center">
  <img width="400" img src="for_readme/mindstorms_pic.jpg">
</p>

### Motors
Reverse engineered and calibrated an NXT motor to work with the arduino.

<p align="center">
  <img width="200" img src="for_readme/nxt_motor1.jpg">
</p>

### Touch Sensors
Reverse engineered and calibrated an NXT touch sensor to work with the arduino.

<p align="center">
  <img width="200" img src="for_readme/NXT_Touch_sensor.png">
</p>

### (Optional) Light Sensor from NXT
Reverse engineered and calibrated an optional light sensor that can tell the color of the objects it is about to pick up.

<p align="center">
  <img width="200" img src="for_readme/NXT_light_sensor.png">
</p>


# 3. IR Range Sensor
Calibrated and used an IR Range Sensor to detect where each object is. The ATD h file handles this.

<p align="center">
  <img width="200" img src="for_readme/Infrared_Range_Sensor2.jpg">
</p>

# 4. Results

<p align="center">
  <img width="700" img src="for_readme/robot project_trim_Trim_smaller_min.gif">
</p>



For further questions please refer to my LinkedIn profile or contact me here on GitHub. 

