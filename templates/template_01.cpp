#include <iostream>
#include <typeinfo>

struct A {
  template <typename T> void f(T* t) {}
};

   
template<typename T> struct  B {
  template<typename U> void f(const U &u){}
};



template<typename T> struct C {

   template<typename U> void f(const U &u);
};

template<typename T> template <typename U> void C<T>::f(const U &u) {}


class Factory {
    A* create() {return 0;}
    //B<int>* create() {return 0;}
    //C* create() {return 0;}
};


template <typename U, typename T> class clazz {
public:
    void foo(T t) {
	std::cout << typeid(t).name() << std::endl;
    }
    
    void bar(U u) {}
};

template <typename U, typename T> class clazz<U, T *> {
public:
    void foo(T *t) {
      std::cout <<"T *t"<< typeid(t).name() << std::endl;
    }
};

template <typename U, typename T> class clazz<U, T &> {
public:
    void foo(T &t) {
      std::cout << typeid(t).name() << std::endl;
    }
};

template <typename U, typename T> class clazz<U, const T>  {
public:
    void foo(const T t) {
      std::cout << typeid(t).name() << std::endl;
    }
};

template <typename U, typename T> class clazz<U, const T *> {
public:
    void foo(const T *t) {
      std::cout << "const T *t" << typeid(t).name() << std::endl;
    }
};

template <typename U, typename T> class clazz<U, const T &> {
public:
    void foo(const T &t) {
      std::cout << typeid(t).name() << std::endl;
    }
};


template <typename U, typename T> class clazz<const U*, T> {
public:
    void foo(const T &t) {
      std::cout << typeid(t).name() << std::endl;
    }
};

class Object {
public:
  void set(int){}
  int get(){}
};








//template <typename Receiver, int (Receiver::*GETTER)(), void (Receiver::*SETTER)(int)> class Command<const Receiver *, GETTER, SETTER>{};



template <typename U> class clazz<U, bool> {
public:
    void foo(bool b) {
	std::cout << typeid(b).name() << std::endl;
    }
    
    void bar(U u) {}
};



struct Base {};
struct Derived : Base {};
struct Poly_Base {virtual void f(){}};
struct Poly_Derived: Poly_Base {};

class Shape1 {
  void set(int){}
  int get(){}};
class Shape2 {
  void set(int){}
  int get(){}
};
class Shape3 {
  void set(int){}
  int get(){}
};


class Factory {
  template <typename T> T * create() {}
  //template <typename T> void create(T* t) {}
  //template <typename T> void create(T* t) {}
};


template <typename T, int (T::*GETTER)(), void (T::*SETTER)(int)> class Command {
  Command() {
    
  }
  
  ~Command() {
    
  }
};


int main () {
  
  
  
  
  C<int> c;
  c.f(0.0);
  
  int i = 0;
  
  clazz<int, int> c1;
  clazz<int, int*> c2;
  clazz<int, int&> c3;
  clazz<int, const int> c4;
  clazz<int, const int*> c5;
  clazz<int, const int&> c6;
  
  clazz<int, Base*> c7;
  clazz<int, Derived*> c8;
  clazz<int, Poly_Base*> c9;
  clazz<int, Poly_Derived*> c10;
  
  
  
  c1.foo(i);
  c2.foo(&i);
  c3.foo(i);
  c4.foo(i);
  c5.foo(&i);
  c6.foo(i);

  
  
  
  
  c1.foo(100);
  //c2.foo(&100);
  //c3.foo(100);
  c4.foo(100);
  //c5.foo(&100);
  c6.foo(100);
  
  
  Derived d;
  Poly_Derived pd;
  c7.foo(&d);
  c8.foo(&d);
  c9.foo(&pd);
  c10.foo(&pd);


  
  
  // built-in types:
  //int i;
  int * pi;
  std::cout << "int is: " << typeid(int).name() << std::endl;
  std::cout << "  i is: " << typeid(i).name() << std::endl;
  std::cout << " pi is: " << typeid(pi).name() << std::endl;
  std::cout << "*pi is: " << typeid(*pi).name() << std::endl << std::endl;

  // non-polymorphic types:
  Derived derived;
  Base* pbase = &derived;
  std::cout << "derived is: " << typeid(derived).name() << std::endl;
  std::cout << " *pbase is: " << typeid(*pbase).name() << std::endl;
  //std::cout << boolalpha << "same type? "; 
  std::cout << ( typeid(derived)==typeid(*pbase) ) << std::endl << std::endl;

  // polymorphic types:
  Poly_Derived polyderived;
  Poly_Base* ppolybase = &polyderived;
  std::cout << "polyderived is: " << typeid(polyderived).name() << std::endl;
  std::cout << " *ppolybase is: " << typeid(*ppolybase).name() << std::endl;
  //std::cout << boolalpha << "same type? "; 
  std::cout << ( typeid(polyderived)==typeid(*ppolybase) ) << std::endl << std::endl;
  
  
}