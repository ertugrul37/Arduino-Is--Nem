import serial
import time

COM_PORT = 'COM3'  
BAUD_RATE = 9600   

ser = serial.Serial(COM_PORT, BAUD_RATE, timeout=1)

try:
    while True:
        if ser.in_waiting > 0:
           
            line = ser.readline().decode('utf-8').rstrip()
            print(f'Gelen veri: {line}')
except KeyboardInterrupt:
    print("Dinleme durduruldu.")
finally:
    ser.close()  