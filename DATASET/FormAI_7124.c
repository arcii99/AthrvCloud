//FormAI DATASET v1.0 Category: Game of Life ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 30

void print_grid(int grid[][WIDTH]) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (grid[x][y] == 1) {
                printf("O");
            } else {
                printf(" ");
            }

        }
        printf("\n");
    }
}

int count_neighbours(int grid[][WIDTH], int x, int y) {
    int count = 0;
    int x1, y1;
    for (y1 = -1; y1 <= 1; y1++) {
        for (x1 = -1; x1 <= 1; x1++) {
            int x2 = x + x1;
            int y2 = y + y1;
            if (x2 >= 0 && x2 < WIDTH && y2 >= 0 && y2 < HEIGHT) {
                count += grid[x2][y2];
            }
        }
    }
    count -= grid[x][y];
    return count;
}

void update_grid(int grid[][WIDTH]) {
    int new_grid[WIDTH][HEIGHT];
    int x, y;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int neighbours = count_neighbours(grid, x, y);

            if (grid[x][y] == 0 && neighbours == 3) {
                new_grid[x][y] = 1;
            } else if (grid[x][y] == 1 && (neighbours < 2 || neighbours > 3)) {
                new_grid[x][y] = 0;
            } else {
                new_grid[x][y] = grid[x][y];
            }
        }
    }
    memcpy(grid, new_grid, WIDTH * HEIGHT * sizeof(int));
}

void random_grid(int grid[][WIDTH]) {
    srand(time(0));
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (rand() % 2 == 0) {
                grid[x][y] = 1;
            } else {
                grid[x][y] = 0;
            }
        }
    }
}

int main() {
    int grid[WIDTH][HEIGHT];
    random_grid(grid);
    while (1) {
        print_grid(grid);
        printf("\n");
        update_grid(grid);
    }
    return 0;
}