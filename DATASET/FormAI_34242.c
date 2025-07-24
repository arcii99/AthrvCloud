//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 // size of grid
#define P 0.6 // probability of site being open


// function to print the grid
void print_grid(int grid[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j]==1){
                printf("* ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main(){
    // initialize the grid
    int grid[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            grid[i][j] = 0;
        }
    }

    // randomly generate open sites
    srand(time(NULL));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if((double)rand()/(double)RAND_MAX < P){
                grid[i][j] = 1;
            }
        }
    }

    // print the initial grid
    printf("Initial Grid\n");
    print_grid(grid);

    // check if there is percolation from top to bottom
    int percolates = 0;
    for(int i=0; i<N; i++){
        if(grid[0][i]==1){ // check if top site is open
            int visited[N][N];
            for(int j=0; j<N; j++){
                for(int k=0; k<N; k++){
                    visited[j][k] = 0;
                }
            }
            // recursively check neighboring sites
            void check_neighbors(int row, int col){
                if(row<0 || col<0 || row>=N || col>=N){ // out of bounds
                    return;
                }
                if(grid[row][col]==0){ // site is closed
                    return;
                }
                if(visited[row][col]==1){ // site already visited
                    return;
                }
                visited[row][col] = 1;
                if(row==N-1){ // site is in bottom row
                    percolates = 1;
                }
                check_neighbors(row-1, col); // check above
                check_neighbors(row+1, col); // check below
                check_neighbors(row, col-1); // check left
                check_neighbors(row, col+1); // check right
            }
            check_neighbors(0, i);
        }
    }

    // print the final result
    if(percolates==1){
        printf("The grid percolates!\n");
    }
    else{
        printf("The grid does not percolate.\n");
    }

    return 0;
}