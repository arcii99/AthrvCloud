//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to print the instructions of the game
void printInstructions() {
    printf("\n=============================\n");
    printf("     WELCOME TO THE GAME\n");
    printf("=============================\n");
    printf("Instructions:\n");
    printf("1. The game board is a 10 x 10 grid, with each cell containing either a number or a mine.\n");
    printf("2. To win the game, the player must uncover all the numbers without detonating a mine.\n");
    printf("3. The player can uncover a cell using the co-ordinates of the cell, e.g. A5, B3, C8 etc.\n");
    printf("4. The game is over if a mine is uncovered, and the player loses.\n");
    printf("5. Good Luck!\n");
    printf("=============================\n\n");
}

// Function to initialize the game board
void initGameboard(int gameboard[][COLS]) {
    srand(time(NULL));
    int i, j;
    // Set all cells to 0 initially
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            gameboard[i][j] = 0;
        }
    }
    // Randomly place 10 mines on the board
    int numMines = 10;
    while (numMines > 0) {
        int randRow = rand() % ROWS;
        int randCol = rand() % COLS;
        if (gameboard[randRow][randCol] != -1) {
            gameboard[randRow][randCol] = -1; // -1 represents a mine
            numMines--;
        }
    }
}

// Function to print the game board
void printGameboard(int gameboard[][COLS]) {
    int i, j;
    printf("  ");
    for (i = 0; i < COLS; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < COLS; j++) {
            if (gameboard[i][j] == -1) {
                printf("* ");
            } else {
                printf("%d ", gameboard[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to get user input
int getUserInput(char *inputMsg) {
    char input[3];
    printf("%s", inputMsg);
    scanf("%s", input);
    int row = input[1] - '1';
    int col = input[0] - 'A';
    return row * ROWS + col;
}

// Function to update the game board after each user input
void updateGameboard(int gameboard[][COLS], int pos) {
    int row = pos / ROWS;
    int col = pos % ROWS;
    // If the user uncovers a mine, the game is over
    if (gameboard[row][col] == -1) {
        printf("You uncovered a mine! GAME OVER.\n");
        return;
    }
    // If the user uncovers a blank cell, reveal all adjacent cells
    if (gameboard[row][col] == 0) {
        int i, j;
        for (i = -1; i <= 1; i++) {
            for (j = -1; j <= 1; j++) {
                if ((row + i >= 0) && (row + i < ROWS) && (col + j >= 0) && (col + j < COLS)) {
                    int adjPos = (row + i) * ROWS + col + j;
                    if (gameboard[row + i][col + j] >= 0) {
                        gameboard[row + i][col + j]++;
                    }
                }
            }
        }
    } else { // Otherwise, increment the value of the cell by 1
        gameboard[row][col]++;
    }
}

// Function to check if the player has won the game.
int checkWin(int gameboard[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if ((gameboard[i][j] >= 0) && (gameboard[i][j] <= 9)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    printInstructions();
    int gameboard[ROWS][COLS];
    initGameboard(gameboard);
    int gameOver = 0;
    while (!gameOver) {
        printGameboard(gameboard);
        int pos = getUserInput("Enter cell co-ordinates (e.g. A5): ");
        updateGameboard(gameboard, pos);
        gameOver = (gameboard[pos / ROWS][pos % ROWS] == -1);
        if (checkWin(gameboard)) {
            printf("\nCongratulations! You have cleared all the cells without detonating a mine. You win!\n");
            break;
        }
    }
    return 0;
}