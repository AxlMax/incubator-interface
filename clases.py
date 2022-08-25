from tkinter import *
from pythonSerial import *

class tablero:
    
    def __init__(self, master, config, inde) -> None:
        
        self.master = master
        self.config = config
        self.numbervar1 = IntVar()        
        self.delta = 0.3
        self.indentificator = inde
        
        self.letras()
        self.botones()
        
    def letras (self) -> None:
        
        buttonGridTemp, buttonGridTemp2, labelGridTemp, width, height = self.config
        
        label = Label(
            self.master,
            text = labelGridTemp["text"],
            font = labelGridTemp["font"],
        )
        
        font , numberSize = labelGridTemp["font"]
        
        self.number = Label(
            self.master,
            text = "5",
            font = (font, int(numberSize + 50*self.delta)),
        )
        
        number2 = Label(
            self.master,
            textvariable = self.numbervar1,
            font         = (font, int(numberSize + 50*self.delta)),
        )
        
        label.place(
            x = labelGridTemp["width"]*width, 
            y = labelGridTemp["height"]*height
        )
        
        self.number.place(
            x = labelGridTemp["width"]*width + 25, 
            y = labelGridTemp["height"]*height + 50
        )
        
        number2.place(
            x = labelGridTemp["width"]*width + 25, 
            y = labelGridTemp["height"]*height + 100
        )
          
    def botones(self) -> None:
        
        def buttonCallBackplus():
                self.numbervar1.set(self.numbervar1.get() + 1)
                writeSerial(self.indentificator)
                
        def buttonCallBackless():
                self.numbervar1.set(self.numbervar1.get() - 1)
                writeSerial(self.indentificator)
                
        buttonGridTemp, buttonGridTemp2, labelGridTemp, width, height = self.config
        
        B = Button(self.master, 
           text    = buttonGridTemp["text"], 
            height = int(buttonGridTemp2["hsize"]*width),
            width  = int(buttonGridTemp2["wsize"]*width),
           command = buttonCallBackplus)
        B.place(
            x = buttonGridTemp["width"]*width, 
            y = buttonGridTemp["height"]*height
        )

        B2 = Button(self.master, 
                text = buttonGridTemp2["text"], 
                height = int(buttonGridTemp2["hsize"]*width),
                width = int(buttonGridTemp2["wsize"]*width),
                command = buttonCallBackless)
        
        B2.place(
            x = buttonGridTemp2["width"]*width, 
            y = buttonGridTemp2["height"]*height
        )
    
    def getNumber(self) -> Label:
        return self.number
        
        