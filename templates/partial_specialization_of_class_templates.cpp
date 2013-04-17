#include <stdio.h>
// partial_specialization_of_class_templates.cpp
template <typename T> struct PTS {
    enum {
        IsPointer = 0,
        IsPointerToDataMember = 0
    };
};

template <typename T> struct PTS<T *> {
    enum {
        IsPointer = 1,
        IsPointerToDataMember = 0
    };
};

template <typename T, typename U> struct PTS<T U:: *> {
    enum {
        IsPointer = 0,
        IsPointerToDataMember = 1
    };
};

struct S {};


int main() {
    S s, *pS;

    int S::*ptm;

    printf("PTS<S       >::IsPointer == %d PTS<S       >::IsPointerToDataMember == %d\n",
           PTS<S       >::IsPointer, PTS<S       >::IsPointerToDataMember);
    printf("PTS<S*      >::IsPointer == %d PTS<S*      >::IsPointerToDataMember == %d\n",
           PTS<S *      >::IsPointer, PTS<S *      >::IsPointerToDataMember);
    printf("PTS<int S::*>::IsPointer == %d PTS<int S::*>::IsPointerToDataMember == %d\n",
           PTS<int S:: *>::IsPointer, PTS<int S:: *>::IsPointerToDataMember);
}
