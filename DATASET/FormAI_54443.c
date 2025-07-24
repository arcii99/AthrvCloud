//FormAI DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLUMNS 100
#define GENERATIONS 100

bool grid[ROWS][COLUMNS];

int count_neighbors(int row, int column) {
    int count = 0;
    for(int i = -1; i < 2; i++) {
        for(int j = -1; j < 2; j++) {
            int r = row + i;
            int c = column + j;
            if(i == 0 && j == 0) continue;
            if(r < 0 || r >= ROWS || c < 0 || c >= COLUMNS) continue;
            if(grid[r][c]) count++;
        }
    }
    return count;
}

void evolve() {
    bool new_grid[ROWS][COLUMNS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            int neighbors = count_neighbors(i, j);
            if(grid[i][j]) {
                if(neighbors == 2 || neighbors == 3) {
                    new_grid[i][j] = true;
                } else {
                    new_grid[i][j] = false;
                }
            } else {
                if(neighbors == 3) {
                    new_grid[i][j] = true;
                } else {
                    new_grid[i][j] = false;
                }
            }
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

void print_grid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            printf("%c", grid[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    for(int gen = 1; gen <= GENERATIONS; gen++) {
        printf("Generation %d:\n", gen);
        print_grid();
        evolve();
    }
    return 0;
}