#include <iostream>


//-fno-elide-constructors

class T
{
public:
    T(const T& object) { std::cout << "T(const T& object) "<< std::endl; }
    T(int value) { _value = value; std::cout << "T(int value) " << std::endl; }
    ~T() { std::cout << "~T() "<< std::endl; }


private:
    T() {std::cout << "T() "<< std::endl;}
    T& operator = (const T& object) {}
    int _value;
};

T f1() { return 10; }
T f2() { T tmp(10); return tmp; }

int main(int argc, char** argv)
{
    T a1 = f1();

    std::cout << "==================== " << std::endl;
 T a2 = f2(); 
 std::cout << "==================== " << std::endl;

 return 0;
}
