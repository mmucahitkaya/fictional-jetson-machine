import serial


 
with serial.Serial('/dev/ttyTHS1', 115200) as ser:
    while True:
        x = input()
        ser.write(bytes(x,'utf-8'))
