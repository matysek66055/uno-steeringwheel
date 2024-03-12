import vgamepad as vg
import serial
import os

# Create a virtual joystick
gamepad = vg.VDS4Gamepad()

# Serial port configuration
ser = serial.Serial('COM2', 30000, timeout=1)  # Change 'COM2' to your Arduino port and update baud rate

# Initialize previous state variables
prev_x_value = 0.0
prev_brake_value = 0.0
prev_gas_value = 0.0

try:
    while True:
        ser.write(b'LED = 1\n')  # Send the command to turn off the LED
        # Read a line from the serial port
        serial_data = ser.readline().decode('utf-8').strip()

        # Check if the line starts with 'X:' to ensure it's a valid line
        if serial_data.startswith('X:'):
            # Extract numerical values from the string
            values = serial_data.split(',')
            try:
                # Parse values from the serial data
                x_value = float(values[0].split(':')[-1])
                brake_value = float(values[1].split(':')[-1])
                gas_value = float(values[2].split(':')[-1])
                button1_value = int(values[3].split(':')[-1])
                button2_value = int(values[4].split(':')[-1])
                button3_value = int(values[5].split(':')[-1])
                button4_value = int(values[6].split(':')[-1])
                button5_value = int(values[7].split(':')[-1])
                button6_value = int(values[8].split(':')[-1])
                button7_value = int(values[9].split(':')[-1])
                button8_value = int(values[10].split(':')[-1])

                # Print the received data
                print(f"X: {x_value}, Brake: {brake_value}, Gas: {gas_value}, "
                      f"Button1: {button1_value}, Button2: {button2_value}, "
                      f"Button3: {button3_value}, Button4: {button4_value}, "
                      f"Button5: {button5_value}, Button6: {button6_value}, "
                      f"Button7: {button7_value}, Button8: {button8_value}")

                # Update virtual joystick controls
                gamepad.left_trigger_float(value_float=brake_value)
                gamepad.right_trigger_float(value_float=gas_value)
                gamepad.left_joystick_float(x_value_float=x_value, y_value_float=0.0)

                # Handle button presses
                if button7_value == 1:
                    gamepad.press_button(vg.DS4_BUTTONS.DS4_BUTTON_SHOULDER_LEFT )
                else:
                    gamepad.release_button(vg.DS4_BUTTONS.DS4_BUTTON_SHOULDER_LEFT )

                if button8_value == 1:
                    gamepad.press_button(vg.DS4_BUTTONS.DS4_BUTTON_SQUARE)
                else:
                    gamepad.release_button(vg.DS4_BUTTONS.DS4_BUTTON_SQUARE)
                if button4_value == 1:
                    gamepad.press_button(vg.DS4_BUTTONS.DS4_BUTTON_CROSS )
                else:
                    gamepad.release_button(vg.DS4_BUTTONS.DS4_BUTTON_CROSS )
                gamepad.update()
                if button2_value == 1:
                    gamepad.press_button(vg.DS4_BUTTONS.DS4_BUTTON_CIRCLE  )
                else:
                    gamepad.release_button(vg.DS4_BUTTONS.DS4_BUTTON_CIRCLE  )
                gamepad.update()
                if button5_value == 1:
                    gamepad.press_button(vg.DS4_BUTTONS.DS4_BUTTON_TRIANGLE  )
                else:
                    gamepad.release_button(vg.DS4_BUTTONS.DS4_BUTTON_TRIANGLE  )
                gamepad.update()         
                if button3_value == 1:
                    gamepad.press_button(vg.DS4_BUTTONS.DS4_BUTTON_SHOULDER_RIGHT   )
                else:
                    gamepad.release_button(vg.DS4_BUTTONS.DS4_BUTTON_SHOULDER_RIGHT   )
                gamepad.update()
                if button1_value == 1:
                    gamepad.press_button(vg.DS4_BUTTONS.DS4_BUTTON_TRIGGER_LEFT   )
                else:
                    gamepad.release_button(vg.DS4_BUTTONS.DS4_BUTTON_TRIGGER_LEFT   )
                gamepad.update()  
                if button6_value == 1:
                    gamepad.press_button(vg.DS4_BUTTONS.DS4_BUTTON_TRIGGER_RIGHT   )
                else:
                    gamepad.release_button(vg.DS4_BUTTONS.DS4_BUTTON_TRIGGER_RIGHT   )
                gamepad.update()                                                    
                # Update previous state variables
                prev_x_value = x_value
                prev_brake_value = brake_value
                prev_gas_value = gas_value
            except ValueError as e:
                print(f"Error parsing values: {e}")

except KeyboardInterrupt:
    pass
finally:
    # Close the serial connection and release the virtual joystick when done
    ser.close()
    gamepad.reset()
    gamepad.update()
    print("Communication closed. The program has been terminated.")
    print("Discord: Matyas66055")
    print("Instagram: Matyas66055")
    print("https://inovation.tk/")
    print("Email: matysek66055@gmail.com")
