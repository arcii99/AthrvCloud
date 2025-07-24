//FormAI DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS]; //global variable to store the grid

void initialize_grid(int seed); //function to initialize the grid with random values
void print_grid(); //function to print the grid
void update_grid(); //function to update the grid according to the rules of the game of life

int main(void) {
    int i;
    int num_generations = 10;
    int seed = time(NULL); //use current time as seed for randomization
    
    initialize_grid(seed);
    
    for (i = 0; i < num_generations; i++) {
        printf("Generation %d:\n", i+1);
        print_grid();
        update_grid();
    }
    
    return 0;
}

void initialize_grid(int seed) {
    int i, j;
    srand(seed);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void update_grid() {
    int i, j, k, l;
    int neighbors;
    int new_grid[ROWS][COLS];
    
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            neighbors = 0;
            for (k = -1; k <= 1; k++) {
                for (l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) continue; //skip the current cell
                    int x = i + k;
                    int y = j + l;
                    if (x < 0) x += ROWS; //wrap around the grid
                    if (y < 0) y += COLS;
                    x %= ROWS;
                    y %= COLS;
                    neighbors += grid[x][y];
                }
            }
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) //cell dies
                new_grid[i][j] = 0;
            else if (grid[i][j] == 0 && neighbors == 3) //cell comes to life
                new_grid[i][j] = 1;
            else //cell stays the same
                new_grid[i][j] = grid[i][j];
        }
    }
    //update the original grid with the new values
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}