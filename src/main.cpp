#include "TicTacToe.h"

using namespace std;

bool checkGame(vector<vector<char>>){

}

void printGameSquares(vector<vector<char>> gameSquaresIn){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < colums; j++){
            cout<<gameSquaresIn[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}

pair<int, int> getIndexOfSquare(vector<vector<char>> gameSquaresIn, int userSquareChoice) {
    int rowCounter, colCounter;
    bool userChoiceFound = false; 
    char userChoiceAsChar = userSquareChoice + '0'; // convert userSquareChoice to a char

    for (rowCounter = 0; rowCounter < 3; rowCounter++) {
        for (colCounter = 0; colCounter < 3; colCounter++) {
            if (gameSquaresIn[rowCounter][colCounter] == userChoiceAsChar) {
                userChoiceFound = true;
                break; // break out of inner loop as soon as userSquareChoice is found
            }
        }
        if (userChoiceFound) {
            break; // break out of outer loop if userSquareChoice is found
        }
    }

    pair<int, int> positionOfSquare(rowCounter, colCounter);
    return positionOfSquare;
}

void computerTurn(vector<vector<char>> gameSquaresIn) {
    //For now computer will play a random square

}

bool vectorContainsValue(std::vector<int> vectorIn, int valueToCheck) {
    for (int element : vectorIn) {
        if (element == valueToCheck){
            return true;
        }
    }
    return false;
}

int main (){
    bool gameOver = false;
    vector<vector<char>> gameSquares(rows, vector<char>(colums, '-'));
    vector<vector<char>> gameSquaresRepresentation{{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char userChoice;
    char computerChoice;
    vector<int> squaresPlayed;
    Player currentPlayer;

    //Start message for user
    cout<<"Welcome to TicTacToe. To choose noughts enter o, to choose crosses enter x."<<endl;
    cin>>userChoice;

    bool userChoiceSet = false;

    //User choses noughts or crosses
    while(!userChoiceSet){
        if (userChoice == 'o'){
            computerChoice = 'x';
            currentPlayer = Player::computer;
            userChoiceSet = true;
        }
        else if(userChoice == 'x'){
            computerChoice = 'o';
            currentPlayer = Player::user;
            userChoiceSet = true;
        }
        else{
            cout<<"You have entered an invalid input. To choose noughts enter o, to choose crosses enter x."<<endl;
            cin>>userChoice;
        }
    }
    
    cout<<"When it is your turn, use the illustration below to choose a square."<<endl;
    printGameSquares(gameSquaresRepresentation);

    //Main game loop 
    int squareChoice;
    while (!gameOver){
        if (currentPlayer == Player::computer){
            printGameSquares(gameSquares);
            currentPlayer = Player::user;
        }
        else{
            //Must make this procedure more user friendly
            do {
                cout<<"Enter the square of your choice."<<endl;
                cin>>squareChoice;
            }
            while (vectorContainsValue(squaresPlayed, squareChoice));
            pair<int, int> indexOfSquare = getIndexOfSquare(gameSquaresRepresentation, squareChoice);
            gameSquares[indexOfSquare.first][indexOfSquare.second] = userChoice;
            printGameSquares(gameSquares);
            currentPlayer = Player::computer;
        }
        //gameOver = checkGame(gameSquares);
    }
    return 0;
}