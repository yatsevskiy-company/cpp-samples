astyle -A2 -k3 ctest1.c ctest2.c main.cpp ctest.h implementation.cpp implementation.h interface.h

gcc -g -Wall -fPIC -c ctest1.c ctest2.c
g++ -g -Wall -fPIC -c implementation.cpp -I.

gcc -g -shared -Wl,-soname,libctest.so.1 -o libctest.so.1.0 ctest1.o ctest2.o implementation.o

ln -sf libctest.so.1.0 libctest.so.1
ln -sf libctest.so.1.0 libctest.so

g++ -g -rdynamic main.cpp -ldl -I.
