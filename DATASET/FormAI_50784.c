//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: introspective
// ABOUT THIS PROGRAM:
// This program simulates percolation on a 2-dimensional grid using the Monte Carlo algorithm with a Weighted Quick Union Find algorithm.
// It starts with a grid of size N x N where each cell is either open or blocked. The algorithm randomly opens cells until there is a path
// from top to bottom of the grid. The program then reports the percolation threshold (i.e. the proportion of cells that needed to be
// opened to achieve percolation) and displays the final state of the grid with open cells represented by "O" and blocked cells represented by "X".

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Define the size of the grid
#define OPEN 'O' // Define the character to represent an open cell
#define BLOCKED 'X' // Define the character to represent a blocked cell

// Define a struct for the nodes in the grid
struct Node {
    int parent;
    int size;
    char status;
};

typedef struct Node Node;

// Declare the functions for the Weighted Quick Union Find algorithm
int root(int i, Node* grid);
void unionNodes(int i, int j, Node* grid);

// Declare the functions for the Monte Carlo simulation
void initializeGrid(Node* grid);
int isOpen(int i, int j, Node* grid);
int isFull(int i, int j, Node* grid);
void openNode(int i, int j, Node* grid);
int percolates(Node* grid);
float calculateThreshold(int count, float total);

// Main function
int main() {
    // Initialize the grid
    Node grid[N*N];
    initializeGrid(grid);
    
    // Declare variables to track the number of open cells and the number of steps taken
    int count = 0;
    int steps = 0;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Run the Monte Carlo simulation
    while(!percolates(grid)) {
        // Randomly choose a cell to open
        int i = rand()%N;
        int j = rand()%N;
        
        // If the cell is not already open, open it
        if(!isOpen(i, j, grid)) {
            openNode(i, j, grid);
            count++;
        }
        steps++;
    }
    
    // Calculate the percolation threshold and print it to the console
    float threshold = calculateThreshold(count, N*N);
    printf("Percolation threshold: %f\n", threshold);
    
    // Print the final state of the grid to the console
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%c ", grid[i*N+j].status);
        }
        printf("\n");
    }
    
    return 0; // End of program
}

// Define the functions for the Weighted Quick Union Find algorithm
int root(int i, Node* grid) {
    while(i != grid[i].parent) {
        grid[i].parent = grid[grid[i].parent].parent; // Path compression
        i = grid[i].parent;
    }
    return i;
}

void unionNodes(int i, int j, Node* grid) {
    int rootI = root(i, grid);
    int rootJ = root(j, grid);
    
    if(rootI == rootJ) return;
    if(grid[rootI].size < grid[rootJ].size) {
        grid[rootI].parent = rootJ;
        grid[rootJ].size += grid[rootI].size;
    } else {
        grid[rootJ].parent = rootI;
        grid[rootI].size += grid[rootJ].size;
    }
}

// Define the functions for the Monte Carlo simulation
void initializeGrid(Node* grid) {
    for(int i = 0; i < N*N; i++) {
        grid[i].parent = i;
        grid[i].size = 1;
        grid[i].status = BLOCKED;
    }
}

int isOpen(int i, int j, Node* grid) {
    return grid[i*N+j].status == OPEN;
}

int isFull(int i, int j, Node* grid) {
    return root(i*N+j, grid) < N;
}

void openNode(int i, int j, Node* grid) {
    grid[i*N+j].status = OPEN;
    if(i > 0 && isOpen(i-1, j, grid)) unionNodes(i*N+j, (i-1)*N+j, grid);
    if(j > 0 && isOpen(i, j-1, grid)) unionNodes(i*N+j, i*N+j-1, grid);
    if(i < N-1 && isOpen(i+1, j, grid)) unionNodes(i*N+j, (i+1)*N+j, grid);
    if(j < N-1 && isOpen(i, j+1, grid)) unionNodes(i*N+j, i*N+j+1, grid);
}

int percolates(Node* grid) {
    for(int j = 0; j < N; j++) {
        if(isFull(N-1, j, grid)) return 1;
    }
    return 0;
}

float calculateThreshold(int count, float total) {
    return (float)count/total;
}