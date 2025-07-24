//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10 // Grid size
#define P 0.6 // Probability of being filled

bool percolate(int grid[][N]){
    int top[N], bottom[N]; // Arrays to track top and bottom rows
    for(int i=0; i<N; i++){
        top[i] = 0;
        bottom[i] = 0;
    }
    // check if there is a path from top to bottom
    for(int j=0; j<N; j++){
        if(grid[0][j] == 1){
            top[j] = 1;
            bottom[j] = 1;
        }
    }

    for(int i=1; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j] == 1){
                if((j-1) >= 0 && top[j-1] == 1){
                    top[j] = 1;
                    bottom[j] = 1;
                }
                if((j+1) < N && top[j+1] == 1){
                    top[j] = 1;
                    bottom[j] = 1;
                }
                if(bottom[j] == 1){
                    top[j] = 1;
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        if(bottom[i] == 1 && top[i] == 1){
            return true;
        }
    }
    return false;
}

int main(){
    int grid[N][N]; // Grid to simulate percolation
    srand(time(NULL)); // Seed random number generator

    // Fill grid with random values according to probability P
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            float r = (float)rand()/(float)RAND_MAX;
            if(r < P){
                grid[i][j] = 1;
            }
            else{
                grid[i][j] = 0;
            }
        }
    }

    // Print initial grid
    printf("Initial grid: \n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Check if percolation occurs
    if(percolate(grid)){
        printf("Percolation occurs!\n");
    }
    else{
        printf("Percolation does not occur!\n");
    }

    return 0;
}