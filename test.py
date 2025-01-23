import serial 
import time 
import json

test_data = {}
arduino = serial.Serial(port='COM8', baudrate=115200, timeout=.1) 

def write_read(x): 
    arduino.flush()
    arduino.write(bytes(x, 'utf-8')) 
    time.sleep(0.5) 
    data = arduino.readline() 
    return data 

while True:
    value = write_read("Test") 
    print("Test1", value)
    test_data['Test1'] = value.decode('utf-8') 
    value = write_read("TEs")
    print("Test2", value)
    test_data['Test2'] = value.decode('utf-8') 
    if test_data['Test1'] and test_data['Test2']:
        break

if arduino:    
    arduino.close()
        
test_data = {"Tests" : test_data}
# Serializing json
json_object = json.dumps(test_data)
 
# Writing to sample.json
with open("build/results.json", "w") as outfile:
    outfile.write(json_object)
            