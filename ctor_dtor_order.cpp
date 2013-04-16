#include<iostream>

struct A1 {
    A1() {
        std::cout << "A1 ctor" << std::endl;
    }

    virtual~A1() {
        std::cout << "A1 dtor" << std::endl;
    }
};

struct A2: A1 {
    A2() {
        std::cout << "A2 ctor" << std::endl;
    }
    virtual~A2() {
        std::cout << "A2 dtor" << std::endl;
    }
};

struct A3: A2 {
    A3() {
        std::cout << "A3 ctor" << std::endl;
    }
    virtual~A3() {
        std::cout << "A3 dtor" << std::endl;
    }
};

struct B1 {
    B1() {
        std::cout << "B1 ctor" << std::endl;
    }
    ~B1() {
        std::cout << "B1 dtor" << std::endl;
    }
};

struct B2: B1 {
    B2() {
        std::cout << "B2 ctor" << std::endl;
    }
    ~B2() {
        std::cout << "B2 dtor" << std::endl;
    }
};

struct B3: B2 {
    B3() {
        std::cout << "B3 ctor" << std::endl;
    }
    ~B3() {
        std::cout << "B3 dtor" << std::endl;
    }
};


int main()
{
    A1 *a = new A3;
    delete a;

    std::cout << "--" << std::endl;

    B1 *b = new B3;
    delete b;
    std::cout << "--" << std::endl;

    B3 *b2 = new B3;
    delete b2;
    std::cout << "--" << std::endl;
}

