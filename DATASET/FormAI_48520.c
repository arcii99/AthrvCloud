//FormAI DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int grid[ROWS][COLS];

void initialize_grid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }
}

void fill_grid() {
    srand(time(0)); //Seed the random number generator with current time
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2; //Fill each cell with either 0 or 1 randomly
        }
    }
}

int count_live_neighbors(int row, int col) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            int r = row + i;
            int c = col + j;
            if(r >= 0 && r < ROWS && c >= 0 && c < COLS && !(i == 0 && j == 0)) {
                count += grid[r][c];
            }
        }
    }
    return count;
}

void print_grid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 1) {
                printf("@ ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void update_grid() {
    int new_grid[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int live_neighbors = count_live_neighbors(i, j);
            if(grid[i][j] == 1) {
                if(live_neighbors < 2 || live_neighbors > 3) {
                    new_grid[i][j] = 0; //Cell dies due to under or over population
                }
                else {
                    new_grid[i][j] = 1; //Cell survives
                }
            }
            else {
                if(live_neighbors == 3) {
                    new_grid[i][j] = 1; //Cell becomes alive due to reproduction
                }
                else {
                    new_grid[i][j] = 0; //Cell stays dead
                }
            }
        }
    }
    //Copy new grid to the original grid
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    initialize_grid();
    fill_grid();
    printf("Initial Grid:\n");
    print_grid();
    printf("\n");
    int generations = 10;
    for(int i = 1; i <= generations; i++) {
        printf("Generation %d:\n", i);
        update_grid();
        print_grid();
        printf("\n");
    }

    return 0;
}