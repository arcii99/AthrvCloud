//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define ROWS 10
#define COLS 10
#define PERC 0.6

// Define enums for cell state and color
enum state {
    BLOCKED,
    OPEN,
    FULL
};

enum color {
    BLACK,
    WHITE,
    BLUE
};

// Declare global variables
enum state grid[ROWS][COLS];
enum color color_map[3] = {BLACK, WHITE, BLUE};

// Define functions 
void print_grid();
int percolates();
void percolate(int row, int col);

// Define main function
int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the grid to be all blocked cells
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = BLOCKED;
        }
    }
    
    // Open random cells to create percolation threshold PERC%
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if((double) rand() / RAND_MAX < PERC) {
                grid[i][j] = OPEN;
            }
        }
    }
    
    // Print the initial state of the grid
    print_grid();
    
    // Repeat the percolation process until the grid percolates
    while(!percolates()) {
        // Choose a random open cell and percolate from it
        int row, col;
        do {
            row = rand() % ROWS;
            col = rand() % COLS;
        } while(grid[row][col] != OPEN);
        
        // Percolate from the chosen cell
        percolate(row, col);
        
        // Print the updated state of the grid
        print_grid();
    }
    
    // Print the final state of the grid when it percolates
    printf("Percolation achieved!\n");
    print_grid();
    
    return 0;
}

// Function to print the state of the grid
void print_grid() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("\033[%dm", color_map[grid[i][j]]);
            printf("%c ", grid[i][j] == BLOCKED ? '#' : ' ');
            printf("\033[0m");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the grid percolates
int percolates() {
    for(int i=0; i<COLS; i++) {
        if(grid[ROWS-1][i] == FULL) {
            return 1;
        }
    }
    return 0;
}

// Recursive function to percolate from a given cell
void percolate(int row, int col) {
    // Base case: if the cell is blocked or already full, return
    if(grid[row][col] != OPEN) {
        return;
    }
    
    // Percolate the current cell
    grid[row][col] = FULL;
    
    // Recursively percolate from the neighboring cells
    if(row > 0) {
        percolate(row-1, col); // up
    }
    if(row < ROWS-1) {
        percolate(row+1, col); // down
    }
    if(col > 0) {
        percolate(row, col-1); // left
    }
    if(col < COLS-1) {
        percolate(row, col+1); // right
    }
}