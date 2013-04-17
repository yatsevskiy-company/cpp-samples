#include <iostream>

class Base {
public:
    Base() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        throw std::exception();
    }

    virtual ~Base() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

int main(int argc, char *argv[]) {
    try {
        Base b;
    } catch(const std::exception &e) {
        std::cout << "Exception message: " << e.what() << std::endl;
    }
    return 0;
}
