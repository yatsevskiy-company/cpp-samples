#include <iostream>

struct A {
  A(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
  ~A(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
};
struct B {
 B(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
~B(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
};
struct C {
 C(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
~C(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
};
struct D {
 D(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
~D(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
};
struct E : virtual A, virtual B, virtual C {
 E(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
~E(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
};
struct F : virtual C, virtual D {
 F(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
~F(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
}; 
struct G : F, E {
 G(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
~G(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
}; 




int main(int argc, char *argv[]) {

  G g;

  return 0;
}
