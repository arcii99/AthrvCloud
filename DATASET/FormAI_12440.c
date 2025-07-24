//FormAI DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MIN 1
#define MAX 5
#define MINE -1
#define UNEXPOSED 0
#define FLAGGED 1
#define EXPLODED 2

int grid[ROWS][COLS]; // game grid
int gameState[ROWS][COLS]; // state of each grid cell
int flagsPlaced = 0; // number of flags placed on the grid

int getRandomNumber(int min, int max) {
    /* Returns a random number between min and max (inclusive) */
    return (rand() % (max - min + 1)) + min;
}

void layMines() {
    /* Randomly lay mines in the game grid */
    int i, j, numMines = 0;
    srand(time(NULL));
    while (numMines < 10) {
        i = getRandomNumber(0, ROWS-1);
        j = getRandomNumber(0, COLS-1);
        if (grid[i][j] != MINE) {
            grid[i][j] = MINE;
            numMines++;
        }
    }
}

void initializeGameState() {
    /* Set the state of each grid cell to unexposed */
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            gameState[i][j] = UNEXPOSED;
        }
    }
}

void printGrid() {
    /* Print out the game grid */
    int i, j;
    printf("\t");
    for (i = 0; i < COLS; i++) {
        printf("%d\t", i);
    }
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("%d\t", i);
        for (j = 0; j < COLS; j++) {
            if (gameState[i][j] == UNEXPOSED) {
                printf(".\t");
            } else if (gameState[i][j] == FLAGGED) {
                printf("F\t");
            } else if (gameState[i][j] == EXPLODED) {
                printf("X\t");
            } else {
                printf("%d\t", grid[i][j]);
            }
        }
        printf("\n");
    }
}

int countAdjacentMines(int row, int col) {
    /* Count the number of mines adjacent to the cell at (row, col) */
    int i, j, count = 0;
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && j >= 0 && i < ROWS && j < COLS && grid[i][j] == MINE) {
                count++;
            }
        }
    }
    return count;
}

int checkWin() {
    /* Check if the player has won the game */
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] != MINE && gameState[i][j] == UNEXPOSED) {
                return 0;
            }
        }
    }
    return 1;
}

int checkLose(int row, int col) {
    /* Check if the player has lost the game (i.e. stepped on a mine) */
    if (grid[row][col] == MINE) {
        return 1;
    }
    return 0;
}

void exposeCell(int row, int col) {
    /* Expose the cell at (row, col) */
    if (gameState[row][col] == UNEXPOSED) {
        int numMines = countAdjacentMines(row, col);
        gameState[row][col] = numMines;
        if (numMines == 0) {
            int i, j;
            for (i = row - 1; i <= row + 1; i++) {
                for (j = col - 1; j <= col + 1; j++) {
                    if (i >= 0 && j >= 0 && i < ROWS && j < COLS && !(i == row && j == col)) {
                        exposeCell(i, j);
                    }
                }
            }
        }
    }
}

void toggleFlag(int row, int col) {
    /* Toggle the flag on the cell at (row, col) */
    if (gameState[row][col] == UNEXPOSED) {
        if (flagsPlaced < 10) {
            gameState[row][col] = FLAGGED;
            flagsPlaced++;
        }
    } else if (gameState[row][col] == FLAGGED) {
        gameState[row][col] = UNEXPOSED;
        flagsPlaced--;
    }
}

int main() {
    printf("Welcome to Minesweeper!\n");
    printf("You have 10 flags to place.\n");
    printf("Enter row and column to reveal cell, or flag the cell (format: row,col,f).\n");
    printf("For example: 3,2 -> reveals cell (3,2), 3,2,f -> flags cell (3,2)\n");
    int row, col, f;
    char input[10], *ptr;
    layMines();
    initializeGameState();
    while (1) {
        printGrid();
        if (checkWin() == 1) {
            printf("You win!\n");
            return 0;
        }
        printf("Enter row and column: ");
        fgets(input, 10, stdin);
        sscanf(input, "%d,%d,%d", &row, &col, &f);
        if (f == 1) {
            toggleFlag(row, col);
        } else {
            if (checkLose(row, col) == 1) {
                printf("You lose!\n");
                gameState[row][col] = EXPLODED;
                printGrid();
                return 0;
            }
            exposeCell(row, col);
        }
    }
    return 0;
}