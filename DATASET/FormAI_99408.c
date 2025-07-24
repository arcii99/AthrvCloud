//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // size of the grid
#define P 0.6 // probability of a cell being open
#define TRIALS 10 // number of percolation trials to perform

// Structure to hold a cell
typedef struct {
    int row, col; // row and column indices
    int isOpen; // whether the cell is open or not
    int isFull; // whether the cell is full or not
} Cell;

// Function to initialize a new cell
Cell newCell(int row, int col, int isOpen) {
    Cell cell;
    cell.row = row;
    cell.col = col;
    cell.isOpen = isOpen;
    cell.isFull = 0;
    return cell;
}

// Function to print the percolation system
void printSystem(Cell system[][SIZE]) {
    printf("  ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", i);
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (system[i][j].isFull) {
                printf("o ");
            } else if (system[i][j].isOpen) {
                printf(". ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the percolation system
    Cell system[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            system[i][j] = newCell(i, j, rand() <= P * RAND_MAX);
        }
    }

    // Perform percolation trials
    for (int trial = 0; trial < TRIALS; trial++) {
        // Reset the system
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                system[i][j].isFull = 0;
            }
        }

        // Fill the top row of open cells
        for (int j = 0; j < SIZE; j++) {
            if (system[0][j].isOpen) {
                system[0][j].isFull = 1;
            }
        }

        // Perform the percolation
        int percolates = 0;
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (system[i][j].isFull) {
                    if (system[i + 1][j].isOpen) {
                        system[i + 1][j].isFull = 1;
                        if (i + 1 == SIZE - 1) {
                            percolates = 1;
                        }
                    }
                    if (j > 0 && system[i][j - 1].isOpen) {
                        system[i][j - 1].isFull = 1;
                    }
                    if (j < SIZE - 1 && system[i][j + 1].isOpen) {
                        system[i][j + 1].isFull = 1;
                    }
                }
            }
        }

        // Print the system and whether it percolated
        printf("Percolation trial %d:\n", trial + 1);
        printSystem(system);
        printf("Percolates: %s\n\n", percolates ? "YES" : "NO");
    }

    return 0;
}