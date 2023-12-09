cmake_minimum_required(VERSION 3.24)
project(AGENDAME C)

set(CMAKE_C_STANDARD 11)

add_executable(AGENDAME main.c liste.c liste.h timer.c timer.h)
