//FormAI DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

/* Define the size of the grid */
#define ROWS 20
#define COLS 40

/* Define cell states */
#define DEAD 0
#define ALIVE 1

/* Helper function to print the grid */
void print_grid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] ? '*' : '.');
        }
        printf("\n");
    }    
}

/* Helper function to initialize the grid with random states */
void initialize_grid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

/* Helper function to count the number of living neighbors of a cell */
int count_neighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int neighbor_row = (row + i + ROWS) % ROWS;
            int neighbor_col = (col + j + COLS) % COLS;
            count += grid[neighbor_row][neighbor_col];
        }
    }
    return count;
}

/* Main function */
int main() {

    /* Seed the random number generator */
    srand(42);

    /* Declare and initialize the grid */
    int grid[ROWS][COLS];
    initialize_grid(grid);

    /* Print the initial grid */
    printf("***************\n");
    printf("* Game of Life *\n");
    printf("***************\n");
    printf("\n");
    print_grid(grid);
    printf("\n");

    /* Iterate over generations */
    int generation = 0;
    while (1) {

        /* Pause for a moment */
        usleep(50000);

        /* Clear the console */
        system("clear");

        /* Print the generation number */
        printf("Generation: %d\n", generation);
        printf("\n");

        /* Create a new grid to hold the next generation */
        int new_grid[ROWS][COLS];

        /* Iterate over cells */
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {

                /* Count the number of living neighbors */
                int neighbors = count_neighbors(grid, i, j);

                /* Determine the state of the cell in the next generation */
                if (grid[i][j] == ALIVE && (neighbors == 2 || neighbors == 3)) {
                    new_grid[i][j] = ALIVE;
                } else if (grid[i][j] == DEAD && neighbors == 3) {
                    new_grid[i][j] = ALIVE;
                } else {
                    new_grid[i][j] = DEAD;
                }

            }
        }

        /* Copy the new grid to the old grid */
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }

        /* Print the updated grid */
        print_grid(grid);
        printf("\n");

        /* Increment the generation number */
        generation++;

    }

    return 0;
}