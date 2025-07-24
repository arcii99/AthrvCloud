//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of the percolation grid

/* Initializing the grid */
int grid[N][N] = {0};

/* Function to print the grid */
void print_grid() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d\t", grid[i][j]);
        }
        printf("\n");
    }
}

/* Function to check if the grid is percolating */
int is_percolating() {
    for(int i=0; i<N; i++) {
        if(grid[0][i] == 1) {
            /* If the top row has a site open, check if it is connected to the bottom row */
            for(int j=0; j<N; j++) {
                if(grid[N-1][j] == 1) {
                    if(is_connected(i, 0, j, N-1)) {
                        /* The grid is percolating */
                        return 1;
                    }
                }
            }
        }
    }

    /* The grid is not percolating */
    return 0;
}

/* Function to check if two sites are connected */
int is_connected(int x1, int y1, int x2, int y2) {
    if(x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || x1 >= N || x2 >= N || y1 >= N || y2 >= N) {
        /* Invalid input */
        return 0;
    }

    /* Initialize the visited array */
    int visited[N][N] = {0};

    /* Initialize a stack for DFS */
    int stack[N*N][2];
    int top = 0;

    /* Push the first site onto the stack */
    stack[top][0] = x1;
    stack[top++][1] = y1;

    /* Perform DFS until the stack is empty */
    while(top > 0) {
        /* Pop a site from the stack */
        int x = stack[--top][0];
        int y = stack[top][1];

        /* Check if the site is connected to the second site */
        if(x == x2 && y == y2) {
            return 1;
        }

        /* Mark the site as visited */
        visited[x][y] = 1;

        /* Push all adjacent open sites onto the stack */
        if(x > 0 && grid[x-1][y] == 1 && !visited[x-1][y]) {
            stack[top][0] = x-1;
            stack[top++][1] = y;
        }

        if(x < N-1 && grid[x+1][y] == 1 && !visited[x+1][y]) {
            stack[top][0] = x+1;
            stack[top++][1] = y;
        }

        if(y > 0 && grid[x][y-1] == 1 && !visited[x][y-1]) {
            stack[top][0] = x;
            stack[top++][1] = y-1;
        }

        if(y < N-1 && grid[x][y+1] == 1 && !visited[x][y+1]) {
            stack[top][0] = x;
            stack[top++][1] = y+1;
        }
    }

    /* The sites are not connected */
    return 0;
}

/* Function to simulate the percolation process */
void percolate() {
    /* Initialize the random number generator */
    srand(time(NULL));

    /* Open the top row */
    for(int i=0; i<N; i++) {
        if(rand() % 2 == 1) {
            grid[0][i] = 1;
        }
    }

    /* Open sites at random until the grid percolates */
    while(!is_percolating()) {
        /* Pick a random site */
        int x = rand() % N;
        int y = rand() % N;

        /* Open the site */
        if(grid[x][y] == 0) {
            grid[x][y] = 1;
        }
    }
}

int main() {
    /* Perform the percolation process */
    percolate();

    /* Print the final grid */
    printf("Final Grid:\n");
    print_grid();

    return 0;
}