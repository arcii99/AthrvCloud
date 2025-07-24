//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to print the game board
void printBoard(char board[][COLS], int score) {
    system("clear");
    printf("Score: %d\n", score);
    printf("   ");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d  ", i);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to randomly place the bombs on the board
void plantBombs(char board[][COLS], int numBombs) {
    srand(time(NULL));
    int bombsPlanted = 0;
    while (bombsPlanted < numBombs) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (board[row][col] == '.') {
            board[row][col] = '*';
            bombsPlanted++;
        }
    }
}

// Function to check if the player won the game
bool checkWin(char board[][COLS], int numBombs) {
    int tilesRevealed = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] != '.' && board[i][j] != '*') {
                tilesRevealed++;
            }
        }
    }
    if (tilesRevealed == ROWS * COLS - numBombs) {
        return true;
    } else {
        return false;
    }
}

// Main function
int main() {
    char board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '.';
        }
    }
    int numBombs = 15;
    plantBombs(board, numBombs);
    int score = 0;
    while (true) {
        printBoard(board, score);
        printf("Enter row and column (separated by space): ");
        int row, col;
        scanf("%d %d", &row, &col);
        if (board[row][col] == '*') {
            printf("Game Over!\n");
            return 0;
        } else {
            int numAdjBombs = 0;
            for (int i = row-1; i <= row+1; i++) {
                for (int j = col-1; j <= col+1; j++) {
                    if (i >= 0 && i < ROWS && j >= 0 && j < COLS && board[i][j] == '*') {
                        numAdjBombs++;
                    }
                }
            }
            board[row][col] = numAdjBombs + '0';
            score++;
            if (checkWin(board, numBombs)) {
                printf("You Win!\n");
                return 0;
            }
        }
    }
    return 0;
}