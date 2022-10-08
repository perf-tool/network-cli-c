cmake_minimum_required(VERSION 3.23)
project(network-cli-c C)

set(CMAKE_C_STANDARD 23)
set(TARGET network-cli-c)

FILE(GLOB Sources *.h *.c)
add_executable(${TARGET} ${Sources})
