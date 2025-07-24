//FormAI DATASET v1.0 Category: Game of Life ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 50
#define HEIGHT 50
#define GENERATIONS 100

int grid[WIDTH][HEIGHT];
int tmp_grid[WIDTH][HEIGHT];

int count_neighbors(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int nx = x + i;
            int ny = y + j;
            if (nx < 0) nx = WIDTH - 1;
            if (nx >= WIDTH) nx = 0;
            if (ny < 0) ny = HEIGHT - 1;
            if (ny >= HEIGHT) ny = 0;
            count += grid[nx][ny];
        }
    }
    return count;
}

int main() {
    // initialize grid
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (rand() % 2 == 0) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    // run generations
    for (int g = 0; g < GENERATIONS; g++) {
        printf("\033[H\033[J"); // clears terminal
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                if (grid[i][j]) {
                    printf("O");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                int neighbors = count_neighbors(i, j);
                if (grid[i][j]) {
                    if (neighbors < 2 || neighbors > 3) {
                        tmp_grid[i][j] = 0;
                    } else {
                        tmp_grid[i][j] = 1;
                    }
                } else {
                    if (neighbors == 3) {
                        tmp_grid[i][j] = 1;
                    } else {
                        tmp_grid[i][j] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                grid[i][j] = tmp_grid[i][j];
            }
        }

        printf("Generation %d\n", g + 1);
        // sleep(1000);
    }

    return 0;
}