//FormAI DATASET v1.0 Category: Game of Life ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 60

// function to randomly initialize the grid
void initGrid(int grid[ROWS][COLS]) {
    srand(time(NULL)); // seed random number generator
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2; // randomly set cell to either 0 or 1
        }
    }
}

// function to print the grid
void printGrid(int generation, int grid[ROWS][COLS]) {
    printf("Generation: %d\n", generation);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("\u2588"); // print solid block if cell is alive
            } else {
                printf(" "); // print space if cell is dead
            }
        }
        printf("\n");
    }
}

// function to count the number of living neighbors around a cell
int countNeighbors(int x, int y, int grid[ROWS][COLS]) {
    int count = 0;
    int dx, dy;
    for (dx = -1; dx <= 1; dx++) {
        for (dy = -1; dy <= 1; dy++) {
            // skip current cell and count only neighbors
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            // wrap around edges of grid
            if (nx < 0) nx = ROWS - 1;
            if (nx >= ROWS) nx = 0;
            if (ny < 0) ny = COLS - 1;
            if (ny >= COLS) ny = 0;
            if (grid[nx][ny] == 1) {
                count++;
            }
        }
    }
    return count;
}

// function to update the grid according to the rules of the Game of Life
void updateGrid(int grid[ROWS][COLS]) {
    int nextGrid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(i, j, grid);
            if (grid[i][j] == 1) {
                // cell is alive
                if (neighbors < 2 || neighbors > 3) {
                    // underpopulation or overpopulation -> cell dies
                    nextGrid[i][j] = 0;
                } else {
                    // survival -> cell lives
                    nextGrid[i][j] = 1;
                }
            } else {
                // cell is dead
                if (neighbors == 3) {
                    // reproduction -> cell lives
                    nextGrid[i][j] = 1;
                } else {
                    // no change -> cell remains dead
                    nextGrid[i][j] = 0;
                }
            }
        }
    }
    // update the grid with the new state
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = nextGrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    int generation = 0;
    initGrid(grid); // initialize the grid randomly
    while (1) { // loop indefinitely
        system("clear"); // clear the console
        printGrid(generation, grid); // print the grid
        updateGrid(grid); // update the grid according to the rules of the Game of Life
        generation++; // increment the generation count
    }
    return 0;
}