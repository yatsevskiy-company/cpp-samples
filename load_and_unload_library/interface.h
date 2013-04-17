#ifndef INTERFACE_H
#define INTERFACE_H


class interface {
protected:
    interface() {}
    interface(const interface &rhs) {}
    virtual ~interface() {}

public:
    static interface *newInstance();
    static void release(interface *oldInstance);

    virtual void a(int *arg) = 0;
    virtual void b(int *arg) = 0;
    virtual void c(int *arg) = 0;
    virtual void d(int *arg) = 0;

};


#endif
