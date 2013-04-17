#!/usr/bin/env bash

JNI_PACKAGE_NAME="com.samsung.myapp"
JNI_PACKAGE_DIR="src/com/samsung/myapp"

TARGET_NAME_LOCAL="OpenGlSurface"
SWIG_FILE="native/swig/${TARGET_NAME_LOCAL}.i"
JNI_FILE="native/jni/${TARGET_NAME_LOCAL}Wrapper.c"
swig -java -package ${JNI_PACKAGE_NAME} -outdir ${JNI_PACKAGE_DIR} -o ${JNI_FILE} ${SWIG_FILE}
$NDK_HOME/ndk-build NDK_DEBUG=1 NDK_PROJECT_PATH=./native NDK_APPLICATION_MK=./native/Application.mk APP_BUILD_SCRIPT=./native/Android.mk
cp ./native/obj/local/armeabi/libOpenGlSurface.so libs/armeabi/libOpenGlSurface.so




TARGET_NAME_LOCAL="MyThread"
SWIG_FILE="MyThread/swig/${TARGET_NAME_LOCAL}.i"
JNI_FILE="MyThread/jni/${TARGET_NAME_LOCAL}Wrapper.cpp"
INCLUDE_DIR="MyThread/include"
swig -c++ -java -I${INCLUDE_DIR} -package ${JNI_PACKAGE_NAME} -outdir ${JNI_PACKAGE_DIR} -o ${JNI_FILE} ${SWIG_FILE}
$NDK_HOME/ndk-build NDK_DEBUG=1 NDK_PROJECT_PATH=./MyThread NDK_APPLICATION_MK=./MyThread/Application.mk APP_BUILD_SCRIPT=./MyThread/Android.mk
cp ./MyThread/obj/local/armeabi/libMyThread.so libs/armeabi/libMyThread.so


ant all

adb push native/libs/armeabi/gdbserver /system/bin/gdbserver 
adb pull /system/bin/app_process app_process



PROCESS_NAME="com.samsung.myapp"
PORT_NUMBER=5055
PID=$(adb shell ps | grep ${PROCESS_NAME} | awk '{print $2}')
adb forward tcp:${PORT_NUMBER} tcp:${PORT_NUMBER}
adb shell gdbserver  :${PORT_NUMBER} --attach ${PID} &


sleep 3
clear

${NDK_HOME}/toolchains/arm-linux-androideabi-4.6/prebuilt/linux-x86/bin/arm-linux-androideabi-gdb \
    -ex "file app_process" \
    -ex "target remote :5055" \
    -ex "set solib-search-path ./native/obj/local/armeabi:./MyThread/obj/local/armeabi"




