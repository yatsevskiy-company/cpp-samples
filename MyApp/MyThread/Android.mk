LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES  := $(LOCAL_PATH)/include
LOCAL_MODULE      := MyThread
LOCAL_SRC_FILES   := src/MyThread.cpp jni/MyThreadWrapper.cpp
LOCAL_CFLAGS      := -fpermissive -frtti
LOCAL_LDLIBS      := -llog

include $(BUILD_SHARED_LIBRARY)