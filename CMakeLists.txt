cmake_minimum_required(VERSION 3.20)
project(transportes C)

set(CMAKE_C_STANDARD 99)

add_executable(transportes main.c menus.c menus.h camioes.c camioes.h)
