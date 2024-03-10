import vgamepad as vg
import serial
import os

# Create a virtual joystick
gamepad = vg.VDS4Gamepad()

# Serial port configuration
ser = serial.Serial('COM2', 22500, timeout=1)  # Change 'COM2' to your Arduino port and update baud rate

# Initialize previous state variables
prev_x_value = 0.0
prev_brake_value = 0.0
prev_gas_value = 0.0

try:
    while True:
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
 
                # Print the received data
                print(f"X: {x_value}, Brake: {brake_value}, Gas: {gas_value}")

                # Update virtual joystick controls
                gamepad.left_trigger_float(value_float=brake_value)
                gamepad.right_trigger_float(value_float=gas_value)
                gamepad.left_joystick_float(x_value_float=x_value, y_value_float=0.0)
                gamepad.right_joystick_float(x_value_float=-1.0, y_value_float=-1.0)

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
