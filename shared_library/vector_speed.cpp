#include <vector>
#include <iostream>
#include <timer.h>





int main(int argc, char *argv[]) {

  Timer timer;

    std::vector<int> v(100000000, 7);


    timer.start();

    for(size_t i = 0; i < v.size(); ++i) {
      v[i] = 8;
    }

    timer.stop();

    std::cout << timer.get() << std::endl;

    timer.start();

    for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
      *it = 8;
    }

    timer.stop();

    std::cout << timer.get() << std::endl;

}
