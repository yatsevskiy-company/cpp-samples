cmake_minimum_required(VERSION 2.8)
project(mythread)
include_directories(${PROJECT_SOURCE_DIR}/include)
set(source src/MyThread.cpp)

add_library(mythread SHARED ${source})

if(ANDROID)
    target_link_libraries(mythread log)
endif(ANDROID)