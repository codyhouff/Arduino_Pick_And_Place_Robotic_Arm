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
3. Train 
4. Tensorboard
5. Export inference graph
6. Run Model on Images in Jupyter Notebook
7. Run Model on Webcam 



# 1. Circuit
Generates artificial training images and a csv file that contains the bounding box location and the class of the object. Also Variance is added to each image, this is to make the model more robust and able to handle images with poor lighting or bad angles.

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
Calibrated an NXT motor to work with the arduino.

<p align="center">
  <img width="200" img src="for_readme/nxt_motor1.jpg">
</p>

### Touch Sensors
Calibrated an NXT touch sensor to work with the arduino.

<p align="center">
  <img width="200" img src="for_readme/NXT_Touch_sensor.png">
</p>

### (Optional) Light Sensor from NXT
Calibrated an optional light sensor that can tell the color of the objects it is about to pick up.

<p align="center">
  <img width="200" img src="for_readme/NXT_light_sensor.png">
</p>


# 3. IR Range Sensor
Used an IR Range Sensor to detect where each object is.

<p align="center">
  <img width="200" img src="for_readme/Infrared_Range_Sensor2.jpg">
</p>

# Results

<p align="center">
  <img width="700" img src="for_readme/robot project_trim_Trim_smaller_min.gif">
</p>

# Outlook

For further questions please refer to my LinkedIn profile or contact us here on GitHub. 

# List of Refrences
[1]
