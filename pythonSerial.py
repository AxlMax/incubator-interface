import time
import serial, time, json, os
from dotenv import load_dotenv

load_dotenv()

conn = serial.Serial(
    port          = os.getenv('PORT') , 
    baudrate      = os.getenv("FREQ"), 
    timeout       = 1, 
    write_timeout = 1
)
      
def getValues():
    
    conn.write('getValue'.encode('utf-8'))
    try:
        raw_string_b = conn.readline()
        raw_string_s = raw_string_b.decode('utf-8')
        
        if(raw_string_s.index("}")>=0 and raw_string_s.index("{")==0):
            
            raw_string_s = raw_string_s[0:raw_string_s.index("}")+1]
            
            raw_string_j = json.loads(raw_string_s)
                        
            return raw_string_j
            
        else:
            print("error/ no } found.")
    except:
        print("Exception occurred, somthing wrong...")
    
def writeSerial(value):
    conn.write(str(value).encode('utf8'))