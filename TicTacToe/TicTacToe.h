#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>

constexpr int rows = 3;
constexpr int colums = 3;

enum Player{
    user, computer
};

bool checkGame(char[rows][colums]);

void printGameSquares(char[rows][colums]);

std::pair<int, int> getIndexOfSquare(char (&gameSquaresIn)[rows][colums], int);

#endif