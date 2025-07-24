//FormAI DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

int grid[HEIGHT][WIDTH];

void initGrid() {
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid() {
    printf("\033[H\033[J");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j] == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int countCells(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int row = (x + i + HEIGHT) % HEIGHT;
            int col = (y + j + WIDTH) % WIDTH;
            count += grid[row][col];
        }
    }
    count -= grid[x][y];
    return count;
}

void shapeShift() {
    int newGrid[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int aliveNeighbors = countCells(i, j);
            if (grid[i][j] == 1) {
                if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if (aliveNeighbors == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    initGrid();
    while (1) {
        printGrid();
        shapeShift();
        usleep(100000);
    }
    return 0;
}