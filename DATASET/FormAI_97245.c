//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// struct representing a cell in the grid
typedef struct{
    int x;
    int y;
    int isOpen;
} cell;

// array representing the grid
cell grid[ROWS][COLS];

// function to print the grid
void printGrid(){
    printf("\n");
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(grid[i][j].isOpen){
                printf("0");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(){
    srand(time(NULL));
    // initialize the grid
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            grid[i][j].x = i;
            grid[i][j].y = j;
            if(rand()%2 == 1){
                grid[i][j].isOpen = 1;
            } else {
                grid[i][j].isOpen = 0;
            }
        }
    }
    // print the initial grid
    printGrid();
    // simulate percolation
    int percolated = 0;
    for(int i=0;i<COLS;i++){
        if(grid[0][i].isOpen && grid[ROWS-1][i].isOpen){
            percolated = 1;
            break;
        }
    }
    // print the final grid and conclusion
    printGrid();
    if(percolated){
        printf("The liquid has percolated!\n");
    } else {
        printf("The liquid has not percolated...\n");
    }
    return 0;
}