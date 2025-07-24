//FormAI DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to display the game board
void display(char board[3][3]){
    printf("Tic Tac Toe Game:\n\n");

    // loop through all the positions on the board
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf(" %c ", board[i][j]); // print the current position on the board
            if(j!=2) printf("|"); // print separator
        }
        if(i!=2) printf("\n---|---|---\n"); // print separator
    }
    printf("\n\n");
}

// function to check if the game has ended
int gameOver(char board[3][3]){
    // check if any row or column or diagonal has all X's or O's
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!='-') return 1; // row
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!='-') return 1; // column
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!='-') return 1; // diagonal 1
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!='-') return 1; // diagonal 2

    // check if the game board is full i.e. all positions are filled
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]=='-') return 0; // game not over
        }
    }

    // if neither of the above conditions satisfied, then game over in a tie
    return 2;
}

// function to get user input for position choice
void getUserMove(char board[3][3]){
    int row, col;
    printf("Enter row (1-3) and column (1-3) separated by a space: ");
    scanf("%d %d", &row, &col);
    row--; col--; // convert to zero-based indexing
    while(board[row][col] != '-'){ // if the position is already occupied
        printf("Position already occupied! Enter again: ");
        scanf("%d %d", &row, &col);
        row--; col--; // convert to zero-based indexing
    } 
    board[row][col] = 'X'; // mark the chosen position on the board
}

// function to generate random computer move
void getCompMove(char board[3][3]){
    int row, col;
    srand(time(0)); // seed the random number generator
    do{
        row = rand()%3; col = rand()%3; // generate random numbers between 0-2 inclusive
    }while(board[row][col] != '-'); // if the position is already occupied
    board[row][col] = 'O'; // mark the chosen position on the board
}

// main function
int main(){
    char board[3][3]; // 3x3 game board

    // initialize the game board with empty positions
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = '-';
        }
    }

    printf("Welcome to Tic Tac Toe! You are playing as X and the computer is O.\n");

    // loop until the game is over
    while(1){
        display(board); // display the current game board
        getUserMove(board); // get user move
        if(gameOver(board) == 1){ // check if game over due to user winning
            display(board);
            printf("Congratulations! You have won the game.\n");
            break;
        }
        if(gameOver(board) == 2){ // check if game over in a tie
            display(board);
            printf("Game over! It's a tie.\n");
            break;
        }
        getCompMove(board); // generate computer move
        if(gameOver(board) == 1){ // check if game over due to computer winning
            display(board);
            printf("Game over! The computer has won the game.\n");
            break;
        }
        if(gameOver(board) == 2){ // check if game over in a tie
            display(board);
            printf("Game over! It's a tie.\n");
            break;
        }
    }

    return 0;
}