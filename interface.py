from distutils.command.config import config
from tkinter import *
from config import *
from clases import *
from pythonSerial import *

def refreshT():
    values = getValues()
    
    try:
        numberT.configure(text = int(values["temperatura"]))
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
    top.attributes('-fullscreen', True)

    top.geometry(f"{width}x{height}")

    configT = [buttonGridTemp, buttonGridTemp2, labelGridTemp, width, height]
    tableroT = tablero(top, configT, "T")
    
    numberT = tableroT.getNumber()
    refreshT()
    
    configH = [buttonGridHum, buttonGridHum2, labelGridHum, width, height]
    tableroH = tablero(top, configH,"H")
    
    numberH = tableroH.getNumber()
    refreshH()

    top.bind('<Escape>',lambda e: top.destroy())
    
    top.mainloop()