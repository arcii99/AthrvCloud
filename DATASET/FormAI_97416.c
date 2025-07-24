//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10 // size of the grid
#define THRESHOLD 0.5 // probability of a cell being open

int grid[SIZE][SIZE]; // initialize grid

// Function to print the grid
void printGrid() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(grid[i][j] == 0) {
                printf("X"); // closed cell
            } else {
                printf("O"); // open cell
            }
        }
        printf("\n");
    }
}

// Function to check if a cell is in bounds
bool inBounds(int i, int j) {
    return i >= 0 && i < SIZE && j >= 0 && j < SIZE;
}

// Function to check if a cell is open
bool isOpen(int i, int j) {
    return inBounds(i, j) && grid[i][j] == 1;
}

// Function to check if a cell is full
bool isFull(int i, int j) {
    if(!inBounds(i, j) || grid[i][j] == 0) {
        return false;
    }
    if(i == 0) {
        return true;
    }
    return isFull(i-1, j) || isFull(i, j-1) || isFull(i, j+1);
}

// Function to run the percolation simulation
void percolate() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            float randNum = (float) rand() / RAND_MAX;
            if(randNum < THRESHOLD) {
                grid[i][j] = 1; // open cell
            }
        }
    }
}

int main() {
    srand(time(0)); // initialize random seed

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            grid[i][j] = 0; // closed cell
        }
    }

    percolate(); // run percolation simulation

    int count = 0; // number of cells that are full
    for(int j = 0; j < SIZE; j++) {
        if(isFull(SIZE-1, j)) {
            count++;
        }
    }

    if(count > 0) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }

    printf("Initial Grid:\n");
    printGrid();

    return 0;
}