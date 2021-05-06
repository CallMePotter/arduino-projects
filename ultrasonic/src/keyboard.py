from time import sleep
from pynput.keyboard import Key, Controller
import serial

arduino_serial_data = serial.Serial("/dev/ttyUSB0", 9600, timeout = 3)
keyboard = Controller()

try:
    while True:
        if arduino_serial_data.in_waiting > 0:
            data = arduino_serial_data.readline().decode()
            data = [int(i) for i in data.split()]

            left = data[0]
            right = data[1]

            if left < 10 and right < 10:
                keyboard.press(" ")
                keyboard.release(" ")
            elif left < 10:
                keyboard.press(Key.left)
                keyboard.release(Key.left)
            elif right < 10:
                keyboard.press(Key.right)
                keyboard.release(Key.right)


except KeyboardInterrupt:
    print("End of the program")
    quit()
