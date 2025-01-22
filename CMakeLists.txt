cmake_minimum_required(VERSION 3.10)
project(tlang)

file(GLOB SOURCES "src/*.c" "src/*/*.c")

file(GLOB HEADERS "src/*.h" "src/*/*.h")

add_executable(tlc ${SOURCES} ${HEADERS})

target_include_directories(tlc PRIVATE src)
