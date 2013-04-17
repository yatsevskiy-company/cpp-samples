#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H

#include <interface.h>

class implementation : public interface {
public:
    virtual ~implementation() {}

    virtual void a(int *arg);
    virtual void b(int *arg);
    virtual void c(int *arg);
    virtual void d(int *arg);
};


#endif
