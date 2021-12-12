from tkinter import *
import operator
import serial
import tkinter as tk


Window = tk.Tk()
Window.title('')
Window.geometry('500x200')


def slider_Values(v):
   freqarray = list(range(109))
   frequency = 87.9
   freqcounter = 0
   while freqcounter < 101:
      freqarray = operator.add(frequency, .2)
      frequency = operator.add(frequency, .2)
      freqcounter = operator.add(freqcounter, 1)
      if freqcounter == int(v):
            Window.title(round(freqarray, 1))
            serialcom = serial.Serial('/dev/ttyUSB0', 9600)
            serialcom.write(bytes([int(v)]))
            print(round(freqarray, 1))


s = tk.Scale(Window, label='      Python FM Radio Tuner', from_=0, to=100, orient=tk.HORIZONTAL, length=200, showvalue=0, tickinterval=10, resolution=1, command=slider_Values)
s.pack()

mainloop()
