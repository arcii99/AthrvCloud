//FormAI DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 30

void printGrid(char (*grid)[WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            char c = grid[i][j] ? '#' : '-';
            putchar(c);
        }
        putchar('\n');
    }
}

int getNeighborCount(char (*grid)[WIDTH], int x, int y) {
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i != 0 || j != 0) && x + i >= 0 && y + j >= 0 && x + i < HEIGHT && y + j < WIDTH) {
                count += grid[x + i][y + j];
            }
        }
    }

    return count;
}

void updateGrid(char (*grid)[WIDTH], char (*newGrid)[WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighborCount = getNeighborCount(grid, i, j);

            if (grid[i][j]) {
                if (neighborCount < 2 || neighborCount > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if (neighborCount == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    char grid[HEIGHT][WIDTH] = {0};

    srand(time(NULL));

    // randomly seed a few cells to start with
    for (int i = 0; i < 150; i++) {
        int x = rand() % HEIGHT;
        int y = rand() % WIDTH;

        grid[x][y] = 1;
    }

    while (1) {
        printGrid(grid);

        char newGrid[HEIGHT][WIDTH];

        updateGrid(grid, newGrid);

        // copy newGrid back to grid
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }

        // sleep for 200ms
        struct timespec tim, tim2;
        tim.tv_sec = 0;
        tim.tv_nsec = 200000000L;

        nanosleep(&tim, &tim2);

        // move cursor back to top left of terminal
        printf("\033[1;1H\033[2J");
    }

    return 0;
}