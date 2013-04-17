
//#include<iostream>

struct A{
A(){/*std::cout<<""<<std::endl;*/}
~A(){/*std::cout<<""<<std::endl;*/}
void print(){/*std::cout<<""<<std::endl;*/}
};

struct B:A{
B(){/*std::cout<<""<<std::endl;*/}
~B(){/*std::cout<<""<<std::endl;*/}
void print(){/*std::cout<<""<<std::endl;*/}
};

struct C:B{
C(){/*std::cout<<""<<std::endl;*/}
~C(){/*std::cout<<""<<std::endl;*/}
void print(){/*std::cout<<""<<std::endl;*/}
};

int main(int argc,char*argv[]){
    A*obj=new A;
    obj->print();
    delete obj;
}
