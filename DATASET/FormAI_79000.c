//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ROWS 9
#define MAX_COLS 9
#define MINES 10

typedef struct { // structure for cell
    bool isMine;
    bool isRevealed;
    bool isFlagged;
} Cell;

Cell board[MAX_ROWS][MAX_COLS]; // game board

int remainingCells; // remaining cells to be revealed
bool gameWon; // flag to check if game is won
bool gameOver; // flag to check if game is over

// function to place mines randomly on board
void placeMines() {
    srand(time(NULL));
    int minesPlaced = 0;
    while (minesPlaced < MINES) {
        int row = rand() % MAX_ROWS;
        int col = rand() % MAX_COLS;
        if (!board[row][col].isMine) {
            board[row][col].isMine = true;
            minesPlaced++;
        }
    }
}

// function to reveal cell at given position
void revealCell(int row, int col) {
    if (board[row][col].isRevealed || board[row][col].isFlagged) {
        return;
    }
    board[row][col].isRevealed = true;
    remainingCells--;
    if (board[row][col].isMine) {
        gameOver = true;
        return;
    }
    if (remainingCells == 0) {
        gameWon = true;
        return;
    }
    int i, j, count = 0;
    for (i = row-1; i <= row+1; i++) {
        for (j = col-1; j <= col+1; j++) {
            if (i >= 0 && j >= 0 && i < MAX_ROWS && j < MAX_COLS && board[i][j].isMine) {
                count++;
            }
        }
    }
    if (count == 0) {
        for (i = row-1; i <= row+1; i++) {
            for (j = col-1; j <= col+1; j++) {
                if (i >= 0 && j >= 0 && i < MAX_ROWS && j < MAX_COLS && !board[i][j].isRevealed) {
                    revealCell(i, j);
                }
            }
        }
    } else {
        board[row][col].isRevealed = true;
    }
}

// function to flag/unflag cell at given position
void flagCell(int row, int col) {
    if (board[row][col].isRevealed || gameWon || gameOver) {
        return;
    }
    board[row][col].isFlagged = !board[row][col].isFlagged;
}

// function to print game board
void printBoard() {
    int i, j;
    printf("  ");
    for (j = 0; j < MAX_COLS; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (i = 0; i < MAX_ROWS; i++) {
        printf("%d|", i);
        for (j = 0; j < MAX_COLS; j++) {
            if (board[i][j].isRevealed) {
                if (board[i][j].isMine) {
                    printf("* ");
                } else {
                    int count = 0, k, l;
                    for (k = i-1; k <= i+1; k++) {
                        for (l = j-1; l <= j+1; l++) {
                            if (k >= 0 && l >= 0 && k < MAX_ROWS && l < MAX_COLS && board[k][l].isMine) {
                                count++;
                            }
                        }
                    }
                    printf("%d ", count);
                }
            } else if (board[i][j].isFlagged) {
                printf("F ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// main function
int main() {
    remainingCells = MAX_ROWS * MAX_COLS - MINES;
    placeMines();
    while (!gameOver && !gameWon) {
        printBoard();
        printf("Remaining cells: %d\n", remainingCells);
        printf("Select cell (x,y) or flag (f,x,y): ");
        char input[10];
        fgets(input, 10, stdin);
        if (input[0] == 'f') {
            int x, y;
            if (sscanf(input, "f,%d,%d", &x, &y) == 2 && x >= 0 && y >= 0 && x < MAX_ROWS && y < MAX_COLS) {
                flagCell(x, y);
            }
        } else {
            int x, y;
            if (sscanf(input, "%d,%d", &x, &y) == 2 && x >= 0 && y >= 0 && x < MAX_ROWS && y < MAX_COLS) {
                revealCell(x, y);
            }
        }
    }
    if (gameWon) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Game over! You lost!\n");
    }
    printBoard();
    return 0;
}