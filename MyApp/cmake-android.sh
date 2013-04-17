#!/bin/sh 


DEBUG="1"
X86_64="1"

for param in $@
do
    if echo $param | grep -q -e "^clean$"
    then
        rm -rf build; mkdir build;
        echo "clean!"
    fi
done 

NDK_API="android14"
APP_ABI="armeabi"
CMAKE_BUILD_TYPE="debug"

CMAKE_TOOLCHAIN_FILE=${ANDROID_CMAKE_TOOLCHAIN}/toolchain/android.toolchain.cmake

(cd build && cmake .. \
    -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} \
    -DANDROID_NATIVE_API_LEVEL=$NDK_API \
    -DANDROID_ABI=$APP_ABI \
    -DCMAKE_BUILD_TYPE=$CMAKE_BUILD_TYPE && make -j 9)