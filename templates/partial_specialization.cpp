#include <iostream>
//using namespace std;

template<typename T, typename U, int I> struct X {
    void f() {
        std::cout << "Primary template" << std::endl;
    }
};

template<typename T, int I> struct X<T, T *, I> {
    void f() {
        std::cout << "Partial specialization 1" << std::endl;
    }
};

template<typename T, typename U, int I> struct X<T *, U, I> {
    void f() {
        std::cout << "Partial specialization 2" << std::endl;
    }
};

template<typename T> struct X<int, T *, 10> {
    void f() {
        std::cout << "Partial specialization 3" << std::endl;
    }
};

template<typename T, typename U, int I> struct X<T, U *, I> {
    void f() {
        std::cout << "Partial specialization 4" << std::endl;
    }
};

int main() {
    X<int, int, 10> a;
    X<int, int *, 5> b;
    X<int *, float, 10> c;
    X<int, char *, 10> d;
    X<float, int *, 10> e;
    //   X<int, int*, 10> f;
    a.f();
    b.f();
    c.f();
    d.f();
    e.f();
}
