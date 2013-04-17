#ifndef MY_THREAD_H
#define MY_THREAD_H

#include <pthread.h>

namespace namespace1 {
namespace namespace2 {

class MyThread {

	pthread_t thread[3];
	pthread_attr_t attribute[3];

public:
	/*volatile*/
	bool quit;

	virtual void onPause();

	virtual void onResume();

	MyThread();

	virtual ~MyThread();
};

}
}
#endif
