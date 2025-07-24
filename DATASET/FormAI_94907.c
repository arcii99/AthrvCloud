//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 20 //grid size
#define p 0.6 //probability of site being open
#define CLOSED 0 //site is closed
#define OPEN 1 //site is open
#define CONNECTED 2 //site is connected

int grid[N][N]; //grid

void initialize_grid() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(((double) rand() / (RAND_MAX)) <= p)
                grid[i][j] = OPEN;
            else
                grid[i][j] = CLOSED;
        }
    }
}

void print_grid() {
    printf("\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j] == OPEN)
                printf("* ");
            else if(grid[i][j] == CONNECTED)
                printf("O ");
            else
                printf("- ");
        }
        printf("\n");
    }
}

int is_valid(int x, int y) {
    return (x>=0 && x<N && y>=0 && y<N);
}

int is_full(int x, int y) {
    if(!is_valid(x, y) || grid[x][y] != OPEN)
        return 0;
    
    grid[x][y] = CONNECTED;
    if(x == 0)
        return 1;
    
    return (is_full(x-1, y) || is_full(x+1, y) || is_full(x, y-1) || is_full(x, y+1));
}

int percolates() {
    for(int j=0; j<N; j++) {
        if(is_full(N-1, j))
            return 1;
    }
    
    return 0;
}

int main() {
    srand(time(NULL)); //seeding random number generator
    
    initialize_grid();

    print_grid();
    printf("\nPercolates? %s\n", percolates() ? "Yes" : "No");
    
    return 0;
}