//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define PROBABILITY 0.6

int grid[SIZE][SIZE];
int visited[SIZE][SIZE];

void percolate(int row, int col){
    visited[row][col] = 1;
    if(row > 0 && grid[row-1][col] && !visited[row-1][col]) percolate(row-1,col);
    if(row < SIZE-1 && grid[row+1][col] && !visited[row+1][col]) percolate(row+1,col);
    if(col > 0 && grid[row][col-1] && !visited[row][col-1]) percolate(row,col-1);
    if(col < SIZE-1 && grid[row][col+1] && !visited[row][col+1]) percolate(row,col+1);
}

int is_percolated(){
    int percolated = 0;
    for(int i=0; i<SIZE; i++){
        if(visited[0][i] && visited[SIZE-1][i]){
            percolated = 1;
            break;
        }
    }
    return percolated;
}

void print_grid(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(grid[i][j]){
                printf("[] ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

int main(){
    srand(time(NULL));
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if((double)rand()/(double)RAND_MAX < PROBABILITY){
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
            visited[i][j] = 0;
        }
    }

    printf("Initial Grid:\n");
    print_grid();

    percolate(0,0);

    printf("\nFinal Grid:\n");
    print_grid();

    if(is_percolated()){
        printf("\nPercolated!\n");
    } else {
        printf("\nNot percolated.\n");
    }

    return 0;
}