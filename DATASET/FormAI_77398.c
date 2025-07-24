//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // grid size

// function to print the grid
void printGrid(int grid[][SIZE]){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) 
            printf("%c ", grid[i][j]);
        
        printf("\n");
    }
}

// function to check if the cell is open
int isOpen(int grid[][SIZE],int row, int col){
    return grid[row][col] == '.';
}

// function to check if the cell is full
int isFull(int grid[][SIZE], int row, int col){

    if(row<0 || row >= SIZE || col<0 || col >= SIZE)
        return 0;
    return grid[row][col] == '#';
}

// function to perculate the grid
void percolation(int grid[][SIZE]){

    for(int j=0;j<SIZE;j++){
        if(isOpen(grid,0,j)){
            grid[0][j] = '#';
            percolation(grid);
        }
    }
    for(int i=1;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(isFull(grid,i-1,j) && isOpen(grid,i,j)){
                grid[i][j] = '#';
                percolation(grid);
            }
        }
    }
}

int main(){
    int grid[SIZE][SIZE];
    char seed;
    srand(time(NULL));
    seed = getchar();
    if(seed == '\n')
        seed = rand()%26 + 'a';
    printf("The seed letter is %c\n", seed);
    srand(seed);
    
    for (int i = 0; i < SIZE; i++) 
        for (int j = 0; j < SIZE; j++)
            grid[i][j] = (rand()%2) ? '.' : ' ';
    
    printf("Initial Grid:\n");
    printGrid(grid);
    printf("\n\nAfter Percolation:\n");
    percolation(grid);
    printGrid(grid);
    
    return 0;
}