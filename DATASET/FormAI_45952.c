//FormAI DATASET v1.0 Category: Game of Life ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int count_neighbors(int row, int col, int arr[][COLS])
{
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && j >= 0 && i < ROWS && j < COLS && !(i == row && j == col)) {
                count += arr[i][j];
            }
        }
    }
    return count;
}

void print_grid(int arr[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%s", arr[i][j] ? "* " : ". ");
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int grid[ROWS][COLS] = {0}; // initialize all cells as dead
    srand(time(NULL)); // seed random number generator with current time

    // randomly initialize some cells as alive
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (rand() % 3 == 0) {
                grid[i][j] = 1;
            }
        }
    }

    printf("Initial state:\n");
    print_grid(grid);

    int new_grid[ROWS][COLS] = {0}; // initialize new grid to all dead
    int neighbor_count;

    // loop through each cell and apply rules of Game of Life
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            neighbor_count = count_neighbors(i, j, grid);
            if (grid[i][j] == 1 && (neighbor_count == 2 || neighbor_count == 3)) {
                new_grid[i][j] = 1; // cell stays alive
            } else if (grid[i][j] == 0 && neighbor_count == 3) {
                new_grid[i][j] = 1; // cell becomes alive
            }
            // else: cell stays dead
        }
    }

    // update old grid with new grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }

    printf("Next state:\n");
    print_grid(grid);

    return 0;
}