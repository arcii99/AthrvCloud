//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define P 0.6

int grid[N][N]; // grid for percolation
int visited[N][N]; // visited nodes on the grid
int num_components = 0; // number of components in the grid

// function to check if site is open or not
int is_open(int row, int col) {
    return grid[row][col] == 1;
}

// function to mark site as open
void mark_open(int row, int col) {
    grid[row][col] = 1;
}

// function to randomly generate the grid
void generate_grid() {
    srand(time(NULL)); // set random seed

    // fill the grid randomly
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            double r = (double)rand()/(double)RAND_MAX;
            mark_open(i, j); // mark site as open
            if(r > P) mark_open(i, j); // mark site closed based on probability
        }
    }
}

// function to check if site is valid
int is_valid(int row, int col) {
    return (row >= 0 && col >= 0 && row < N && col < N);
}

// function to perform depth first search on the grid
void dfs(int row, int col) {
    if(!is_valid(row, col)) return; // if the site is not valid, return
    if(!is_open(row, col)) return; // if the site is not open, return
    if(visited[row][col]) return; // if the site is already visited, return

    visited[row][col] = 1; // mark site as visited

    // perform dfs on adjacent sites
    dfs(row-1, col);
    dfs(row+1, col);
    dfs(row, col-1);
    dfs(row, col+1);
}

// function to calculate the number of components
int count_components() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(is_open(i, j) && !visited[i][j]) { // if site is open and not visited, perform dfs
                num_components++;
                dfs(i, j);
            }

        }
    }
    return num_components;
}

int main() {
    generate_grid();

    int num_components = count_components();
    if(num_components > 1) {
        printf("Perculation occurs!\n");
    } else {
        printf("No perculation.\n");
    }

    return 0;
}