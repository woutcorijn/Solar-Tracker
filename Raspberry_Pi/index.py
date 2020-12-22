#module for reading serial data.
import serial
#webserver module.
from flask import Flask

#Open the Serial Port
#ser = serial.Serial('/dev/rfcomm0', 9600)

#get Arduino data
print("Waiting for data...")

#while True:
    #result = ser.readline()
    #print(result)

#webserver
app = Flask(__name__)

@app.route('/')
def hello():
    name = request.args.get("name", "World")
    return f'Hello, {escape(name)}!'
