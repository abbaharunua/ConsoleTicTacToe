#include "TicTacToe.h"

using tic = TicTacToeGame;

//TicTacToeGame Implementaion
tic::TicTacToeGame() {
    gameSquares = std::vector(rows, std::vector(columns, '-'));
    gameSquaresRepresentation = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    currentPlayer = Player::player1;
    squaresPlayed = {};
    gameOver = false;
}

void tic::checkGame() {
    
    std::vector<char> tempVectorOfPlayerChars = {player1Char, player2Char};
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
            std::cout<<gameSquares[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n\n";
}

void tic::printRepresentation() {
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            std::cout<<gameSquaresRepresentation[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n\n";
}

std::pair<int, int> tic::getIndexOfSquare(int& squareIn) {
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
    std::pair<int, int> positionOfSquare(rowCounter, colCounter);
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
    std::pair<int, int> index = getIndexOfSquare(squareChoice);

    if (currentPlayer == Player::player1) {
        gameSquares[index.first][index.second] = player1Char;
        currentPlayer = Player::player2;
    }
    else {
        gameSquares[index.first][index.second] = player1Char;
        currentPlayer = Player::player1;
    }
    squaresPlayed.push_back(squareChoice);
    printGameSquares();
    checkGame();
}

bool tic::getIsGameOver() {
    return gameOver;
}

Player tic::getCurrentPlayer() const {
    return currentPlayer;
}

//Game Handler implementation

using gmh = GameHandler;

gmh::GameHandler() {
    game = TicTacToeGame();
    startGame();
}

void gmh::startGame() {
    std::cout<<"Welcome to tic-tac-toe!. Are you \"X\" or \"O\"\n";
    bool userChoiceSet = false;        
    std::cin>>userChar;

    while (!userChoiceSet) {
        if (userChar == 'X') {
            userChoiceSet = true;
            playerOneFunction = &gmh::userTurn;
            playerTwoFunction = &gmh::computerTurn;
        }
        else if (userChar == 'O') {
            userChoiceSet = true;
            playerOneFunction = &gmh::computerTurn;
            playerTwoFunction = &gmh::userTurn;
        }
        else {
            std::cout<<"Please enter \"X\" or \"O\"\n";
        }
        std::cout<<"When it is your turn, enter the number of the square you\n"<< 
        "want to chose using the representation below.\n";
        game.printRepresentation();
    }

    while (!game.getIsGameOver()) {
        if (game.getCurrentPlayer() == Player::player1) {
            this->playerOneFunction;
        }
        else {
            this->playerTwoFunction;
        }
    }
}

void gmh::userTurn() {
    int squareChoice;
    do {
        std::cout<<"Enter the square of your choice.\n";
        std::cin>>squareChoice;
    }
    while (game.isSquarePlayed(squareChoice));
    game.playTurn(squareChoice);
}

void gmh::computerTurn() {
    int randomNumber;
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    do {
        std::uniform_int_distribution<int> distr(1, rows*columns);
        randomNumber = distr(generator);
    }
    while (game.isSquarePlayed(randomNumber));
    game.playTurn(randomNumber);
}
