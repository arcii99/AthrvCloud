//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void printBoard(char board[3][3]);
int checkWin(char board[3][3], char player);
void makeMove(char board[3][3], int row, int col, char player);
void computerMove(char board[3][3]);

int main() {
    // Initialize board and player
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';
    
    printf("Welcome to Tic Tac Toe!\n\n");
    printf("The board is 3x3. Please input your moves in (row, column) format starting from 0.\n\n");
    printf("Let's begin!\n\n");
    
    // Loop through game until there is a winner or tie
    while (1) {
        printBoard(board);
        
        int row, col, validMove;
        
        // Player move
        do {
            printf("Player %c: ", player);
            scanf("%d%d", &row, &col);
            if (board[row][col] != ' ') {
                printf("Invalid move. Please choose an empty square.\n");
                validMove = 0;
            } else {
                validMove = 1;
            }
        } while (!validMove);
        
        makeMove(board, row, col, player);
        
        // Check for win or tie
        if (checkWin(board, player)) {
            printBoard(board);
            printf("Player %c wins!\n", player);
            break;
        }
        
        // Check for tie
        int emptySpaces = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ')
                    emptySpaces++;
            }
        }
        if (emptySpaces == 0) {
            printBoard(board);
            printf("Tie game!\n");
            break;
        }
        
        // Computer move
        computerMove(board);
        
        // Check for win or tie
        if (checkWin(board, 'O')) {
            printBoard(board);
            printf("Computer wins!\n");
            break;
        }
        
        // Check for tie
        emptySpaces = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ')
                    emptySpaces++;
            }
        }
        if (emptySpaces == 0) {
            printBoard(board);
            printf("Tie game!\n");
            break;
        }
    }
    
    return 0;
}

// Function to print the board
void printBoard(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check for win
int checkWin(char board[3][3], char player) {
    if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
        return 1;
    } else if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
        return 1;
    } else if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
        return 1;
    } else if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
        return 1;
    } else if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
        return 1;
    } else if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
        return 1;
    } else if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    } else if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
        return 1;
    } else {
        return 0;
    }
}

// Function to make a move
void makeMove(char board[3][3], int row, int col, char player) {
    board[row][col] = player;
}

// Function for the computer move (AI)
void computerMove(char board[3][3]) {
    printf("Computer's turn:\n");
    
    // Check for possible win
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                if (checkWin(board, 'O')) {
                    return;
                } else {
                    board[i][j] = ' ';
                }
            }
        }
    }
    
    // Check for possible block
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                if (checkWin(board, 'X')) {
                    board[i][j] = 'O';
                    return;
                } else {
                    board[i][j] = ' ';
                }
            }
        }
    }
    
    // Choose random square
    srand(time(NULL));
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    
    board[row][col] = 'O';
}