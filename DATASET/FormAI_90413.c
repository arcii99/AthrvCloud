//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 20 // Grid size N x N
#define p 0.6 // Probability of site occupancy

bool grid[N][N] = {0}; // Grid for percolation simulation
bool visited[N][N] = {0}; // Grid to keep track of visited sites

// Function to randomly occupy sites on the grid
void occupySites() {
    srand(time(NULL)); // seed for random function
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double randNum = (double) rand() / (double) RAND_MAX;
            if (randNum < p) {
                grid[i][j] = true;
            }
        }
    }
}

// Function to check if a site is open
bool isOpen(int row, int col) {
    if (grid[row][col] == true) {
        return true;
    }
    return false;
}

// Function to check if a site is full
bool isFull(int row, int col) {
    if (grid[row][col] == true && visited[row][col] == true) {
        return true;
    }
    return false;
}

// Function to check if the system percolates
bool percolates() {
    for (int i = 0; i < N; i++) {
        if (visited[N-1][i] == true) {
            return true;
        }
    }
    return false;
}

// Function to perform depth-first search to mark all connected sites as full
void dfs(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N) {
        return;
    }
    if (visited[row][col] || !isOpen(row, col)) {
        return;
    }
    visited[row][col] = true;
    dfs(row-1, col);
    dfs(row+1, col);
    dfs(row, col-1);
    dfs(row, col+1);
}

int main() {
    occupySites();
    dfs(0,0); // check sites from the top
    if (percolates()) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    return 0;
}