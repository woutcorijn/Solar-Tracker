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

#Open the Serial Port
ser = serial.Serial('/dev/rfcomm0', 9600)

#get Arduino data
def getData():
	global rcell, data, dataArray
	data = ser.readline()
	dataArray = data.split("/")
	print(dataArray[0])
	print(dataArray[1])
	if data != "Waiting for data...":
		time = datetime.now()
		timeStamp = time.strftime("%d/%m/%Y, %H:%M:%S")
		sheet1.write(rcell, 0, timeStamp)
		for i in range(len(dataArray)):
			sheet1.write(rcell, i+1, dataArray[i])
		rcell += 1
		wb.save('data.xls')

scheduler = BackgroundScheduler()
scheduler.add_job(getData, 'interval', seconds=1)
scheduler.start()

#webserver
app = Flask(__name__)

@app.route('/')
def main():
	data1 = dataArray[0] + "V"
	data2 = dataArray[1]
	return render_template("index.html", data1=data1, data2=data2)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=80)
