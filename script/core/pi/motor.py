import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600)
ser.write(str(unichr(1)))
