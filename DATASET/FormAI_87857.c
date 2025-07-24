//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROW 20 // number of rows in the grid
#define COL 20 // number of columns in the grid
#define PERCENTAGE 60 // percentage of sites that should be open

bool grid[ROW][COL]; // boolean grid that keeps track of site open/close status

// function to initialize the grid randomly with the specified percentage of sites that should be open
void initialize_grid() {
    int open_sites = ROW * COL * PERCENTAGE / 100; // calculate the number of sites that should be open
    
    // randomly select open sites
    while (open_sites > 0) {
        int row = rand() % ROW;
        int col = rand() % COL;
        
        if (!grid[row][col]) { // if the site is not already open
            grid[row][col] = true; // open the site
            open_sites--; // decrement the number of open sites that still need to be selected
        }
    }
}

// function to print the current state of the grid
void print_grid() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (grid[i][j]) { // if the site is open
                printf("O ");
            } else { // if the site is closed
                printf("X ");
            }
        }
        printf("\n");
    }
}

// function to check if the system percolates
bool percolates() {
    bool top_row[COL]; // boolean array that keeps track of the open sites in the top row
    
    for (int i = 0; i < COL; i++) {
        top_row[i] = grid[0][i]; // initialize the array with the open/close status of the sites in the top row
    }
    
    for (int i = 1; i < ROW; i++) {
        // boolean array that will keep track of the open sites in the row below
        bool next_row[COL];
        
        for (int j = 0; j < COL; j++) {
            if (grid[i][j]) { // if the site is open
                // check if any of the adjacent sites in the row above are open
                if ((j > 0 && top_row[j - 1]) || top_row[j] || (j < COL - 1 && top_row[j + 1])) {
                    next_row[j] = true; // open the site in the row below
                } else {
                    next_row[j] = false; // keep the site in the row below closed
                }
            } else { // if the site is closed
                next_row[j] = false; // keep the site in the row below closed
            }
        }
        
        top_row[0] = next_row[0]; // update the top_row array with the open/close status of the sites in the next row
        top_row[COL - 1] = next_row[COL - 1];
        
        for (int j = 1; j < COL - 1; j++) {
            top_row[j] = next_row[j] || (top_row[j - 1] && top_row[j + 1]); // open the site in the row below if it is connected to an open site in the row above
        }
    }
    
    // check if any site in the bottom row is open
    for (int i = 0; i < COL; i++) {
        if (grid[ROW - 1][i] && top_row[i]) { // if the site is open and it is connected to an open site in the top row
            return true; // the system percolates
        }
    }
    
    return false; // the system does not percolate
}

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    
    initialize_grid(); // initialize the grid randomly
    print_grid(); // print the initial state of the grid
    
    if (percolates()) { // check if the system percolates
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    
    return 0;
}