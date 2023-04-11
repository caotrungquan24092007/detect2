import serial
import time
serialcomm = serial.Serial('COM4', 9600)
serialcomm.timeout = 1

while True:
    time.sleep(2)
    serialcomm.write(str.encode('1'))
    print("LED turned on")
    time.sleep(2)

