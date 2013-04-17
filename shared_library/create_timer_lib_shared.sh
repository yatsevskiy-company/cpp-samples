g++ -Wall -fPIC -c timer.cpp
g++ -shared -Wl,-soname,libtimer.so.1 -o libtimer.so.1.0 timer.o

ln -sf libtimer.so.1.0 libtimer.so.1
ln -sf libtimer.so.1.0 libtimer.so

g++ -O3 vector_speed.cpp -L. -ltimer -I.

LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH ./a.out