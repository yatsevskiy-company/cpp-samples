#include <iostream>
#include <typeinfo>
#include <assert.h>
class A{};
class B{};
class C{};
class D{};
class Collection {
public :
    A *getA() const{std::cout << "getA" << " this " << this << std::endl;}
    void setA(A *){std::cout << "setA" <<  " this " << this << std::endl;}

    B *getB() const;
    void setB(B *){}

    C *getC() const{}
    void setC(C *){}

    D *getD() const{}
    void setD(D *){}
};


class Factory {
public :
    template<typename T> long store(T *);
    template<typename T> T * restore(long);
};

template<typename U, typename V, V * (U::*GETTER)() const, void (U::*SETTER)(V*)> class Command {
private :
    long mCollection, mNewObject, mOldObject;
    Factory *mFactory;
    
    
public:
    Command(Factory *, long, long, long);
    ~Command();
    void execute();
    void undo();
};

template<typename U, typename V, V * (U::*GETTER)() const, void (U::*SETTER)(V*)>
Command<U, V, GETTER, SETTER>::Command(Factory * factory, long collection, long newObject, long oldObject) : mFactory(factory), mCollection(collection), mNewObject(newObject), mOldObject(oldObject){}

template<typename U, typename V, V * (U::*GETTER)() const, void (U::*SETTER)(V*)>
Command<U, V, GETTER, SETTER>::~Command() {}

template<typename U, typename V, V * (U::*GETTER)() const, void (U::*SETTER)(V*)>
void Command<U, V, GETTER, SETTER>::execute() {
    assert(mFactory != 0);

    U * u = mFactory->restore<U>(mCollection);

    V * v = mFactory->restore<V>(mNewObject);

    (u->*SETTER)(v);

}

template<typename U, typename V, V * (U::*GETTER)() const, void (U::*SETTER)(V*)>
void Command<U, V, GETTER, SETTER>::undo() {
    assert(mFactory != 0);
    
    U * u = mFactory->restore<U>(mCollection);

    V * v = mFactory->restore<V>(mOldObject);
    
    (u->*SETTER)(v);
}




template<typename T> 
long Factory::store(T *) {
    std::cout << "template store" << std::endl;
    return 0l;
}

template<typename T> 
T * Factory::restore(long) {
    std::cout << "template restore" << std::endl;
    return 0;
}

template<> 
long Factory::store(A *) {
    std::cout << "A store" << std::endl;
    return 0l;
}

template<> 
A * Factory::restore(long) {
    std::cout << "A restore" << std::endl;
    return 0;
}

template<> 
long Factory::store(B *) {
    std::cout << "B store" << std::endl;
    return 0l;
}

template<> 
B * Factory::restore(long) {
    std::cout << "B restore" << std::endl;
    return 0;
}

template<> 
long Factory::store(C *) {
    std::cout << "C store" << std::endl;
    return 0l;
}

template<> 
C * Factory::restore(long) {
    std::cout << "C restore" << std::endl;
    return 0;
}

template<> 
long Factory::store(D *) {
    std::cout << "D store" << std::endl;
    return 0l;
}

template<> 
D * Factory::restore(long) {
    std::cout << "D restore" << std::endl;
    return 0;
}

template<> 
long Factory::store(Collection *) {
    std::cout << "Collection store" << std::endl;
    return 0l;
}

template<> 
Collection * Factory::restore(long) {
    std::cout << "Collection restore" << std::endl;
    return 0;
}


int main() {
    Factory factory;
    A * a = 0;
    B * b = 0;
    C * c = 0;
    D * d = 0;
    long aID = factory.store(a);
    long bID = factory.store(b);
    long cID = factory.store(c);
    long dID = factory.store(d);
    a = factory.restore<A>(aID);
    b = factory.restore<B>(bID);
    c = factory.restore<C>(cID);
    d = factory.restore<D>(dID);
    Command<Collection, A, &Collection::getA, &Collection::setA> command(&factory, 0l, 0l, 0l);
    command.execute();
    command.undo();
}


