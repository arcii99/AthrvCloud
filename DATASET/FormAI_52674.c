//FormAI DATASET v1.0 Category: Game of Life ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

// Function to print the current state of the world
void print_world(int world[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (world[r][c] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

// Function to generate a random world
void generate_world(int world[ROWS][COLS]) {
    srand(time(NULL));
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            world[r][c] = rand() % 2;
        }
    }
}

// Function to check if a given cell is alive
int is_alive(int world[ROWS][COLS], int row, int col) {
    int neighbors = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int r = row + i;
            int c = col + j;
            if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
                continue;
            }
            if (world[r][c] == 1) {
                neighbors++;
            }
        }
    }

    if (world[row][col] == 1 && (neighbors == 2 || neighbors == 3)) {
        return 1;
    } else if (world[row][col] == 0 && neighbors == 3) {
        return 1;
    } else {
        return 0;
    }
}

// Function to update the world to the next state
void update_world(int world[ROWS][COLS]) {
    int new_world[ROWS][COLS];

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            new_world[r][c] = is_alive(world, r, c);
        }
    }

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            world[r][c] = new_world[r][c];
        }
    }
}

int main() {
    int world[ROWS][COLS];

    generate_world(world);

    for (int i = 0; i < 100; i++) {
        print_world(world);
        update_world(world);
    }

    return 0;
}