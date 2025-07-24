//FormAI DATASET v1.0 Category: Game of Life ; Style: introspective
#include <stdio.h>

#define ROWS 20
#define COLS 20

/* Function that initializes the grid with random cells */
void init_grid(int grid[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

/* Function that prints the grid */
void print_grid(int grid[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

/* Function that calculates the next state of the grid */
void next_state(int grid[ROWS][COLS])
{
    int new_grid[ROWS][COLS] = {0};
    int i, j, neighbors;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            neighbors = grid[(i - 1 + ROWS) % ROWS][(j - 1 + COLS) % COLS] +
                        grid[(i - 1 + ROWS) % ROWS][j] +
                        grid[(i - 1 + ROWS) % ROWS][(j + 1) % COLS] +
                        grid[i][(j - 1 + COLS) % COLS] +
                        grid[i][(j + 1) % COLS] +
                        grid[(i + 1) % ROWS][(j - 1 + COLS) % COLS] +
                        grid[(i + 1) % ROWS][j] +
                        grid[(i + 1) % ROWS][(j + 1) % COLS];

            if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                new_grid[i][j] = 1;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }

    /* Copy new grid to old grid */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main()
{
    int grid[ROWS][COLS];

    /* Initialize grid with random cells */
    init_grid(grid);

    /* Print initial state of grid */
    print_grid(grid);

    /* Calculate and print the next state of grid */
    next_state(grid);
    print_grid(grid);

    /* Calculate and print the next state of grid */
    next_state(grid);
    print_grid(grid);

    /* Calculate and print the next state of grid */
    next_state(grid);
    print_grid(grid);

    return 0;
}