//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function Declaration */
void printGrid(int grid[]);
void updateGrid(int grid[], int move);
int generateRandNum();
int checkIfGameOver(int grid[]);
void gameLoop();

/* Global Variables */
int score = 0;
int highScore = 0;

/* Main Function */
int main() {
    printf("Welcome to the Terminal Based Game!\n");
    printf("Instructions: Use the arrow keys to move the tiles and merge identical numbers.\n");
    printf("Score points by merging tiles. The game ends when there are no more possible moves.\n");
    printf("\nPress any key to start the game...\n");
    getchar();

    gameLoop();

    return 0;
}

/* Actual Game Function */
void gameLoop() {
    int grid[16] = {0};
    int gameOver = 0;
    int move = 0;

    /* Set Up Grid */
    grid[generateRandNum()] = 2;
    grid[generateRandNum()] = 2;
    printGrid(grid);

    /* Keep Looping Until Game Over */
    while (!gameOver) {
        /* Get Input from User */
        move = getchar();

        /* Update Grid */
        updateGrid(grid, move);

        /* Print Updated Grid */
        printGrid(grid);

        /* Check If Game Over */
        gameOver = checkIfGameOver(grid);

        /* Print Score */
        printf("Score: %d\n", score);
        printf("High Score: %d\n", highScore);
    }

    printf("Game Over! Your Score: %d\n", score);
}

/* Function to Check If Game Over */
int checkIfGameOver(int grid[]) {
    int i = 0;
    int j = 0;

    /* Check If Grid Is Full */
    for (i = 0; i < 16; i++) {
        if (grid[i] == 0) {
            return 0;
        }
    }

    /* Check Rows for Possible Merges */
    for (i = 0; i < 16; i += 4) {
        for (j = i; j < i + 3; j++) {
            if (grid[j] == grid[j+1]) {
                return 0;
            }
        }
    }

    /* Check Columns for Possible Merges */
    for (i = 0; i < 4; i++) {
        for (j = i; j < i + 12; j += 4) {
            if (grid[j] == grid[j+4]) {
                return 0;
            }
        }
    }

    /* Game Over */
    return 1;
}

/* Function to Update Grid */
void updateGrid(int grid[], int move) {
    int i = 0;
    int j = 0;
    int k = 0;
    int tempGrid[16] = {0};

    /* Move Up */
    if (move == 'w' || move == 'W') {
        for (i = 0; i < 4; i++) {
            k = i;
            for (j = i; j <= i+12; j += 4) {
                if (grid[j] != 0) {
                    tempGrid[k] = grid[j];
                    k++;
                }
            }
            for (j = i+4; j <= i+12; j += 4) {
                if (grid[j] != 0) {
                    if (tempGrid[k-1] == grid[j]) {
                        tempGrid[k-1] *= 2;
                        score += tempGrid[k-1];
                        if (score > highScore) {
                            highScore = score;
                        }
                        j += 4;
                    }
                    if (k < 4) {
                        tempGrid[k] = grid[j];
                        k++;
                    }
                }
            }
            for (j = k; j < 4; j++) {
                tempGrid[j] = 0;
            }
        }
    }

    /* Move Down */
    else if (move == 's' || move == 'S') {
        for (i = 0; i < 4; i++) {
            k = i+12;
            for (j = i+12; j >= i; j -= 4) {
                if (grid[j] != 0) {
                    tempGrid[k] = grid[j];
                    k--;
                }
            }
            for (j = i+8; j >= i; j -= 4) {
                if (grid[j] != 0) {
                    if (tempGrid[k+1] == grid[j]) {
                        tempGrid[k+1] *= 2;
                        score += tempGrid[k+1];
                        if (score > highScore) {
                            highScore = score;
                        }
                        j -= 4;
                    }
                    if (k >= 12) {
                        tempGrid[k] = grid[j];
                        k--;
                    }
                }
            }
            for (j = k; j > i+12; j++) {
                tempGrid[j] = 0;
            }
        }
    }

    /* Move Left */
    else if (move == 'a' || move == 'A') {
        for (i = 0; i < 16; i += 4) {
            k = i;
            for (j = i; j <= i+3; j++) {
                if (grid[j] != 0) {
                    tempGrid[k] = grid[j];
                    k++;
                }
            }
            for (j = i+1; j <= i+3; j++) {
                if (grid[j] != 0) {
                    if (tempGrid[k-1] == grid[j]) {
                        tempGrid[k-1] *= 2;
                        score += tempGrid[k-1];
                        if (score > highScore) {
                            highScore = score;
                        }
                        j += 1;
                    }
                    if (k < i+4) {
                        tempGrid[k] = grid[j];
                        k++;
                    }
                }
            }
            for (j = k; j < i+4; j++) {
                tempGrid[j] = 0;
            }
        }
    }

    /* Move Right */
    else if (move == 'd' || move == 'D') {
        for (i = 0; i < 16; i += 4) {
            k = i+3;
            for (j = i+3; j >= i; j--) {
                if (grid[j] != 0) {
                    tempGrid[k] = grid[j];
                    k--;
                }
            }
            for (j = i+2; j >= i; j--) {
                if (grid[j] != 0) {
                    if (tempGrid[k+1] == grid[j]) {
                        tempGrid[k+1] *= 2;
                        score += tempGrid[k+1];
                        if (score > highScore) {
                            highScore = score;
                        }
                        j -= 1;
                    }
                    if (k >= i) {
                        tempGrid[k] = grid[j];
                        k--;
                    }
                }
            }
            for (j = k; j >= i; j--) {
                tempGrid[j] = 0;
            }
        }
    }

    /* Update the Actual Grid */
    for (i = 0; i < 16; i++) {
        grid[i] = tempGrid[i];
    }

    /* Generate a New 2 tile */
    grid[generateRandNum()] = 2;
}

/* Function to Generate Random Number for New Tile */
int generateRandNum() {
    int r;
    srand(time(NULL));
    r = rand() % 16;
    return r;
}

/* Function to Print the Grid */
void printGrid(int grid[]) {
    system("clear");  /* Clear the Screen */
    printf("\n");
    printf("Score: %d\n", score);
    printf("High Score: %d\n", highScore);
    printf("┌───────┬───────┬───────┬───────┐\n");
    printf("│   %4d│   %4d│   %4d│   %4d│\n", grid[0], grid[1], grid[2], grid[3]);
    printf("├───────┼───────┼───────┼───────┤\n");
    printf("│   %4d│   %4d│   %4d│   %4d│\n", grid[4], grid[5], grid[6], grid[7]);
    printf("├───────┼───────┼───────┼───────┤\n");
    printf("│   %4d│   %4d│   %4d│   %4d│\n", grid[8], grid[9], grid[10], grid[11]);
    printf("├───────┼───────┼───────┼───────┤\n");
    printf("│   %4d│   %4d│   %4d│   %4d│\n", grid[12], grid[13], grid[14], grid[15]);
    printf("└───────┴───────┴───────┴───────┘\n");
    printf("\n");
}