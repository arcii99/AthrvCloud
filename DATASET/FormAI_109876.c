//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

int grid[ROWS][COLS];

void initialize_grid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i == 0 || i == ROWS-1 || j == 0 || j == COLS-1)
                grid[i][j] = 1;
            else
                grid[i][j] = rand()%2;
        }
    }
}

void print_grid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initialize_grid();
    print_grid();
    return 0;
}