//FormAI DATASET v1.0 Category: Game of Life ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int grid[HEIGHT][WIDTH];
int temp[HEIGHT][WIDTH];

void initGrid() {
    srand(time(NULL));
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid() {
    printf("\n");
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            if(grid[i][j] == 1) {
                printf("|*|");
            }
            else {
                printf("| |");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int getNeighbors(int row, int col) {
    int neighbors = 0;
    for(int i=row-1; i<=row+1; i++) {
        for(int j=col-1; j<=col+1; j++) {
            if(!(i==row && j==col)) {
                if(i >= 0 && j >= 0 && i < HEIGHT && j < WIDTH) {
                    if(grid[i][j] == 1) {
                        neighbors++;
                    }
                }
            }
        }
    }
    return neighbors;
}

void updateGrid() {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            int neighbors = getNeighbors(i, j);
            if(grid[i][j] == 1) {
                if(neighbors < 2 || neighbors > 3) {
                    temp[i][j] = 0;
                }
                else {
                    temp[i][j] = 1;
                }
            }
            else {
                if(neighbors == 3) {
                    temp[i][j] = 1;
                }
                else {
                    temp[i][j] = 0;
                }
            }
        }
    }
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            grid[i][j] = temp[i][j];
        }
    }
}

int main() {
    int generation = 0;
    initGrid();
    printGrid();
    while(1) {
        printf("Generation %d\n", generation);
        updateGrid();
        printGrid();
        generation++;
        getchar();
    }
    return 0;
}