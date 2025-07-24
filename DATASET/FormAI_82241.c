//FormAI DATASET v1.0 Category: Game of Life ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the grid
#define N 20
#define M 40

// Initialize the grid with random values
void init_grid(int grid[N][M]) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Print the current state of the grid
void print_grid(int grid[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Calculate the next state of the grid
void next_state(int grid[N][M]) {
    int new_grid[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int count = 0;
            for (int a = -1; a <= 1; a++) {
                for (int b = -1; b <= 1; b++) {
                    if (!(a == 0 && b == 0)) {
                        int x = i + a;
                        int y = j + b;
                        if (x >= 0 && x < N && y >= 0 && y < M) {
                            count += grid[x][y];
                        }
                    }
                }
            }
            if (grid[i][j] == 1 && count < 2) {
                new_grid[i][j] = 0;
            }
            else if (grid[i][j] == 1 && (count == 2 || count == 3)) {
                new_grid[i][j] = 1;
            }
            else if (grid[i][j] == 1 && count > 3) {
                new_grid[i][j] = 0;
            }
            else if (grid[i][j] == 0 && count == 3) {
                new_grid[i][j] = 1;
            }
            else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

// Main program
int main() {
    int grid[N][M];
    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        printf("Generation %d:\n", i);
        print_grid(grid);
        next_state(grid);
    }

    return 0;
}