#include <iostream>
#include <Test3.h>

void dumpObject(D * o) {
 
    A * a = dynamic_cast<A *>(  o  );
    B * b = dynamic_cast<B *>(  o  );
    C * c = dynamic_cast<C *>(  o  );
    D * d = dynamic_cast<D *>(  o  );

    std::cout << "A " << a << std::endl;
    std::cout << "B " << b << std::endl;
    std::cout << "C " << c << std::endl;
    std::cout << "D " << d << std::endl;

    long pA = reinterpret_cast<long>(a);
    long pB = reinterpret_cast<long>(b);
    long pC = reinterpret_cast<long>(c);
    long pD = reinterpret_cast<long>(d);


    std::cout << "B - D -- >> " << pB - pD << std::endl;
    std::cout << "C - D -- >> " << pC - pD << std::endl;
    std::cout << "A - D -- >> " << pA - pD << std::endl;
}
 
A * C::bar(D * /*d*/) {return 0;}
B * D::bar(D * d) { if (d == this) dumpObject(this); return 0;}


int Test3(/*int argc, char* argv[]*/) {


    D *o = new D;
    dumpObject(o);
    o->bar(o);
    delete o;

    return 0;
}
