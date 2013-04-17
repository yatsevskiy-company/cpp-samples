
#ifdef ANDROID 
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <android/log.h>
#endif


#ifndef ANDROID 
#include <GL/gl.h>
#include <GL/glext.h>
#endif


const static char * LOG_TAG = "OpenGlSurface";

void onSurfaceCreated() {
#ifdef ANDROID 
	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __PRETTY_FUNCTION__);
#endif
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}
void onSurfaceChanged(int width, int height) {
#ifdef ANDROID 
	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __PRETTY_FUNCTION__);
#endif
	glViewport(0, 0, width, height);
}
void onDrawFrame() {
#ifdef ANDROID 
	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __PRETTY_FUNCTION__);
#endif
	glClear(GL_COLOR_BUFFER_BIT);
}

