#include<iostream>
struct A{
A(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
virtual ~A(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
virtual void print(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
};

struct B:A{
B(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
~B(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
void print(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
};

struct C:B{
C(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
~C(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
void print(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
};

int main(int argc,char*argv[]){
A*obj=new C;
obj->print();
delete obj;
}
