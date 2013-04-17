#include <iostream>

class A{};

A bar(A a) {
    std::cout << "b ";
    return a;
}


namespace detail {
template <typename T, int N>  
class Vector {
  T array[N];
public :
  template <typename F> void  apply          (F f);
  template <>           void  apply <A (*)(A)> (A(*f)(A));
};
}

template <typename T, int N>
template <typename F>
void    Vector<T, N>::apply(F function)
{
  for (int i(0); i < N; ++i) array[i] = function(array[i]);
   std::cout << std::endl;
}

template <typename T, int N>
template <>
void    Vector<T, N>::<A (*)(A)>(A (*f)(A)) {
    
    std::cout << "specialization"<< std::endl;
  for (int i(0); i < N; ++i) array[i] = function(array[i]);
   std::cout << std::endl;
}



A foo(A a) {
    std::cout << "f ";
    return a;
}



int main (void) {
    
    Vector<A, 100> v;
    v.apply(foo);
}
