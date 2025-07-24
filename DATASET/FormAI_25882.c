//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to print the Bingo Grid
void printGrid(int grid[ROWS][COLS]) {
    printf("-----------------------\n");
    printf("|  B  |  I  |  N  |  G  |  O  |\n");
    printf("-----------------------\n");
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == -1) {
                printf("  X  |");
            }
            else {
                printf(" %2d  |", grid[i][j]);
            }
        }
        printf("\n-----------------------\n");
    }
}

// Function to check if the user has won the game
int hasWon(int grid[ROWS][COLS]) {
    int rowSum, colSum, diagonalSum1 = 0, diagonalSum2 = 0;
    for (int i = 0; i < ROWS; i++) {
        rowSum = colSum = 0;
        for (int j = 0; j < COLS; j++) {
            rowSum += grid[i][j];
            colSum += grid[j][i];
            if (i == j) { // diagonal from top left to bottom right
                diagonalSum1 += grid[i][j];
            }
            if (i == ROWS - j - 1) { // diagonal from top right to bottom left
                diagonalSum2 += grid[i][j];
            }
        }
        if (rowSum == 0 || colSum == 0) {
            return 1; // bingo in a row or column
        }
    }
    if (diagonalSum1 == 0 || diagonalSum2 == 0) {
        return 1; // bingo in a diagonal
    }
    return 0; // no bingo
}

int main() {
    int numCalls = 0;
    int grid[ROWS][COLS]; // set grid to -1
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = -1;
        }
    }
    srand(time(NULL)); // seed the random number generator
    printf("Welcome to Bingo Simulator!\n");
    printf("Let's play a game of Bingo. The first to get a bingo wins!\n");
    printf("Press enter to start the game.\n");
    getchar(); // wait for player to press enter
    while (1) {
        int lucky = rand() % 75 + 1; // generate a random number between 1 and 75
        printf("The next lucky number is %d.\n", lucky);
        numCalls++;
        for (int i = 0; i < ROWS; i++) { // mark the number in the grid
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == lucky) {
                    grid[i][j] = -1;
                }
            }
        }
        printGrid(grid);
        if (hasWon(grid)) { // check if the player has won
            printf("Bingo! You won in %d calls.\n", numCalls);
            break;
        }
        printf("Press enter for the next number.\n");
        getchar(); // wait for player to press enter
    }
    printf("Thank you for playing Bingo Simulator!\n");
    return 0;
}