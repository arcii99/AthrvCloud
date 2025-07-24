//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define BINGO 5

void printBoard(int board[ROWS][COLS]);
int checkRows(int board[ROWS][COLS], int num);
int checkCols(int board[ROWS][COLS], int num);
int checkDiagonal1(int board[ROWS][COLS], int num);
int checkDiagonal2(int board[ROWS][COLS], int num);

int main() {
    int board[ROWS][COLS];
    int i, j, num, gameover = 0, winner = 0;

    // Initialize board with 0's
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    // Seed random number generator
    srand(time(NULL));

    printf("Welcome to Bingo!\n");

    while (!gameover) {
        // Generate random number between 1 and 25
        num = rand() % 25 + 1;

        printf("\nNext number is: %d\n", num);
        printf("Checking board...\n");

        // Check rows, columns, and diagonals for the number
        if (checkRows(board, num) || checkCols(board, num) || checkDiagonal1(board, num) || checkDiagonal2(board, num)) {
            printf("We have a match!\n");

            // Print updated board
            printBoard(board);

            // Check for winner
            int row, col, diagonal1, diagonal2;

            for (i = 0; i < ROWS; i++) {
                row = 0;
                col = 0;

                for (j = 0; j < COLS; j++) {
                    if (board[i][j] == num) {
                        row++;
                    }

                    if (board[j][i] == num) {
                        col++;
                    }
                }

                if (row == BINGO || col == BINGO) {
                    winner = 1;
                    break;
                }
            }

            diagonal1 = checkDiagonal1(board, num);
            diagonal2 = checkDiagonal2(board, num);

            if (diagonal1 == BINGO || diagonal2 == BINGO) {
                winner = 1;
            }

            // Break out of loop if we have a winner
            if (winner) {
                gameover = 1;
            }
        } else {
            printf("No match!\n");
        }

        // Wait for user to press enter
        printf("\nPress enter to continue...");
        getchar();
    }

    // Print winning board
    printf("\nBingo!\n");
    printBoard(board);

    return 0;
}

// Print the current state of the board
void printBoard(int board[ROWS][COLS]) {
    int i, j;

    printf("\nBoard:\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%2d ", board[i][j]);
        }

        printf("\n");
    }
}

// Check all rows for the number
int checkRows(int board[ROWS][COLS], int num) {
    int i, j, match;

    for (i = 0; i < ROWS; i++) {
        match = 0;

        for (j = 0; j < COLS; j++) {
            if (board[i][j] == num) {
                match = 1;
            }
        }

        if (match) {
            return 1;
        }
    }

    return 0;
}

// Check all columns for the number
int checkCols(int board[ROWS][COLS], int num) {
    int i, j, match;

    for (i = 0; i < COLS; i++) {
        match = 0;

        for (j = 0; j < ROWS; j++) {
            if (board[j][i] == num) {
                match = 1;
            }
        }

        if (match) {
            return 1;
        }
    }

    return 0;
}

// Check diagonal from top left to bottom right for the number
int checkDiagonal1(int board[ROWS][COLS], int num) {
    int i, match;

    match = 0;

    for (i = 0; i < ROWS; i++) {
        if (board[i][i] == num) {
            match++;
        }
    }

    if (match == BINGO) {
        return BINGO;
    }

    return 0;
}

// Check diagonal from bottom left to top right for the number
int checkDiagonal2(int board[ROWS][COLS], int num) {
    int i, match;

    match = 0;

    for (i = 0; i < ROWS; i++) {
        if (board[i][ROWS-1-i] == num) {
            match++;
        }
    }

    if (match == BINGO) {
        return BINGO;
    }

    return 0;
}