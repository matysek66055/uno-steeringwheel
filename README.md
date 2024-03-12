# uno-steeringwheel
Arduino Uno Steeringwheel with Python


Using python 3.12
Steerwheel 90C rotation

Arduino uno with A1-A3 pins
Just calculate your own potenciometers in (0 - 1023)
Enjoy playing.

I was repairing my old Genius steeringwheel SPEED WHEEL 3 :D So i make this program which using vgamepad, arduino uno with baud 30000 and A1-A3 pins, digital pins can be use for buttons 2-13




Location for the wheel.exe files: C:\wheel\ (originally a .bat program converted to .exe that automatically launches the Python script)

This program, originally a .bat file converted to .exe, is designed to automatically execute the Python script located in C:\wheel\. You can run the script directly in the console or create your own startup script. To customize, upload the .ino file with your specific values. Measure these values using analog sensors for minimum, maximum, and center points for the X-axis. Modify the mapping function accordingly. If you wish to add buttons, use digital pins, and transmit their states similarly to gas, brake, and X, but with values ranging from 0 to 1 (1 for the pressed state, 0 for the unpressed state).

Enjoy your gaming experience! Have a great time playing!
