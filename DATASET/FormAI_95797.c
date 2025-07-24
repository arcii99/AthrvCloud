//FormAI DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* Define the size of the grid */
#define SIZE 20

/* Define the number of iterations to run */
#define ITERATIONS 50

/* Define a convenience macro for accessing elements of the grid */
#define CELL(y, x) (grid[(y) * SIZE + (x)])

/* Function to randomly initialize the grid */
void initialize_grid(bool *grid) {
    srand(time(NULL));
    for (int i = 0; i < SIZE * SIZE; i++) {
        grid[i] = rand() % 2;
    }
}

/* Function to print the grid */
void print_grid(bool *grid) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", CELL(i, j) ? '#' : ' ');
        }
        printf("\n");
    }
}

/* Function to count the number of alive neighbors */
int count_neighbors(bool *grid, int y, int x) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            /* Skip the current cell */
            if (i == 0 && j == 0) {
                continue;
            }
            /* Wrap around the edges */
            int yy = (y + i + SIZE) % SIZE;
            int xx = (x + j + SIZE) % SIZE;
            count += CELL(yy, xx);
        }
    }
    return count;
}

/* Function to update the grid for the next iteration */
void update_grid(bool *grid) {
    bool new_grid[SIZE * SIZE];
    for (int i = 0; i < SIZE * SIZE; i++) {
        int y = i / SIZE;
        int x = i % SIZE;
        int neighbors = count_neighbors(grid, y, x);
        /* Apply the rules of the game */
        if (CELL(y, x) == true && neighbors < 2) {
            new_grid[i] = false;
        }
        else if (CELL(y, x) == true && (neighbors == 2 || neighbors == 3)) {
            new_grid[i] = true;
        }
        else if (CELL(y, x) == true && neighbors > 3) {
            new_grid[i] = false;
        }
        else if (CELL(y, x) == false && neighbors == 3) {
            new_grid[i] = true;
        }
        else {
            new_grid[i] = CELL(y, x);
        }
    }
    /* Copy the new grid back to the original */
    for (int i = 0; i < SIZE * SIZE; i++) {
        grid[i] = new_grid[i];
    }
}

/* Main function */
int main() {
    bool grid[SIZE * SIZE];
    initialize_grid(grid);
    for (int i = 0; i < ITERATIONS; i++) {
        printf("Iteration %d:\n", i);
        print_grid(grid);
        update_grid(grid);
    }
    return 0;
}