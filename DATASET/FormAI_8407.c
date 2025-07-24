//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the Tic Tac Toe board
void displayBoard(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if the game is over
int isGameOver(char board[3][3]) {
    int i, j;

    // Check if any row is completely filled
    for(i=0; i<3; i++) {
        if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check if any column is completely filled
    for(j=0; j<3; j++) {
        if(board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check if any diagonal is completely filled
    if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    // Check if the board is completely filled
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return 2;
}

// Function to get the player's move
void getPlayerMove(char board[3][3], int* row, int* col) {
    printf("Enter the row and column numbers (1-3) of your move: ");
    scanf("%d%d", row, col);
    (*row)--;
    (*col)--;
    while(board[*row][*col] != ' ') {
        printf("Invalid move. Enter the row and column numbers (1-3) of your move: ");
        scanf("%d%d", row, col);
        (*row)--;
        (*col)--;
    }
}

// Function to get the computer's move
void getComputerMove(char board[3][3], int* row, int* col) {
    int i, j, found;

    // Try to find a winning move
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'O';
                if(isGameOver(board) == 1) {
                    *row = i;
                    *col = j;
                    board[i][j] = ' ';
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // Try to find a blocking move
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'X';
                if(isGameOver(board) == 1) {
                    *row = i;
                    *col = j;
                    board[i][j] = ' ';
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // Randomly choose an open spot
    srand(time(0));
    do {
        *row = rand() % 3;
        *col = rand() % 3;
    } while(board[*row][*col] != ' ');
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int row, col, turn = 0;

    printf("Welcome to the Medieval Tic Tac Toe game!\n");
    printf("You are playing as 'X' and I am playing as 'O'.\n");
    printf("The game board looks like this:\n");

    displayBoard(board);

    while(isGameOver(board) == 0) {
        if(turn == 0) {
            getPlayerMove(board, &row, &col);
            board[row][col] = 'X';
            turn = 1;
        } else {
            printf("My turn!\n");
            getComputerMove(board, &row, &col);
            board[row][col] = 'O';
            turn = 0;
        }
        displayBoard(board);
    }

    if(isGameOver(board) == 1) {
        printf("Congratulations! You won!\n");
    } else {
        printf("I won! Better luck next time!\n");
    }

    return 0;
}