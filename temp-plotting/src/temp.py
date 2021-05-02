import matplotlib.pyplot as plt
import numpy as np
import serial
from drawnow import *

tempArray = []
humArray = []

count = 0

arduinoSerialData = serial.Serial("/dev/ttyUSB0", 9600)
plt.ion()

def makeFig():
    plt.ylim(0, 100)
    plt.grid(True)
    plt.title("Live Streaming Sensor Data")
    plt.xlabel("Time")
    plt.ylabel("Value")
    plt.plot(tempArray, "r-o", label = "Temperature")
    plt.plot(humArray, "b-o", label = "Humidity")
    plt.legend()

try:
    while True:
        if arduinoSerialData.in_waiting > 0:
            data = arduinoSerialData.readline().decode("utf-8")
            dataArray = data.split(" , ")
            temp = float(dataArray[0])
            hum = float(dataArray[1])
            tempArray.append(temp)
            humArray.append(hum)
            drawnow(makeFig)
            plt.pause(.0000001)
            count += 1
            if count > 50:
                tempArray.pop(0)
                humArray.pop(0)

except KeyboardInterrupt:
    pass
