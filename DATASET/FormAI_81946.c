//FormAI DATASET v1.0 Category: Game of Life ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define ROWS 30
#define COLS 30

//Grid initialization
void init_grid(int grid[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }
}

//Grid print
void print_grid(int grid[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

//Grid update
void update_grid(int grid[ROWS][COLS]) {
    int i, j, n, m;
    int adjacent_count;
    int newgrid[ROWS][COLS];
    init_grid(newgrid);

    for(i = 1; i < ROWS-1; i++) {
        for(j = 1; j < COLS-1; j++) {
            adjacent_count = 0;
            for(n = -1; n <= 1; n++) {
                for(m = -1; m <= 1; m++) {
                    adjacent_count += grid[i + n][j + m];
                }
            }
            adjacent_count -= grid[i][j];
            if(grid[i][j] && adjacent_count < 2) {
            newgrid[i][j] = 0;
            } else if(grid[i][j] && (adjacent_count == 2 || adjacent_count == 3)) {
                newgrid[i][j] = 1;
            } else if(grid[i][j] && adjacent_count > 3) {
                newgrid[i][j] = 0;
            } else if(!grid[i][j] && adjacent_count == 3) {
                newgrid[i][j] = 1;
            }
        }
    }
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            grid[i][j] = newgrid[i][j];
        }
    }
}

//Main function
int main() {
    int grid[ROWS][COLS];
    init_grid(grid);
    
    //initialize a glider object
    grid[10][10] = 1;
    grid[11][11] = 1;
    grid[12][9] = 1;
    grid[12][10] = 1;
    grid[12][11] = 1;

    //print initialized grid
    printf("Initial grid state:\n");
    print_grid(grid);

    //update and print grid for 50 times
    int i;
    for(i = 0; i < 50; i++) {
        update_grid(grid);
        printf("\nGrid State after iteration %d:\n", i+1);
        print_grid(grid);
    }
    return 0;
}