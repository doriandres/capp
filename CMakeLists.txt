# MyApp CMakeList.txt

# CMake settings
cmake_minimum_required(VERSION 3.9)

# Project settings
project(MyApp VERSION 1.0)

# VCPKG Dependencies
find_package(cpprestsdk CONFIG REQUIRED)

# App entry
add_executable(MyApp MyApp.cxx)

# C++ Standard settings
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# Config file settings
configure_file(MyAppConfig.h.in MyAppConfig.h)

# To include libraries
add_subdirectory(MyMath)

# Directories to use to find files used by #include
target_include_directories(MyApp PUBLIC 
    ${PROJECT_BINARY_DIR}    
    ${CPPRESTSDK_INCLUDE_DIRS}
)

# Libraries to include
target_link_libraries(MyApp PUBLIC
    MyMath
    cpprestsdk::cpprest
)