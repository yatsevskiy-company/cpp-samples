gcc -Wall -c ctest1.c ctest2.c
ar -cvq libctest.a ctest1.o ctest2.o
ar -t libctest.a