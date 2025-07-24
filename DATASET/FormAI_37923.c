//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GRIDSIZE 20

int grid[GRIDSIZE][GRIDSIZE];

void initialize_grid() {
    for(int i = 0; i < GRIDSIZE; i++) {
        for(int j = 0; j < GRIDSIZE; j++) {
            if(i == 0) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

bool is_percolated() {
    bool first_row[GRIDSIZE] = {false};
    for(int i = 0; i < GRIDSIZE; i++) {
        if(grid[0][i] == 1) {
            first_row[i] = true;
        }
    }
    for(int i = 1; i < GRIDSIZE; i++) {
        for(int j = 0; j < GRIDSIZE; j++) {
            if(grid[i][j] == 1 && (j == 0 || first_row[j-1] || first_row[j] || first_row[j+1])) {
                first_row[j] = true;
                if(i == GRIDSIZE-1) {
                    return true;
                }
            }
        }
    }
    return false;
}

void print_grid() {
    printf("\n");
    for(int i = 0; i < GRIDSIZE; i++) {
        for(int j = 0; j < GRIDSIZE; j++) {
            if(grid[i][j] == 1) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    initialize_grid();
    print_grid();
    while(!is_percolated()) {
        int x = rand() % GRIDSIZE;
        int y = rand() % GRIDSIZE;
        if(grid[x][y] == 0) {
            grid[x][y] = 1;
        }
        print_grid();
    }
    printf("\nPercolation achieved!\n");
    return 0;
}