#!/bin/sh
cd /home/woutco/Solar-Tracker/Stationary/Raspberry_Pi/
rfcomm release 0
rfcomm bind hci0 98:DA:60:00:CA:98
timeout 2h python index.py
