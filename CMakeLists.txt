cmake_minimum_required(VERSION 3.10)
project(code-gen-app)

set(CMAKE_CXX_STANDARD 17)
find_package(YARP REQUIRED)

add_executable(ert_main
src/ert_main.cpp 
src/HarnessControl.cpp
src/Control.cpp
src/LQR.cpp
src/Manager_1.cpp
src/Fault.cpp
)

add_executable(main_yarp
src/main_yarp.cpp 
src/HarnessControl.cpp
src/Control.cpp
src/LQR.cpp
src/Manager_1.cpp
src/Fault.cpp
)
target_link_libraries(main_yarp PUBLIC ${YARP_LIBRARIES})