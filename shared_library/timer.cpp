#include "timer.h"
#include <stdio.h>

void Timer::start() {
    gettimeofday(&mStart, NULL);
}
void Timer::stop() {
    gettimeofday(&mStop, NULL);
}

long Timer::get() {
    long seconds  = mStop.tv_sec  - mStart.tv_sec;
    long useconds = mStop.tv_usec - mStart.tv_usec;

    return seconds * 1000 + useconds / 1000.0;
}



