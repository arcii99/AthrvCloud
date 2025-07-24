//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10 // Change value of N to try different simulations

int grid[N][N]; // Simulation grid
int visited[N][N]; // Visited cells
int percolates = 0; // Flag to check if percolation occurs

int dfs(int r, int c){
    if(r<0 || r>=N || c<0 || c>=N || grid[r][c]==0 || visited[r][c]) return 0; // Base condition
    visited[r][c] = 1; // Marking the visited cell
    if(r==N-1) percolates = 1; // Checking if percolation occurs
    dfs(r+1,c); // Traversing down
    dfs(r-1,c); // Traversing up
    dfs(r,c+1); // Traversing right
    dfs(r,c-1); // Traversing left
    return 0;
}

int main(){
    srand(time(NULL)); // Initializing random seed
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(rand()%2) grid[i][j] = 1; // Assigning 0 or 1 randomly
            else grid[i][j] = 0;
            printf("%d ",grid[i][j]); // Printing the grid
        }
        printf("\n");
    }
    for(int i=0;i<N;i++){
        if(!visited[0][i] && grid[0][i]==1){ // Checking if cell is unvisited and open
            dfs(0,i); // Finding the path
        }
    }
    if(percolates) printf("\nThe system percolates!"); // Printing message if percolation occurs
    else printf("\nThe system does not percolate.");
    return 0;
}