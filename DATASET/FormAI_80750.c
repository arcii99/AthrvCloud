//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 20 // the size of the grid
#define PROBABILITY 0.55 // the probability of a site being open

bool grid[SIZE][SIZE]; // the grid
bool visited[SIZE][SIZE]; // to keep track of which sites have been visited

// recursive function to check if the system percolates
bool percolates(int row, int col) {
    if(col < 0 || col >= SIZE || row < 0 || row >= SIZE) return false; // if out of bounds
    if(!grid[row][col]) return false; // if site is blocked
    if(visited[row][col]) return false; // if site has already been checked
    
    if(row == SIZE - 1) return true; // if site is in the bottom row
    
    visited[row][col] = true; // mark site as visited
    
    // check neighboring sites
    bool percolates_flag = percolates(row-1,col) || percolates(row+1,col) || percolates(row,col-1) || percolates(row,col+1);
    
    return percolates_flag;
}

int main() {
    srand(time(NULL)); // seed the random number generator
    
    // initialize grid with blocked sites
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            grid[i][j] = false;
        }
    }
    
    // generate random sites to open
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            float random_float = ((float)rand()/(float)(RAND_MAX));
            if(random_float < PROBABILITY) {
                grid[i][j] = true;
            }
        }
    }
    
    // print grid
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(grid[i][j]) {
                printf("O ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
    
    // check if the system percolates
    bool percolates_flag = false;
    for(int i=0; i<SIZE; i++) {
        if(percolates(0,i)) {
            percolates_flag = true;
            break;
        }
    }
    
    // print result
    if(percolates_flag) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    
    return 0;
}