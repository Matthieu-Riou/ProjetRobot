from communicationArduino import Communication

class Visio:
  
  def __init__(self, angleMin, angleMax):
    self.angleMin = angleMin
    self.angleMax = angleMax
    
    self.visio = [0]*((angleMax-angleMin)/5)
    
  def update(self):
    self.vision = communication.balayage()
    
    self.alertDistance()
    self.detectObjet()
      
  def alertDistance(self):
    print "ALERTE"
    
  def detectObjet(self):
    print "DETECTE"
