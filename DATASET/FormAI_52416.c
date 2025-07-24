//FormAI DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 // size of the grid
#define GENERATIONS 50 // number of generations to simulate

void printGrid(int grid[][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%c ", grid[i][j] ? '*' : ' '); // print '*' for alive cell, ' ' otherwise
        }
        printf("\n");
    }
    printf("\n");
}

int countNeighbors(int grid[][N], int x, int y){
    int count = 0;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0){ continue; } // exclude the cell itself
            int row = (x+i+N) % N; // wrap around the edges
            int col = (y+j+N) % N;
            count += grid[row][col];
        }
    }
    return count;
}

void updateGrid(int grid[][N]){
    int newGrid[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int neighbors = countNeighbors(grid, i, j);
            if(grid[i][j]){ neighbors--; } // exclude the cell itself
            if(grid[i][j] && (neighbors==2 || neighbors==3)){ newGrid[i][j] = 1; } // keep alive
            else if(!grid[i][j] && neighbors==3){ newGrid[i][j] = 1; } // bring to life
            else{ newGrid[i][j] = 0; } // kill or keep dead
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            grid[i][j] = newGrid[i][j]; // copy the new grid
        }
    }
}

int main(){
    srand(time(NULL)); // use current time as seed for random generator
    int grid[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int random = rand() % 2; // randomly assign 0 or 1
            grid[i][j] = random;
        }
    }
    printGrid(grid);
    for(int g=1; g<=GENERATIONS; g++){
        updateGrid(grid);
        printf("Generation %d:\n", g);
        printGrid(grid);
    }
    return 0;
}