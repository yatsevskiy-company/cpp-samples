#include<iostream>
struct A{
A(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
~A(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
void print(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
};

struct B:A{
B(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
virtual ~B(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
virtual void print(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
};

struct C:B{
C(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
~C(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
void print(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
};

int main(int argc,char*argv[]){
B*obj=new C;
obj->print();
delete obj;
}
