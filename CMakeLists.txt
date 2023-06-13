cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp CMgr.h CManager.h CEmployee.h CSales.h CWage.h UserController.h)
