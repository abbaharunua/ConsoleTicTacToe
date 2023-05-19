#include "TicTacToe.h"

using namespace std;


bool checkGame(char gameSquaresIn[rows][colums]){

}

/*char[][] computerPlayer(){

}*/

int main (){
    bool gameOver = false;
    char gameSquares[rows][colums] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char userChoice;
    char computerChoice;
    Player currentPlayer;

    //Start message for user
    cout<<"Welcome to TicTacToe. To choose noughts enter o, to choose crosses enter x.";
    cin>>userChoice;

    bool userChoiceSet = false;

    while(!userChoiceSet){
        if (userChoice == 'o'){
            computerChoice = 'x';
            currentPlayer = Player::computer;
        }
        else if(userChoice == 'x'){
            computerChoice = 'o';
            currentPlayer = Player::user;
        }
        else{
            cout<<"You have entered an invalid input. To choose noughts enter o, to choose crosses enter x.";
            cin>>userChoice;
        }
    }

    while (!gameOver){
        gameOver = checkGame(gameSquares);
    }

    return 0;
}