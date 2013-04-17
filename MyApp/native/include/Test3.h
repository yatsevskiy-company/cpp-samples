#ifndef TEST3_H
#define TEST3_H

struct D;

struct A                             {int i; virtual A * bar(D * d) = 0; virtual ~A() {}};
struct B : virtual          public A {int i; virtual B * bar(D * d) = 0; };
struct C : virtual          public A {int i; virtual A * bar(D * d); };
struct D : public   B   ,   public C {int i; virtual B * bar(D * d); };

#endif
