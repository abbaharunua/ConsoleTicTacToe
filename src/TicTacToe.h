#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include <vector>
#include <random>

constexpr int rows = 3;
constexpr int colums = 3;

enum Player{
    user, computer
};

bool checkGame(std::vector<std::vector<char>>);

bool vectorContainsValue(std::vector<int>, int);

void printGameSquares(std::vector<std::vector<char>>);

std::pair<int, int> getIndexOfSquare(std::vector<std::vector<char>>, int);

//Plays the computers turn
void computerTurn();

#endif