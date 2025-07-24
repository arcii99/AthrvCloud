//FormAI DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdio.h>

#define ROWS 50 // Number of rows in the grid
#define COLS 50 // Number of columns in the grid

// Function to initialize the grid with random values
void init_grid(int grid[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the grid
void print_grid(int grid[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", (grid[i][j] == 0) ? '.' : '*');
        }
        printf("\n");
    }
}

// Function to compute the next generation of the grid
void next_gen(int grid[][COLS]) {
    int new_grid[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;

            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    if (k >= 0 && k < ROWS && l >= 0 && l < COLS && !(k == i && l == j)) {
                        neighbors += grid[k][l];
                    }
                }
            }

            if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                new_grid[i][j] = 1;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS];

    srand(time(NULL)); // Seed the random number generator

    init_grid(grid);
    print_grid(grid);

    for (int i = 0; i < 100; i++) {
        printf("\nGeneration %d:\n", i + 1);
        next_gen(grid);
        print_grid(grid);
        sleep(1); // Wait for one second before printing the next generation
    }

    return 0;
}