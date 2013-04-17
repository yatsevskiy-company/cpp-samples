LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE      := OpenGlSurface
LOCAL_SRC_FILES   := src/OpenGlSurface.c jni/OpenGlSurfaceWrapper.c
LOCAL_LDLIBS      := -llog -lGLESv2

include $(BUILD_SHARED_LIBRARY)