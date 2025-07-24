//FormAI DATASET v1.0 Category: Game of Life ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int grid[ROWS][COLS];

void fillGrid() {
    srand(time(NULL));

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 1)
                printf("* ");
            else
                printf("- ");
        }
        printf("\n");
    }
}

int countNeighbors(int x, int y) {
    int count = 0;
    for(int i = x-1; i <= x+1; i++) {
        for(int j = y-1; j <= y+1; j++) {
            if(i == x && j == y)
                continue;
            if(i < 0 || i >= ROWS || j < 0 || j >= COLS)
                continue;
            if(grid[i][j] == 1)
                count++;
        }
    }
    return count;
}

void updateGrid() {
    int tempGrid[ROWS][COLS];

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(i, j);

            if(grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) // Any live cell with fewer than two live neighbours dies, as if by underpopulation. Or Any live cell with more than three live neighbours dies, as if by overpopulation.
                tempGrid[i][j] = 0;
            else if(grid[i][j] == 0 && neighbors == 3) // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
                tempGrid[i][j] = 1;
            else // Any live cell with two or three live neighbours lives on to the next generation.
                tempGrid[i][j] = grid[i][j];
        }
    }

    // Copy tempGrid to grid
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = tempGrid[i][j];
        }
    }
}

int main() {
    fillGrid();

    while(1) {
        system("clear"); // clear terminal
        printGrid();
        updateGrid();
        usleep(100000); // sleep for 100ms
    }

    return 0;
}