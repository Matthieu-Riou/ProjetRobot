import serial
import time

class Communication:
  
  def __init__(self):
    self.ser = serial.Serial('/dev/ttyACM0', 9600)    
    
  def arreter(self):
    self.ser.write(chr(0))
    
  def avancer(self):
    self.ser.write(chr(1)) 
    
  def reculer(self):
    self.ser.write(chr(2))
    
  def tourner(self, angle):
    self.ser.write(chr(3))
    self.ser.write(chr(angle))
    self.ser.read()
    
  def balayage(self):
    self.ser.write(chr(4))
    
    values = []
    while self.ser.in_waiting > 0:
      values.append(self.ser.read())
    
    print values
    
    return values
    
communication = Communication()
