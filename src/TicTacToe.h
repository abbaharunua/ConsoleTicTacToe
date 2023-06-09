#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include <vector>
#include <random>
#include <map>

constexpr int rows = 3;
constexpr int columns = 3;
constexpr char player1Char = 'X';
constexpr char player2Char = 'O';

enum Player {
    player1, player2
};

class TicTacToeGame {
private:
    std::vector<std::vector<char>> gameSquares;
    std::vector<std::vector<char>> gameSquaresRepresentation;
    std::vector<int> squaresPlayed;
    Player currentPlayer;
    bool gameOver;

    //Will return the index of the a sqaure based on the given square number
    std::pair<int, int> getIndexOfSquare(int&);
public:
    //Constructor
    TicTacToeGame();

    //Checks if the game is over by seeing if one player has won or if its a draw
    void checkGame();

    //Shows the current state of the game 
    void printGameSquares();

    //Shows the id of each square
    void printRepresentation();

    //Updates the gameSquares and changes the currentPlayer 
    void playTurn(int&);

    //Checks if a square has been already used
    bool isSquarePlayed(int&);

    //Returns the isGameOver variable value
    bool getIsGameOver();

    Player getCurrentPlayer();
};

class GameHandler {
private:
    TicTacToeGame game;
    char userChar;
    void (GameHandler::*playerOneFunction)();
    void (GameHandler::*playerTwoFunction)();

public:
    GameHandler();

    void computerTurn();

    void startGame();

    void userTurn();
};
#endif