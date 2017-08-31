cmake_minimum_required(VERSION 3.7)
project(tarea4_progra3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Evaluador.cpp Evaluador.h Mascota.cpp Mascota.h)
add_executable(tarea4_progra3 ${SOURCE_FILES})