cmake_minimum_required(VERSION 3.10)
project(code-gen-app)

set(CMAKE_CXX_STANDARD 17)

add_executable(main 
src/main.cpp 
src/Architecture.cpp
src/LQR.cpp
src/Sensing.cpp
src/Control.cpp
)