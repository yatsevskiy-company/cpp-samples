#!/usr/bin/env bash

${NDK_HOME}/toolchains/arm-linux-androideabi-4.6/prebuilt/linux-x86/bin/arm-linux-androideabi-gdb \
    -ex "file app_process" \
    -ex "target remote :5055" \
    -ex "set solib-search-path ./native/obj/local/armeabi:./MyThread/obj/local/armeabi"