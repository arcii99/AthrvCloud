//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10 // Size of the grid
#define PERC_THRESHOLD 0.6 // Threshold probability for percolation

void initializeGrid(int grid[SIZE][SIZE]){
    int i, j;
    srand(time(NULL));
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            if((double)rand()/(double)RAND_MAX < PERC_THRESHOLD){
                grid[i][j] = 1;
            }
            else{
                grid[i][j] = 0;
            }
        }
    }
}

int percolate(int grid[SIZE][SIZE]){
    int i, j;
    int visited[SIZE][SIZE] = {0};
    for(i=0;i<SIZE;i++){
        if(grid[0][i] == 1){
            visited[0][i] = 1;
        }
    }
    for(i=1;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            if(grid[i][j] == 1){
                if((j>0 && visited[i][j-1] == 1) || (j<SIZE-1 && visited[i][j+1] == 1) || (i<SIZE-1 && visited[i+1][j] == 1)){
                    visited[i][j] = 1;
                }
            }
        }
    }
    for(i=0;i<SIZE;i++){
        if(visited[SIZE-1][i] == 1){
            return 1;
        }
    }
    return 0;
}

void displayGrid(int grid[SIZE][SIZE]){
    int i, j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            if(grid[i][j] == 1){
                printf("# ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main(){
    int grid[SIZE][SIZE];
    initializeGrid(grid);
    printf("Initial Grid:\n");
    displayGrid(grid);
    if(percolate(grid)){
        printf("\nHooray!! The Grid has Percolated\n");
    }
    else{
        printf("\nOops!! The Grid has Not Percolated\n");
    }
    return 0;
}