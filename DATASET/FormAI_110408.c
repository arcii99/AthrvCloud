//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
// C Percolation Simulator Example Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRIDSIZE 20
#define SITE(i,j) ((i)*GRIDSIZE + (j))

int num_open_sites = 0;

/* Function to check if a site is open */
int is_open(int *grid, int i, int j) {
    return *(grid + SITE(i,j)) == 1;
}

/* Function to open a site */
void open_site(int *grid, int i, int j) {
    *(grid + SITE(i,j)) = 1;
    num_open_sites++;
}

/* Function to check percolation using DFS approach */
int percolates(int *grid, int i, int j, int *visited) {
    *(visited + SITE(i,j)) = 1;
    if(i == GRIDSIZE-1) return 1;
    if(i-1 >= 0 && is_open(grid,i-1,j) && !*(visited + SITE(i-1,j)))
        if(percolates(grid,i-1,j,visited)) return 1;
    if(j-1 >= 0 && is_open(grid,i,j-1) && !*(visited + SITE(i,j-1)))
        if(percolates(grid,i,j-1,visited)) return 1;
    if(i+1 < GRIDSIZE && is_open(grid,i+1,j) && !*(visited + SITE(i+1,j)))
        if(percolates(grid,i+1,j,visited)) return 1;
    if(j+1 < GRIDSIZE && is_open(grid,i,j+1) && !*(visited + SITE(i,j+1)))
        if(percolates(grid,i,j+1,visited)) return 1;
    return 0;
}

/* Function to print the grid */
void print_grid(int *grid) {
    for(int i=0;i<GRIDSIZE;i++) {
        for(int j=0;j<GRIDSIZE;j++) {
            if(is_open(grid,i,j)) printf("X ");
            else printf("- ");
        }
        printf("\n");
    }
}

int main() {
    
    // Initialize grid and visited arrays
    int grid[GRIDSIZE*GRIDSIZE] = {0};
    int visited[GRIDSIZE*GRIDSIZE] = {0};
    
    // Seed random number generator
    srand(time(NULL));
    
    // Loop to open sites randomly until percolation occurs
    while(!percolates(grid,0,rand()%GRIDSIZE,visited)) {
        open_site(grid,rand()%GRIDSIZE,rand()%GRIDSIZE);
    }
    
    // Print the percolating grid and statistics
    print_grid(grid);
    printf("Percolation occured by opening %d sites.",num_open_sites);
    
    return 0;
}