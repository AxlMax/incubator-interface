from distutils.command.config import config
from tkinter import *
from config import *
from clases import *
from pythonSerial import *

def refreshT():
    values = getValues()
    
    try:
        numberT.configure(text = values["temperatura"])
    except:
        print("error on refresh")
        
    top.after(1000, refreshT)

def refreshH():
    values = getValues()
    
    try:
        numberH.configure(text = values["humedad"])
    except:
        print("error on refresh")
        
    top.after(1000, refreshH)

if __name__ == "__main__":
    
    load_dotenv()

    top = Tk()

    top.title("incubatorVHM")

    top.geometry(f"{width}x{height}")

    configT = [buttonGridTemp, buttonGridTemp2, labelGridTemp, width, height]
    tableroT = tablero(top, configT)
    
    numberT = tableroT.getNumber()
    refreshT()
    
    configH = [buttonGridHum, buttonGridHum2, labelGridHum, width, height]
    tableroH = tablero(top, configH)
    
    numberH = tableroH.getNumber()
    refreshH()

    top.mainloop()