//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define N 10  // grid size
#define P 0.5 // probability of occupied site

// function to randomly generate the grid
void generate_grid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double r = (double) rand() / RAND_MAX;
            if (r < P) {
                grid[i][j] = 1; // site is occupied
            } else {
                grid[i][j] = 0; // site is empty
            }
        }
    }
}

// function to print the grid
void print_grid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// function to check if the top and bottom of the grid are connected
int percolates(int grid[N][N]) {
    int top[N][N] = {0}; // to keep track of connected sites from the top
    int bottom[N][N] = {0}; // to keep track of connected sites from the bottom
    
    // initialize top and bottom sites as connected
    for (int j = 0; j < N; j++) {
        top[0][j] = 1;
        bottom[N-1][j] = 1;
    }
    
    // perform depth-first search to find connected sites from the top
    int stack[N*N][2]; // using a stack to perform DFS
    int top_index = -1; // initialize index of top stack
    for (int j = 0; j < N; j++) {
        if (grid[0][j] == 1) {
            stack[++top_index][0] = 0;
            stack[top_index][1] = j;
            top[0][j] = 1;
            while (top_index >= 0) {
                int x = stack[top_index][0];
                int y = stack[top_index][1];
                top_index--;
                if (x > 0 && grid[x-1][y] == 1 && top[x-1][y] == 0) {
                    stack[++top_index][0] = x-1;
                    stack[top_index][1] = y;
                    top[x-1][y] = 1;
                }
                if (x < N-1 && grid[x+1][y] == 1 && top[x+1][y] == 0) {
                    stack[++top_index][0] = x+1;
                    stack[top_index][1] = y;
                    top[x+1][y] = 1;
                }
                if (y > 0 && grid[x][y-1] == 1 && top[x][y-1] == 0) {
                    stack[++top_index][0] = x;
                    stack[top_index][1] = y-1;
                    top[x][y-1] = 1;
                }
                if (y < N-1 && grid[x][y+1] == 1 && top[x][y+1] == 0) {
                    stack[++top_index][0] = x;
                    stack[top_index][1] = y+1;
                    top[x][y+1] = 1;
                }
            }
        }
    }
    
    // perform depth-first search to find connected sites from the bottom
    int bottom_index = -1; // initialize index of bottom stack
    for (int j = 0; j < N; j++) {
        if (grid[N-1][j] == 1) {
            stack[++bottom_index][0] = N-1;
            stack[bottom_index][1] = j;
            bottom[N-1][j] = 1;
            while (bottom_index >= 0) {
                int x = stack[bottom_index][0];
                int y = stack[bottom_index][1];
                bottom_index--;
                if (x > 0 && grid[x-1][y] == 1 && bottom[x-1][y] == 0) {
                    stack[++bottom_index][0] = x-1;
                    stack[bottom_index][1] = y;
                    bottom[x-1][y] = 1;
                }
                if (x < N-1 && grid[x+1][y] == 1 && bottom[x+1][y] == 0) {
                    stack[++bottom_index][0] = x+1;
                    stack[bottom_index][1] = y;
                    bottom[x+1][y] = 1;
                }
                if (y > 0 && grid[x][y-1] == 1 && bottom[x][y-1] == 0) {
                    stack[++bottom_index][0] = x;
                    stack[bottom_index][1] = y-1;
                    bottom[x][y-1] = 1;
                }
                if (y < N-1 && grid[x][y+1] == 1 && bottom[x][y+1] == 0) {
                    stack[++bottom_index][0] = x;
                    stack[bottom_index][1] = y+1;
                    bottom[x][y+1] = 1;
                }
            }
        }
    }
    
    // check if there is a path from top to bottom by comparing top and bottom matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (top[i][j] == 1 && bottom[i][j] == 1) {
                return 1; // percolates
            }
        }
    }
    return 0; // does not percolate
}

int main() {
    int grid[N][N];
    srand(time(NULL)); // use current time as seed for random number generator
    
    generate_grid(grid);
    printf("Initial grid:\n");
    print_grid(grid);
    
    if (percolates(grid)) {
        printf("Percolates!\n");
    } else {
        printf("Does not percolate.\n");
    }
    
    return 0;
}