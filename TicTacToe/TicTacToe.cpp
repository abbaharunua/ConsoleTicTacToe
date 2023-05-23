#include "TicTacToe.h"

using namespace std;

bool checkGame(char gameSquaresIn[rows][colums]){

}

void printGameSquares(char gameSquaresIn[rows][colums]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < colums; j++){
            cout<<gameSquaresIn[i][j]<<" ";
        }
        cout<<"\n";
    }
}

std::pair<int, int> getIndexOfSquare(char (&gameSquaresIn)[rows][colums], int userSquareChoice){
    char currentValue;
    pair<int, int> positionOfSquare;
    int rowCounter;
    int colCounter;
    bool userChoiceFound = false;
    

    for (rowCounter = 0; rowCounter < rows; rowCounter++){
        for (colCounter = 0; colCounter < colums; colCounter++){
            currentValue = gameSquaresIn[rowCounter][colCounter];
            int currentValueAsInt = currentValue - '0';
            if (currentValueAsInt == userSquareChoice) {
                userChoiceFound = true;
                break;
            }
        }
        if (userChoiceFound){
            break;
        }
    }
    positionOfSquare.first = rowCounter;
    positionOfSquare.second = colCounter;

    return positionOfSquare;
}

int main (){
    bool gameOver = false;
    char gameSquares[rows][colums] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    char gameSquaresRepresentation[rows][colums] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char userChoice;
    char computerChoice;
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
    while (!gameOver){
        if (currentPlayer == Player::computer){
            printGameSquares(gameSquares);
        }
        else{
            cout<<"Enter the square of your choice."<<endl;
            int squareChoice;
            cin>>squareChoice;
            pair<int, int> indexOfSquare = getIndexOfSquare(gameSquaresRepresentation, squareChoice);
            gameSquares[indexOfSquare.first][indexOfSquare.second] = userChoice;
            printGameSquares(gameSquares);

        }
        //gameOver = checkGame(gameSquares);
    }

    return 0;
}