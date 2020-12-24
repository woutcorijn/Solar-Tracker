import serial #module for reading serial data.
from flask import Flask, render_template #webserver module.
from apscheduler.schedulers.background import BackgroundScheduler
import xlwt #write to excel sheet
from xlwt import Workbook
from datetime import datetime

data = "Waiting for data..."
wb = Workbook()
sheet1 = wb.add_sheet('Sheet1')
rcell = 0
time = datetime.now()
timeFormat = time.strftime("%m/%d/%Y, %H:%M:%S")

#Open the Serial Port
ser = serial.Serial('/dev/rfcomm0', 9600)

#get Arduino data
def getData():
	global rcell, data
	data = ser.readline()
	print(data)
	if data != "Waiting for data...":
		sheet1.write(rcell, 0, timeFormat)
		sheet1.write(rcell, 1, data)
		rcell += 1
		wb.save('data.xls')

scheduler = BackgroundScheduler()
scheduler.add_job(getData, 'interval', seconds=1)
scheduler.start()

#webserver
app = Flask(__name__)

@app.route('/')
def main():
	dataSend = data + "V"
	return render_template("index.html", data=dataSend)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=80)
