//FormAI DATASET v1.0 Category: Game of Life ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

int grid[HEIGHT][WIDTH];

void init_grid() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = rand() % 2;
        }
    }
}

void print_grid() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c ", grid[y][x] ? '#' : '.');
        }
        printf("\n");
    }
}

int count_neighbors(int x, int y) {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) {
                continue;
            }
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
                count += grid[ny][nx];
            }
        }
    }
    return count;
}

void update_grid() {
    int new_grid[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int neighbors = count_neighbors(x, y);
            if (grid[y][x] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[y][x] = 0;
            } else if (grid[y][x] == 0 && neighbors == 3) {
                new_grid[y][x] = 1;
            } else {
                new_grid[y][x] = grid[y][x];
            }
        }
    }
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = new_grid[y][x];
        }
    }
}

int main() {
    init_grid();
    for (int i = 0; i < 10; i++) {
        system("clear"); // for Linux/MacOS
        //system("cls"); // for Windows
        print_grid();
        update_grid();
    }
    return 0;
}