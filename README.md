# Arduino Pick and Place Robotic Arm 
Designed and programmed (in C++) a pick and place robot using an Arduino, sensors, circuits, and reverse engineered a Mindstorms NXT kit using an Oscilloscope

<p align="center">
  <img width="700" img src="for_readme/robot_project_pic_1.jpg">
</p>

# Motivation
This was for a Mechatronics project. Me and my partner could create anything, we weren't allowed to use most of the built in functions in the Arduino IDE so we could learn how to write code that will work directly with microprocessors. We ambitiously chose to Design and program (in C++) a pick and place robot using an Arduino, sensors, circuits, and reverse engineered a Mindstorms NXT kit using an Oscilloscope 

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


# 3. Train
Takes the train.record, test.record, train images, the config file, the pbtxt file, the model and saves checkpoints in a folder in training. One of these checkpoints will be chosen to create the inference graph. 

Don't forget to change the num_examples to the number of images in the images/train folder.
```
num_examples: 972	# num of training images in the images/train folder after generating the images
```

# 4. Tensorboard
Click on the _4_tensorboard.py file to open tensorboard and visualize the data. Look at the Total loss.

<p align="center">
  <img width="700" img src="results/images_for_readme/graph_tensorboard2.JPG">
</p>



# Results

<p align="center">
  <img width="700" img src="for_readme/mindstorms_pic.jpg">
</p>

# Outlook

For further questions please refer to my LinkedIn profile or contact us here on GitHub. 

# List of Refrences
[1]
