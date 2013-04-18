#include <sys/time.h>
#include <iostream>
#include <limits>

main(){

    struct timeval t1;
    struct timeval t2;

    gettimeofday(&t1, NULL);




    for (int i = 0; i < std::numeric_limits<int>::max(); ++i) {
    }

    gettimeofday(&t2, NULL);

    
    __time_t sec = t2.tv_sec - t1.tv_sec;
    __suseconds_t usec = t2.tv_usec - t1.tv_usec;


    //    std::cout << sec << " sec; "<< usec << " usec ("<<  usec/1000<< ");" << std::endl;
    //    std::cout << t1.tv_sec << std::endl;
    //    std::cout << t1.tv_usec << std::endl;
    //    std::cout << t2.tv_sec << std::endl;
    //    std::cout << t2.tv_usec << std::endl;
    std::cout << (t2.tv_sec * 1000000 + t2.tv_usec - t1.tv_sec * 1000000 - t1.tv_usec) / 1000 << std::endl;
}
