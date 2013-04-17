#include <iostream>

class Base {
public:
    Base() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    virtual ~Base() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};


class Derived : public Base {
public:
    Derived() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        throw std::exception();
    }

    virtual ~Derived() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

int main(int argc, char *argv[]) {
    try {
        Base b;
        Derived d;
    } catch(const std::exception &e) {
        std::cout << "Exception message: " << e.what() << std::endl;
    }
    return 0;
}
