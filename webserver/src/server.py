import socket
import time
import serial

serial_data = serial.Serial("/dev/ttyUSB0", timeout=5)

HEADERSIZE = 10

host_name = "0.0.0.0"
port = 8000

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((host_name, port))
s.listen(5)

while True:
    client_socket, address = s.accept()
    print(f"Connection from {address} has been established!")

    while True:
        if serial_data.in_waiting > 0:
            msg = serial_data.readline()
            msg = bytes(f"{len(msg):<{HEADERSIZE}}", "utf-8") + msg

            try:
                client_socket.send(msg)
            except:
                print(f"Connection from {address} has been closed!")
                client_socket.close()
                break
