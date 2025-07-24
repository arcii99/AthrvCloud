//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // gridSize
#define PERCOLATION_THRESHOLD 0.6

int grid[SIZE][SIZE];
int top[SIZE * SIZE];
int bottom[SIZE * SIZE];

void init(){
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            grid[i][j] = 0;
        }
    }
}

int getTopRoot(int p){
    while(p != top[p]){
        top[p] = top[top[p]];
        p = top[p];
    }
    return p;
}

int getBottomRoot(int p){
    while(p != bottom[p]){
        bottom[p] = bottom[bottom[p]];
        p = bottom[p];
    }
    return p;
}

void connect(int p, int q){
    top[getTopRoot(p)] = getTopRoot(q);
    bottom[getBottomRoot(p)] = getBottomRoot(q);
}

int isConnected(int p, int q){
    return getTopRoot(p) == getTopRoot(q) && getBottomRoot(p) == getBottomRoot(q);
}

void percolate(){
    for(int i = 0; i < SIZE * SIZE; ++i){
        top[i] = i;
        bottom[i] = i;
    }

    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            if((double)rand()/RAND_MAX < PERCOLATION_THRESHOLD){
                if(i > 0 && grid[i-1][j]){
                    connect(i * SIZE + j, (i-1) * SIZE + j);
                }
                if(i < SIZE - 1 && grid[i+1][j]){
                    connect(i * SIZE + j, (i+1) * SIZE + j);
                }
                if(j > 0 && grid[i][j-1]){
                    connect(i * SIZE + j, i * SIZE + j - 1);
                }
                if(j < SIZE - 1 && grid[i][j+1]){
                    connect(i * SIZE + j, i * SIZE + j + 1);
                }
            }
        }
    }

    int topRoot = getTopRoot(0);
    int bottomRoot = getBottomRoot(SIZE * SIZE - 1);

    if(isConnected(0, SIZE * SIZE - 1)){
        printf("The grid percolates!\n");
    }
    else{
        printf("The grid does not percolate.\n");
    }  
}

int main(){
    init();
    srand(time(NULL));
    percolate();
    return 0;
}