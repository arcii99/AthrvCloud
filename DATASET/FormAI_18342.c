//FormAI DATASET v1.0 Category: Memory Game ; Style: creative
// "Memory Game" - a classic computer game where the player has to remember the positions of different objects in a grid and match them

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5 // number of rows in the grid
#define COLS 5 // number of columns in the grid

int grid[ROWS][COLS]; // 2D array to represent the grid
int visible[ROWS][COLS]; // 2D array to represent the visibility of objects in the grid

int main() {
    srand(time(NULL)); // initialize random seed
    int numObjects = (ROWS * COLS) / 2; // calculate the number of objects

    // populate the grid with pairs of objects
    for (int i = 1; i <= numObjects; i++) {
        int row1, col1, row2, col2;
        do {
            row1 = rand() % ROWS;
            col1 = rand() % COLS;
        } while (grid[row1][col1] != 0);
        grid[row1][col1] = i;
        do {
            row2 = rand() % ROWS;
            col2 = rand() % COLS;
        } while (grid[row2][col2] != 0);
        grid[row2][col2] = i;
    }

    // initialize the visibility of objects in the grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            visible[i][j] = 0;
        }
    }

    int numMatches = 0; // initialize the number of matches to 0

    // game loop
    while (numMatches < numObjects) {
        // display the grid with visible objects
        printf("    ");
        for (int j = 0; j < COLS; j++) {
            printf("%-3d", j + 1);
        }
        printf("\n    ");
        for (int j = 0; j < COLS; j++) {
            printf("---");
        }
        printf("\n");
        for (int i = 0; i < ROWS; i++) {
            printf("%-3d|", i + 1);
            for (int j = 0; j < COLS; j++) {
                if (visible[i][j]) {
                    printf("%-3d", grid[i][j]);
                } else {
                    printf("   ");
                }
            }
            printf("\n");
        }

        // prompt the user to enter the positions of two objects
        int row1, col1, row2, col2;
        printf("Enter the row and column of the first object (e.g. 2 3): ");
        scanf("%d%d", &row1, &col1);
        printf("Enter the row and column of the second object (e.g. 4 5): ");
        scanf("%d%d", &row2, &col2);

        // check if the positions are valid
        if (row1 < 1 || row1 > ROWS || col1 < 1 || col1 > COLS ||
            row2 < 1 || row2 > ROWS || col2 < 1 || col2 > COLS) {
            printf("Invalid input! Please enter valid positions.\n");
            continue;
        }

        // check if the objects at the positions are already matched or visible
        if (grid[row1 - 1][col1 - 1] == 0 || grid[row2 - 1][col2 - 1] == 0 ||
            visible[row1 - 1][col1 - 1] || visible[row2 - 1][col2 - 1]) {
            printf("Invalid input! Please enter valid positions.\n");
            continue;
        }

        // check if the objects at the positions match
        if (grid[row1 - 1][col1 - 1] == grid[row2 - 1][col2 - 1]) {
            visible[row1 - 1][col1 - 1] = visible[row2 - 1][col2 - 1] = 1;
            numMatches++;
            printf("Congratulations! You found a match.\n");
        } else {
            printf("Sorry, the objects do not match.\n");
        }
    }

    printf("You won! You found all the matches.\n");

    return 0;
}