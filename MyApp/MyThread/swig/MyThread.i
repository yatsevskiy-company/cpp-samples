%module  ___MyThread___
 /*%module(directors="1") ___Module___*/

/*%feature("director");*/

%{
#include <namespace1/namespace2/MyThread.h>
%}

%include <namespace1/namespace2/MyThread.h>
