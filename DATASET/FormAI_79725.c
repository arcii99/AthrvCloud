//FormAI DATASET v1.0 Category: Game of Life ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int grid[ROWS][COLS];
int temp[ROWS][COLS];

/* Function to print the grid */
void printGrid() {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

/* Function to generate the initial grid randomly */
void initGrid() {
    srand(time(NULL));
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

/* Function to compute the next generation of the grid */
void nextGen() {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            int neighbors = 0;

            // Check the number of neighbors
            for (int x=-1; x<=1; x++) {
                for (int y=-1; y<=1; y++) {
                    if (x == 0 && y == 0) {
                        continue;
                    }

                    int row = i + x;
                    int col = j + y;

                    if (row < 0) {
                        row = ROWS-1;
                    } else if (row >= ROWS) {
                        row = 0;
                    }

                    if (col < 0) {
                        col = COLS-1;
                    } else if (col >= COLS) {
                        col = 0;
                    }

                    neighbors += grid[row][col];
                }
            }

            // Apply the rules of the game
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                temp[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                temp[i][j] = 1;
            } else {
                temp[i][j] = grid[i][j];
            }
        }
    }

    // Copy the temporary grid to the main grid
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            grid[i][j] = temp[i][j];
        }
    }
}

int main() {
    initGrid();

    printf("Welcome to the Post-Apocalyptic Game of Life!\n");
    printf("Each cell is represented by a '*' or '.' depending on its state.\n");
    printf("Dead cells are represented by '.' and living cells by '*'.\n");

    printf("Initial state:\n");
    printGrid();

    int generations = 0;
    char cont = 'y';
    while (cont == 'y' || cont =='Y') {
        printf("Generation %d:\n", generations+1);
        nextGen();
        printGrid();
        generations++;
        printf("Do you want to continue? (y/n)");
        scanf(" %c", &cont);
    }

    printf("Thank you for playing the Post-Apocalyptic Game of Life!\n");
    printf("Your civilization has lasted for %d generations.\n", generations);

    return 0;
}