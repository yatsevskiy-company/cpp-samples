#ifndef TIMER_H
#define TIMER_H

#include <sys/time.h>

class Timer {
    struct timeval mStart, mStop;

public :
    void start();
    void stop();
    long get();
};
#endif
