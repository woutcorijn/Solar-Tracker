#!/bin/sh
cd /home/woutco/Solar-Tracker/Rotating/Raspberry_Pi/
rfcomm release 0
rfcomm bind hci0 20:16:06:15:63:62
timeout 2h python index.py
