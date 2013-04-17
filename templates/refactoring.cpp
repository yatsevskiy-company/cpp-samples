#include <string>
#include <iostream>
class A {
    std::string messageA;
public:
    /*
    A() : messageA() {
        std::cout << "classA, default constructor, " << messageA << std::endl;
    }
    */
    A(const std::string &messge) : messageA(messge) {
        std::cout << "classA, non-default constructor, " << messageA << std::endl;
    }
    A(const A &rhs) : messageA(rhs.messageA) {
        std::cout << "classA, copy constructor, " << messageA << std::endl;
    }
    A& operator=(const A &rhs) {
        std::cout << "classA, assignment operator, " << messageA << std::endl;
        if (this != &rhs) {
            messageA = rhs.messageA;
        }
        return *this;
    }
    ~A() {
        std::cout << "classA, destructor, " << messageA << std::endl;
    }
};

class B : virtual public A {
    std::string messageB;
public:
    B() : A("0x0B") , messageB() {
        std::cout << "classB, default constructor, " << messageB << std::endl;
    }
    B(const std::string &messge) : A("0x0B") , messageB(messge) {
        std::cout << "classB, non-default constructor, " << messageB << std::endl;
    }
    B(const B &rhs) : A("0x0B") , messageB(rhs.messageB) {
        std::cout << "classB, copy constructor, " << messageB << std::endl;
    }
    B& operator=(const B &rhs) {
        std::cout << "classB, assignment operator, " << messageB << std::endl;
        if (this != &rhs) {
            messageB = rhs.messageB;
        }
        return *this;
    }
    ~B() {
        std::cout << "classB, destructor, " << messageB << std::endl;
    }
};

class C : virtual public A {
    std::string messageC;
public:
    C() : A("0x0C") , messageC() {
        std::cout << "class C, default constructor, " << messageC << std::endl;
    }
    C(const std::string &messge) : A("0x0C") ,messageC(messge) {
        std::cout << "class C, non-default constructor, " << messageC << std::endl;
    }
    C(const C &rhs) : A("0x0C") , messageC(rhs.messageC) {
        std::cout << "class C, copy constructor, " << messageC << std::endl;
    }
    C& operator=(const C &rhs) {
        std::cout << "class C, assignment operator, " << messageC << std::endl;
        if (this != &rhs) {
            messageC = rhs.messageC;
        }
        return *this;
    }
    ~C() {
        std::cout << "class C, destructor, " << messageC << std::endl;
    }
};


class D : public B, public C {
    std::string messageD;
public:
    D() : A("0x0D") , messageD() {
        std::cout << "class D, default constructor, " << messageD << std::endl;
    }
    D(const std::string &messge) : A("0x0D") , messageD(messge) {
        std::cout << "class D, non-default constructor, " << messageD << std::endl;
    }
    D(const D &rhs) : A("0x0D") , messageD(rhs.messageD) {
        std::cout << "class D, copy constructor, " << messageD << std::endl;
    }
    D& operator=(const D &rhs) {
        std::cout << "class D, assignment operator, " << messageD << std::endl;
        if (this != &rhs) {
            messageD = rhs.messageD;
        }
        return *this;
    }
    ~D() {
        std::cout << "class D, destructor, " << messageD << std::endl;
    }
};


int main(int argc, char *argv[]) {
    D d;
    return 0;
}
