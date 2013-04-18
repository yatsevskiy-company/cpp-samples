#include<iostream>

struct m {
    std::string s;
    m(const std::string &s): s(s) {
        std::cout << "m:ctor " << s << std::endl;
    }

    ~m() {
        std::cout << "m:dtor " << s << std::endl;
    }
};

struct V1 {
    m m0;
    m m1;
    m m2;
    m m3;
    std::string s;
    V1(const std::string &s): s(s), m0("V1:m0"), m1("V1:m1"), m2("V1:m2"), m3("V1:m3") {
        std::cout << "V1:ctor " << s << std::endl;
    }
    ~V1() {
        std::cout << "V1:dtor " << s << std::endl;
    }
};


struct A1: virtual V1 {
    m m0;
    m m1;
    m m2;
    m m3;
    A1(): V1("A1:V1"), m0("A1:m0"), m1("A1:m1"), m2("A1:m2"), m3("A1:m3") {
        std::cout << "A1:ctor " << std::endl;
    }
    ~A1() {
        std::cout << "A1:dtor " << std::endl;
    }
};

struct A2: A1 {
    m m0;
    m m1;
    m m2;
    m m3;
    A2(): V1("A2:V1"), m0("A2:m0"), m1("A2:m1"), m2("A2:m2"), m3("A2:m3") {
        std::cout << "A2:ctor " << std::endl;
    }
    ~A2() {
        std::cout << "A2:dtor " << std::endl;
    }
};


int main(int argc, char *argv[])
{
    A2 a2;
    return 0;
}
