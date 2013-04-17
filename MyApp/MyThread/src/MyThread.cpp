#include <namespace1/namespace2/MyThread.h>

#ifdef ANDROID
#include <android/log.h>
#endif

#include <unistd.h>

namespace namespace1 {
namespace namespace2 {

const static char * LOG_TAG = "MyThread";

void pid() {
#ifdef ANDROID
	int id = gettid();
	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, "%d", id);
#endif
}

void* entry(void* data) {

	MyThread *self = static_cast<MyThread *>(data);

	while (!self->quit) {
		usleep(16666);
		pid();
	}

	return NULL;
}

void MyThread::onResume() {

#ifdef ANDROID
	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __PRETTY_FUNCTION__);
#endif
    pid();

	quit = false;
	for (int i = 0; i < 3; ++i) {
		pthread_attr_init(&attribute[i]);
		pthread_attr_setdetachstate(&attribute[i], PTHREAD_CREATE_JOINABLE);
		pthread_create(&thread[i], &attribute[i], &entry, this);
	}

}

    void MyThread::onPause() {
#ifdef ANDROID
	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __PRETTY_FUNCTION__);
#endif

	pid();

	quit = true;
	for (int i = 0; i < 3; ++i) {
		pthread_join(thread[i], NULL);
		pthread_attr_destroy(&attribute[i]);
	}
}

MyThread::MyThread() :
		quit(false) {
#ifdef ANDROID
	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __PRETTY_FUNCTION__);
#endif
}

MyThread::~MyThread() {
#ifdef ANDROID
	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __PRETTY_FUNCTION__);
#endif 
}
}
}

