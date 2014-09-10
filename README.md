cycleChaser
===========

Here's the code for the CycleChaser Project, a *Make:* Magazine / RadioShack Weekend Project. For more information about what it does and how to make it, see here:

This code will only compile on a Raspberry Pi with openFrameworks and WiringPi installed.

openFrameworks on Raspberry Pi: http://www.openframeworks.cc/setup/raspberrypi/
WiringPi: http://wiringpi.com/

If you want to change the frames, move .png files into the bin/data directory. Update the #define at the top of ofApp.cpp with the number of frames in the folder.

Also note that the config.make file has been updated to link the WiringPi library to this project.
