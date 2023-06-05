#include "TicTacToe.h"

using namespace std;
using tic = TicTacToeGame;

tic::TicTacToeGame() {
    gameSquares = vector(rows, vector(columns, '-'));
    gameSquaresRepresentation = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    currentPlayer = Player::player1;
    squaresPlayed = {};
    gameOver = false;
}

void tic::checkGame() {
    
    vector<char> tempVectorOfPlayerChars = {player1Char, player2Char};
    for (char character : tempVectorOfPlayerChars) {
        //Check rows
        for (int i = 0; i < rows; i++) {
            if (gameSquares[i][0] == character && gameSquares[i][1] == character && gameSquares[i][2] == character) {
            gameOver = true;
            }
        }

        //Check columns
        for (int i = 0; i < columns; i++) {
            if(gameSquares[0][i] == character && gameSquares[1][i] == character && gameSquares[2][i] == character) {
                gameOver = true;
            }
        }

        //Check diagonals
        if (gameSquares[0][0] == character && gameSquares[1][1] == character && gameSquares[2][2] == character) {
            gameOver = true;
        }

        if (gameSquares[0][2] == character && gameSquares[1][1] == character && gameSquares[2][0] == character) {
            gameOver = true;
        }
    }
}

void tic::printGameSquares() {
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout<<gameSquares[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}

void tic::printRepresentation() {
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout<<gameSquaresRepresentation[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}

pair<int, int> tic::getIndexOfSquare(int& squareIn) {
    int rowCounter, colCounter;
    bool userChoiceFound = false; 
    char userChoiceAsChar = squareIn + '0'; // convert userSquareChoice to a char

    for (rowCounter = 0; rowCounter < 3; rowCounter++) {
        for (colCounter = 0; colCounter < 3; colCounter++) {
            if (gameSquares[rowCounter][colCounter] == userChoiceAsChar) {
                userChoiceFound = true;
                break;
            }
        }
        if (userChoiceFound) {
            break;
        }
    }
    pair<int, int> positionOfSquare(rowCounter, colCounter);
    return positionOfSquare;
}

bool tic::isSquarePlayed(int& valueToCheck) {
    for (int element : squaresPlayed) {
        if (element == valueToCheck){
            return true;
        }
    }
    return false;
}

void tic::playTurn(int& squareChoice) {
    auto index = getIndexOfSquare(squareChoice);

    if (currentPlayer == Player::player1) {
        gameSquares[index.first][index.second] = player1Char;
        currentPlayer = Player::player2;
    }
    else {
        gameSquares[index.first][index.second] = player1Char;
        currentPlayer = Player::player2;
    }
    printGameSquares();
}