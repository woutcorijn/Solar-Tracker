import serial

ser = serial.Serial('/dev/rfcomm0', 9600)

print("Waiting for data...")

while True:
    result = ser.readline()
    print(result)
