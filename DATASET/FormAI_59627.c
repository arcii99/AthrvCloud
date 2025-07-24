//FormAI DATASET v1.0 Category: Game of Life ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ROW 20
#define COL 40

void initializeGrid(int grid[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid(int grid[ROW][COL]) {
    printf("\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (grid[i][j] == 1) {
                printf(" O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int countNeighbors(int grid[ROW][COL], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nRow = (row + i + ROW) % ROW;
            int nCol = (col + j + COL) % COL;
            count += grid[nRow][nCol];
        }
    }
    count -= grid[row][col];
    return count;
}

void playGameLife(int grid[ROW][COL]) {
    int newGrid[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j] == 0 && neighbors == 3) {
                newGrid[i][j] = 1;
            } else if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0;
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int grid[ROW][COL];
    initializeGrid(grid);
    while (1) {
        printGrid(grid);
        usleep(5000);
        system("clear");
        playGameLife(grid);
    }
    return 0;
}