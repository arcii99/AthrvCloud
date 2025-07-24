//FormAI DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 40
#define COLS 80

void initialize_grid(bool grid[ROWS][COLS]) {
    // Setting all elements to false
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = false;
        }
    }
    // Setting some random cells to true
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(rand() % 5 == 0) {
                grid[i][j] = true;
            }
        }
    }
}

void display_grid(bool grid[ROWS][COLS]) {
    // Clearing the console
    system("clear");
    // Printing the grid
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j]) {
                printf("@");
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int count_neighbours(bool grid[ROWS][COLS], int x, int y) {
    int count = 0;
    for(int i = x - 1; i <= x + 1; i++) {
        for(int j = y - 1; j <= y + 1; j++) {
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == x && j == y)) {
                if(grid[i][j]) {
                    count++;
                }
            }
        }
    }
    return count;
}

void simulate_generation(bool grid[ROWS][COLS], bool new_grid[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int neighbours = count_neighbours(grid, i, j);
            if(grid[i][j]) {
                if(neighbours < 2 || neighbours > 3) {
                    new_grid[i][j] = false;
                }
                else {
                    new_grid[i][j] = true;
                }
            }
            else {
                if(neighbours == 3) {
                    new_grid[i][j] = true;
                }
                else {
                    new_grid[i][j] = false;
                }
            }
        }
    }
    // Copying the new grid to the original grid
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    bool grid[ROWS][COLS];
    bool new_grid[ROWS][COLS];
    initialize_grid(grid);
    while(true) {
        display_grid(grid);
        simulate_generation(grid, new_grid);
        // Delaying for 100 milliseconds
        struct timespec delay = {0, 100000000L};
        nanosleep(&delay, NULL);
    }
    return 0;
}