//FormAI DATASET v1.0 Category: Game of Life ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 30

int grid[ROWS][COLS];
int neighbors[ROWS][COLS];

void initialize() {
    int i, j;
    srand(time(0));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

int countNeighbors(int i, int j) {
    int count = 0;
    int x, y;
    for (x = i - 1; x <= i + 1; x++) {
        for (y = j - 1; y <= j + 1; y++) {
            if (x == i && y == j) continue;
            if (x < 0 || x >= ROWS) continue;
            if (y < 0 || y >= COLS) continue;
            count += grid[x][y];
        }
    }
    return count;
}

void update() {
    int i, j, count;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            count = countNeighbors(i, j);
            if (grid[i][j] == 0 && count == 3) {
                neighbors[i][j] = 1;
            } else if (grid[i][j] == 1 && (count < 2 || count > 3)) {
                neighbors[i][j] = 0;
            } else {
                neighbors[i][j] = grid[i][j];
            }
        }
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = neighbors[i][j];
        }
    }
}

void display() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    initialize();
    int i;
    for (i = 0; i < 100; i++) {
        display();
        update();
        printf("\033[H\033[J");
        usleep(50000);
    }
    return 0;
}