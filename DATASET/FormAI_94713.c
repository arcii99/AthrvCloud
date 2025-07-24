//FormAI DATASET v1.0 Category: Game of Life ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 50

int grid[ROWS][COLUMNS];
int temp_grid[ROWS][COLUMNS];

void initialize_grid() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            if(grid[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int count_live_neighbors(int row, int col) {
    int count = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int neighbor_row = row + i;
            int neighbor_col = col + j;
            if(neighbor_row >= 0 && neighbor_col >= 0 && neighbor_row < ROWS && neighbor_col < COLUMNS) {
                if(i == 0 && j == 0) {
                    continue;
                }
                if(grid[neighbor_row][neighbor_col] == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

void update_grid() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            int live_neighbors = count_live_neighbors(i, j);
            if(grid[i][j] == 1) {
                if(live_neighbors < 2 || live_neighbors > 3) {
                    temp_grid[i][j] = 0;
                } else {
                    temp_grid[i][j] = 1;
                }
            } else {
                if(live_neighbors == 3) {
                    temp_grid[i][j] = 1;
                } else {
                    temp_grid[i][j] = 0;
                }
            }
        }
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            grid[i][j] = temp_grid[i][j];
        }
    }
}

int main() {
    initialize_grid();
    for(int i=0; i<50; i++) {
        printf("Generation %d:\n", i);
        print_grid();
        update_grid();
    }
    return 0;
}