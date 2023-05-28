set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/TicTacToe.cpp
                 ${CMAKE_CURRENT_SOURCE_DIR}/TicTacToe.h)

#add_library(TicTacToe ${SOURCE_FILES})

add_executable(${PROJECT_NAME} main.cpp)