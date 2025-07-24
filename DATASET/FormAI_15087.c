//FormAI DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 30

int grid[WIDTH][HEIGHT]; // declare the grid as a global variable

void init_grid() {
    // initialize the grid randomly
    srand(time(NULL));
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid() {
    // print the grid to the console
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%c", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int x, int y) {
    // count the number of living neighbors around cell (x, y)
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nx = (x + i + WIDTH) % WIDTH;
            int ny = (y + j + HEIGHT) % HEIGHT;
            count += grid[nx][ny];
        }
    }
    count -= grid[x][y];
    return count;
}

void update_grid() {
    // update the grid based on the rules of Conway's Game of Life
    int new_grid[WIDTH][HEIGHT];
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int neighbors = count_neighbors(i, j);
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    init_grid();
    while (1) {
        print_grid();
        update_grid();
    }
    return 0;
}