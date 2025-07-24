//FormAI DATASET v1.0 Category: Chess AI ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];

//Function to initialize the chess board with zeros
void initializeBoard() {
    for(int i=0;i<BOARD_SIZE;i++) {
        for(int j=0;j<BOARD_SIZE;j++) {
            board[i][j] = 0;
        }
    }
}

//Function to print the chess board
void printBoard() {
    for(int i=0;i<BOARD_SIZE;i++) {
        for(int j=0;j<BOARD_SIZE;j++) {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

//Function to generate a random move for the AI player
int generateMove() {
    srand(time(NULL));
    return rand() % BOARD_SIZE + 1;
}

//Function to check if the move is valid
int isValidMove(int col) {
    return board[0][col] == 0;
}

//Function to make the move for the AI player
void makeMove(int player, int col) {
    for(int i=BOARD_SIZE-1;i>=0;i--) {
        if(board[i][col] == 0) {
            board[i][col] = player;
            break;
        }
    }
}

//Function to check if the game has ended
int checkForWinner(int player) {
    //Checking for rows
    for(int i=0;i<BOARD_SIZE;i++) {
        for(int j=0;j<BOARD_SIZE-3;j++) {
            if(board[i][j] == player && board[i][j+1] == player && board[i][j+2] == player && board[i][j+3] == player) {
                return 1;
            }
        }
    }

    //Checking for columns
    for(int i=0;i<BOARD_SIZE-3;i++) {
        for(int j=0;j<BOARD_SIZE;j++) {
            if(board[i][j] == player && board[i+1][j] == player && board[i+2][j] == player && board[i+3][j] == player) {
                return 1;
            }
        }
    }

    //Checking for diagonal 1
    for(int i=0;i<BOARD_SIZE-3;i++) {
        for(int j=0;j<BOARD_SIZE-3;j++) {
            if(board[i][j] == player && board[i+1][j+1] == player && board[i+2][j+2] == player && board[i+3][j+3] == player) {
                return 1;
            }
        }
    }

    //Checking for diagonal 2
    for(int i=0;i<BOARD_SIZE-3;i++) {
        for(int j=3;j<BOARD_SIZE;j++) {
            if(board[i][j] == player && board[i+1][j-1] == player && board[i+2][j-2] == player && board[i+3][j-3] == player) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    initializeBoard();
    int currentPlayer = 1;
    while(1) {
        printf("Current Board:\n");
        printBoard();
        int col;
        if(currentPlayer == 1) {
            printf("Player 1's turn. Enter column number to make a move: ");
            scanf("%d",&col);
        }
        else {
            printf("AI player making a move...\n");
            col = generateMove();
        }
        if(!isValidMove(col)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        makeMove(currentPlayer,col-1);
        int winner = checkForWinner(currentPlayer);
        if(winner) {
            printf("Player %d has won the game!\n",currentPlayer);
            break;
        }
        if(currentPlayer == 1) {
            currentPlayer = 2;
        }
        else {
            currentPlayer = 1;
        }
    }
    printf("Final Board:\n");
    printBoard();
    return 0;
}