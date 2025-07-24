//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // size of the grid

int grid[N][N]; // grid to represent the system
int visited[N][N]; // grid to keep track of visited sites

int is_connected(int row1, int col1, int row2, int col2) {
    // check if two sites are connected
    if (row1 < 0 || row2 < 0 || col1 < 0 || col2 < 0 || row1 >= N || row2 >= N || col1 >= N || col2 >= N) {
        return 0; // check for out-of-bounds indices
    }
    if (visited[row1][col1] && visited[row2][col2] && grid[row1][col1] == grid[row2][col2]) {
        return 1; // check if sites have been visited and are of same cluster
    }
    return 0; // sites are not connected
}

void dfs(int row, int col, int cluster) {
    // depth first search to label sites in the same cluster
    if (visited[row][col] || !grid[row][col]) {
        return; // if the site has already been visited or is blocked, return
    }
    visited[row][col] = 1; // mark site as visited
    grid[row][col] = cluster; // label site with cluster ID
    dfs(row-1, col, cluster); // check site to the north
    dfs(row+1, col, cluster); // check site to the south
    dfs(row, col-1, cluster); // check site to the west
    dfs(row, col+1, cluster); // check site to the east
}

int main() {
    int opened_sites = 0; // number of opened sites
    int cluster_id = 1; // cluster ID for labeling sites
    srand(time(NULL)); // seed for randomization
    
    // initialize grid and visited arrays to 0
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            grid[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    
    // randomly open sites until percolation
    while(!is_connected(0, 0, N-1, N-1)) {
        int row = rand() % N; // generate random row index
        int col = rand() % N; // generate random column index
        if(!grid[row][col]) { // if the site is blocked 
            grid[row][col] = -1; // open the site
            opened_sites++; // increment number of opened sites
            if(is_connected(row-1, col, row, col)) {
                grid[row][col] = grid[row-1][col]; // join clusters if connected
            }
            else if(is_connected(row, col-1, row, col)) {
                grid[row][col] = grid[row][col-1]; // join clusters if connected
            }
            else if(is_connected(row+1, col, row, col)) {
                grid[row][col] = grid[row+1][col]; // join clusters if connected
            }
            else if(is_connected(row, col+1, row, col)) {
                grid[row][col] = grid[row][col+1]; // join clusters if connected
            }
            else {
                grid[row][col] = cluster_id++; // create new cluster
            }
        }
    }
    
    printf("Percolation after %d sites opened.\n", opened_sites);
    
    return 0;
}