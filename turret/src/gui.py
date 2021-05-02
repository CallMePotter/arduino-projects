from time import sleep
import tkinter as tk
import serial

arduino_serial_data = serial.Serial("/dev/ttyACM0", 9600)


class Application(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.pack()


def motion(event):
    x, y = event.x, event.y

    arduino_serial_data.write(bytes("X" + str(x) + "Y" + str(y), encoding="ascii"))
    sleep(.025)

root = tk.Tk()
app = Application(master=root)
app.master.title("Turret")
app.master.config(bg = "black")
app.master.geometry("1920x1080")
app.master.resizable(False, False)
app.master.bind("<Motion>", motion)
app.mainloop()
