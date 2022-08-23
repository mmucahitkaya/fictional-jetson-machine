import serial

with serial.Serial('/dev/ttyTHS1', 115200) as ser:
    while True:
        ser_bytes = ser.readline()
        print(str(ser_bytes))