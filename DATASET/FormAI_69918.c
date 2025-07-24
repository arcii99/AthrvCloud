//FormAI DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 3

// Function to initialize the game board with empty spaces
void initializeBoard(char board[][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the game board
void printBoard(char board[][GRID_SIZE]) {
    printf("   1   2   3\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d  %c | %c | %c \n", i+1, board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("  ---|---|---\n");
        }
    }
    printf("\n");
}

// Function to get player input for their move
void getPlayerMove(char board[][GRID_SIZE], int *row, int *col) {
    int tempRow, tempCol;
    printf("Enter your move (row column): ");
    scanf("%d %d", &tempRow, &tempCol);
    *row = tempRow-1;
    *col = tempCol-1;
    while (*row < 0 || *row >= GRID_SIZE || *col < 0 || *col >= GRID_SIZE || board[*row][*col] != ' ') {
        printf("Invalid move. Try again.\n");
        printf("Enter your move (row column): ");
        scanf("%d %d", &tempRow, &tempCol);
        *row = tempRow-1;
        *col = tempCol-1;
    }
}

// Function to get computer's move
void getComputerMove(char board[][GRID_SIZE], int *row, int *col) {
    srand(time(NULL));
    *row = rand() % GRID_SIZE;
    *col = rand() % GRID_SIZE;
    while (board[*row][*col] != ' ') {
        *row = rand() % GRID_SIZE;
        *col = rand() % GRID_SIZE;
    }
}

// Function to check if someone has won the game
int checkWin(char board[][GRID_SIZE], char player) {
    for (int i = 0; i < GRID_SIZE; i++) {
        // Check rows
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        // Check columns
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

int main() {
    char board[GRID_SIZE][GRID_SIZE];
    initializeBoard(board);
    int row, col, playerWin = 0, computerWin = 0;

    printf("Welcome to Tic Tac Toe!\n\n");
    printBoard(board);

    // Loop until the game is over
    while (!playerWin && !computerWin) {
        // Get player move
        getPlayerMove(board, &row, &col);
        board[row][col] = 'X';
        printBoard(board);

        // Check if player has won
        playerWin = checkWin(board, 'X');
        if (playerWin) {
            printf("Congratulations! You have won!\n");
            break;
        }

        // Check if board is full (tie)
        int boardFull = 1;
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (board[i][j] == ' ') {
                    boardFull = 0;
                    break;
                }
            }
            if (!boardFull) {
                break;
            }
        }
        if (boardFull) {
            printf("It's a tie!\n");
            break;
        }

        // Get computer move
        printf("Computer's turn:\n");
        getComputerMove(board, &row, &col);
        board[row][col] = 'O';
        printBoard(board);

        // Check if computer has won
        computerWin = checkWin(board, 'O');
        if (computerWin) {
            printf("Sorry, you lost. Better luck next time!\n");
        }
    }

    return 0;
}