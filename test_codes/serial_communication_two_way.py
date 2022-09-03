import serial
 
with serial.Serial('/dev/ttyTHS1', 115200) as ser:
    
    while True:
        x = input("servo angle: ")
        ser.write(bytes(x,'utf-8'))
        ser_bytes = ser.readline().decode('utf-8').rstrip()
        print(str(ser_bytes))