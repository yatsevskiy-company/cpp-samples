#include <iostream>

template<class T1> class Outer {
public:
   template<class T2> class Inner {
   public:
       template<class T3> void f(T2,T3);
       void g(T2);
       void log(const std::string &log) {
           std::cout << log << std::endl;
       }
   };
};

template<typename T1> template<typename T2> template<typename T3> void Outer<T1>::Inner<T2>::f(T2, T3) { log("Template 1"); }
//template<typename T1> template<typename T2> template<           > void Outer<T1>::Inner<T2>::f(T2, int) { log(__PRETTY_FUNCTION__); }
//template<typename T1> template<           > template<typename T3> void Outer<T1>::Inner<int>::f(int, T3) { log(__PRETTY_FUNCTION__); }
//template<typename T1> template<           > template<           > void Outer<T1>::Inner<int>::f(int, int) { log(__PRETTY_FUNCTION__); }
//template<           > template<typename T2> template<typename T3> void Outer<int>::Inner<T2>::f(T2, T3) { log(__PRETTY_FUNCTION__); }
//template<           > template<typename T2> template<           > void Outer<int>::Inner<T2>::f(T2, int) { log(__PRETTY_FUNCTION__); }
template<           > template<           > template<typename T3> void Outer<int>::Inner<int>::f(int, T3) { log("Template 4"); }
template<           > template<           > template<           > void Outer<int>::Inner<int>::f(int, int) { log("Template 5"); }

template<typename T1> template<typename T2> void Outer<T1>::Inner<T2>::g(T2) {log("Template 2");}
//template<typename T1> template<           > void Outer<T1>::Inner<int>::g(int) {log(__PRETTY_FUNCTION__);}
//template<           > template<typename T2> void Outer<int>::Inner<T2>::g(T2) {log(__PRETTY_FUNCTION__);}
template<           > template<           > void Outer<int>::Inner<int>::g(int) {log("Template 3");}


int main() {
   Outer<int>::Inner<int> a;
   Outer<char>::Inner<char> b;
   a.f(1, 2);
   a.f(3, 'x');
   a.g(3);
   b.f('x', 'y');
   b.g('z');
}