#include <iostream>

template<typename T1>
struct Outer {
public:
    template<typename T2>
    struct Inner {
    public:
        template<typename T3>
        void f(T2, T3);
        void g(T2);
    };
};

template<typename T1>
template<typename T2>
template<typename T3>
void Outer<T1>::Inner<T2>::f(T2, T3) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
/*
template<>
template<typename T2>
template<typename T3>
void Outer<int>::Inner<T2>::f(T2, T3) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
*/
/*
template<typename T1>
template<>
template<typename T3>
void Outer<T1>::Inner<int>::f(int, T3) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
*/
template<>
template<>
template<typename T3>
void Outer<int>::Inner<int>::f(int, T3) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
/*
template<typename T1>
template<typename T2>
template<>
void Outer<T1>::Inner<T2>::f(T2, int) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
*/
/*
template<>
template<typename T2>
template<>
void Outer<>::Inner<T2>::f(T2, int) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
*/
/*
template<typename T1>
template<>
template<>
void Outer<T1>::Inner<int>::f(int, int) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
*/

template<>
template<>
template<>
void Outer<int>::Inner<int>::f(int, int) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}












template<typename T1>
template<typename T2>

void Outer<T1>::Inner<T2>::g(T2) {

    std::cout << "Template 2" <<   std::endl;
}

template<>
template<>

void Outer<int>::Inner<int>::g(int) {
    std::cout << "Template 3"   << std::endl;
}


// template<> template<typename T2> template<typename T3>
//    void Outer<char>::Inner<T2>::f(T2, T3) { std::cout << "Template 6" << std::endl; }

// template<typename T1> template<>
//    void Outer<T1>::Inner<float>::g(float) { std::cout << "Template 7" << std::endl; }

int main() {
    Outer<int>::Inner<int> a;
    Outer<char>::Inner<char> b;
    a.f(1, 2);
    a.f(3, 'x');
    a.g(3);
    b.f('x', 'y');
    b.g('z');
}
