#!/usr/bin/env bash
PROCESS_NAME="com.samsung.myapp"
PORT_NUMBER=5055
PID=$(adb shell ps | grep ${PROCESS_NAME} | awk '{print $2}')
adb forward tcp:${PORT_NUMBER} tcp:${PORT_NUMBER}
adb shell gdbserver  :${PORT_NUMBER} --attach ${PID}