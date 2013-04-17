#include <implementation.h>

void implementation::a(int *arg) {
    *arg = 1;
}
void implementation::b(int *arg) {
    *arg = 2;
}
void implementation::c(int *arg) {
    *arg = 3;
}
void implementation::d(int *arg) {
    *arg = 4;
}


interface *interface::newInstance() {
    return new implementation;
}

void interface::release(interface *oldInstance) {
    delete oldInstance;
}
