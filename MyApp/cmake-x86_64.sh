rm -rf build; mkdir build; cd build; 


CMAKE_BUILD_TYPE="Debug"

cmake .. \
    -DCMAKE_BUILD_TYPE=$CMAKE_BUILD_TYPE

    

make 