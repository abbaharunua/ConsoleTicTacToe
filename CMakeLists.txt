cmake_minimum_required(VERSION 3.26.3)

#Project name
project(ConsoleTicTacToe)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(TicTacToe)

add_executable(${PROJECT_NAME} TicTacToe/TicTacToe.cpp)