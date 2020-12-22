#!/bin/sh
rfcomm release 0
rfcomm bind hci0 20:16:06:15:63:62
python index.py
