import serial #module for reading serial data.
from flask import Flask, render_template #webserver module.
from apscheduler.schedulers.background import BackgroundScheduler

data = "Waiting for data..."

#Open the Serial Port
ser = serial.Serial('/dev/rfcomm0', 9600)

#get Arduino data
def getData():
	global data
        data = ser.readline()
        print(data)

scheduler = BackgroundScheduler()
scheduler.add_job(getData, 'interval', seconds=1)
scheduler.start()

#webserver
app = Flask(__name__)

@app.route('/')
def main():
    return render_template("index.html", data=data)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=80)
