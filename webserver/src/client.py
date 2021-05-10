import RPi.GPIO as GPIO
import socket

GPIO.setmode(GPIO.BOARD)

buzz_pin = 11

GPIO.setup(buzz_pin, GPIO.OUT)

HEADERSIZE = 10

host_name = "192.168.1.136"
port = 8000

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((host_name, port))

try:
    while True:
        full_msg = ""
        new_msg = True

        while True:
            msg = s.recv(16)
            if new_msg:
                msg_len = int(msg[:HEADERSIZE])
                new_msg = False

            full_msg += msg.decode("utf-8")

            if len(full_msg) - HEADERSIZE == msg_len:
                print(full_msg[HEADERSIZE:-1])
                if int(full_msg[HEADERSIZE:-1]) == 0:
                    GPIO.output(buzz_pin, GPIO.HIGH)
                else:
                    GPIO.output(buzz_pin, GPIO.LOW)
                new_msg = True
                full_msg = ""
except KeyboardInterrupt:
    GPIO.cleanup()
    quit()
