//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void printGrid(int grid[SIZE][SIZE], int count){
    printf("Iteration %d:\n",count);
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(grid[i][j] == -1){
                printf("|W");
            }
            else if(grid[i][j] == 1){
                printf("|B");
            }
            else{
                printf("|_");
            }
        }
        printf("|\n");
    }
}

int percolate(int grid[SIZE][SIZE]){
    int connections[SIZE][SIZE] = {0};
    int count = 0;
    while(1){
        int flag = 0;
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                if(grid[i][j] == -1){
                    if(i-1 >= 0){ // Check north cell
                        if(grid[i-1][j] == 1){
                            connections[i][j] = 1;
                            grid[i][j] = 1;
                            flag = 1;
                        }
                    }
                    if(j-1 >= 0){ // Check west cell
                        if(grid[i][j-1] == 1){
                            connections[i][j] = 1;
                            grid[i][j] = 1;
                            flag = 1;
                        }
                    }
                    if(i+1 < SIZE){ // Check south cell
                        if(grid[i+1][j] == 1){
                            connections[i][j] = 1;
                            grid[i][j] = 1;
                            flag = 1;
                        }
                    }
                    if(j+1 < SIZE){ // Check east cell
                        if(grid[i][j+1] == 1){
                            connections[i][j] = 1;
                            grid[i][j] = 1;
                            flag = 1;
                        }
                    }
                }
            }
        }
        if(flag == 0){
            break;
        }
        count++;
        printGrid(grid,count);
        printf("\n");
    }
    for(int i = 0; i < SIZE; i++){
        if(connections[0][i] == 1){
            return 1;
        }
    }
    return 0;
}

int main(){
    srand(time(NULL));
    int grid[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(rand()%100 < 50){
                grid[i][j] = -1;
            }
            else{
                grid[i][j] = 0;
            }
        }
    }
    printf("Initial grid:\n");
    printGrid(grid,0);
    printf("\n");
    int result = percolate(grid);
    if(result == 1){
        printf("Percolation occured!\n");
    }
    else{
        printf("Percolation did not occur!\n");
    }
    return 0;
}