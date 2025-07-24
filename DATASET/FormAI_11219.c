//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 //size of the grid
#define BARRIER 2 //value of barrier
#define OPEN 1 //value of open
#define FULL 0 //value of full
#define PERC_THRESHOLD 0.6 //threshold for percolation
#define MAX_ITERATIONS 100000 //maximum number of iterations

//function to initialize the grid with open and barrier cells
void initialize_grid(int grid[SIZE][SIZE], int barrier_value){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(i==0 || j==0 || i==SIZE-1 || j==SIZE-1){
                grid[i][j]=barrier_value; //add barriers around the grid
            }else{
                grid[i][j]=OPEN; //add open cells
            }
        }
    }
}

//function to print the grid
void print_grid(int grid[SIZE][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(grid[i][j] == OPEN){
                printf("."); //print open cell
            }else if(grid[i][j] == FULL){
                printf("X"); //print full cell
            }else{
                printf("#"); //print barrier
            }
        }
        printf("\n");
    }
}

//function to check if the system has percolated
int has_percolated(int grid[SIZE][SIZE]){
    for(int i=1; i<SIZE-1; i++){
        if(grid[1][i]==FULL){//check if there is a FULL cell in the first row
            return 1; //the system has percolated
        }
    }
    return 0; //the system has not percolated
}

//function to simulate percolation
void simulate_percolation(int grid[SIZE][SIZE]){
    int iterations = 0;
    int x, y;

    while(iterations<MAX_ITERATIONS){
        x = rand() % (SIZE-2) + 1; //random x coordinate
        y = rand() % (SIZE-2) + 1; //random y coordinate

        if(grid[x][y]==OPEN){//check if the cell is OPEN
            grid[x][y]=FULL; //fill the cell

            if(has_percolated(grid)){ //check if the system has percolated
                return;
            }
        }
        iterations++;
    }
}

int main(){
    int grid[SIZE][SIZE];

    srand(time(NULL)); //initialize random seed

    initialize_grid(grid, BARRIER); //initialize grid
    simulate_percolation(grid); //simulate percolation
    print_grid(grid); //print the grid

    return 0;
}