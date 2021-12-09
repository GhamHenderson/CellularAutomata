cmake_minimum_required(VERSION 3.20)
project(CellularAutomata C)

set(CMAKE_C_STANDARD 11)

include_directories(project)

add_executable(CellularAutomata
        project/cellautochild.c
        project/cellautoMain.c
        project/functions.h
        project/timer.h)
