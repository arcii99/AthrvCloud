//FormAI DATASET v1.0 Category: Game of Life ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 10
#define GENERATIONS 10

int grid[ROWS][COLS]; //The grid representing the current state of the game of life
int temp[ROWS][COLS]; //A temporary grid to hold the next state during computation

//Function to print the grid
void print_grid() {
    printf("\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(grid[i][j]) {
                printf("X ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

//Function to initialize the grid with a random set of initial cells
void initialize_grid() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = rand() % 2; //Each cell has an equal chance of being alive or dead
        }
    }
}

//Function to count the number of living neighbors for a given cell
int count_neighbors(int row, int col) {
    int count = 0;
    for(int i=row-1; i<=row+1; i++) {
        for(int j=col-1; j<=col+1; j++) {
            if(i>=0 && i<ROWS && j>=0 && j<COLS) { //Checking if the neighbor is within the bounds of the grid
                if(!(i==row && j==col) && grid[i][j] == 1) { //Checking if the neighbor is not the current cell and is alive
                    count++;
                }
            }
        }
    }
    return count;
}

//Main function that implements the game of life algorithm
void compute_next_generation() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int count = count_neighbors(i, j);
            if(grid[i][j] == 1) { //If the cell is alive
                if(count<2 || count>3) { //If it has less than 2 or more than 3 living neighbors, it dies
                    temp[i][j] = 0;
                }
                else { //Otherwise, it remains alive
                    temp[i][j] = 1;
                }
            }
            else { //If the cell is dead
                if(count == 3) { //If it has exactly 3 living neighbors, it becomes alive
                    temp[i][j] = 1;
                }
                else { //Otherwise, it remains dead
                    temp[i][j] = 0;
                }
            }
        }
    }

    //Copy the temporary grid to the main grid for the next generation
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = temp[i][j];
        }
    }
}

int main() {
    initialize_grid();
    for(int i=0; i<GENERATIONS; i++) {
        print_grid();
        compute_next_generation();
    }
    return 0;
}