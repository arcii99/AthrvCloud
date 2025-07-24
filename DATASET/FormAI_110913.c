//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: puzzling
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

//Function to check if a cell is open
bool is_open(int x, int y, bool grid[][ROWS+2]){
    return grid[x][y];
}

//Function to open a cell
void open(int x, int y, bool grid[][ROWS+2]){
    grid[x][y] = true;
}

//Function to check if a cell is full
bool is_full(int x, int y, bool grid[][ROWS+2]){
    //Base Case
    if (x < 1 || x > ROWS || y < 1 || y > COLS) {
        return false;
    }
    if (!is_open(x, y, grid)) {
        return false;
    }
    // Mark the current cell as full
    grid[x][y] = false;
    bool full_top = is_full(x-1, y, grid);
    bool full_bottom = is_full(x+1, y, grid);
    bool full_left = is_full(x, y-1, grid);
    bool full_right = is_full(x, y+1, grid);
    return full_top || full_bottom || full_left || full_right;
}

//Percolation Function
bool percolate(bool grid[][ROWS+2]){
    //Mark all the cells in the first row as full
    for (int i = 1; i <= COLS; i++) {
        if (is_open(1, i, grid)) {
            open(1, i, grid);
            is_full(1, i, grid);
        }
    }
    //Check if the last row is open and full
    for (int i = 1; i <= COLS; i++) {
        if (is_open(ROWS, i, grid) && is_full(ROWS, i, grid)) {
            return true;
        }
    }
    return false;
}

int main() {
    bool grid[ROWS+2][COLS+2];
    //Fill the grid with false values (unopened cells)
    for(int i=1; i<=ROWS; i++){
        for(int j=1; j<=COLS; j++){
            grid[i][j] = false;
        }
    }
    //Seed the random number generator
    srand(time(NULL));
    //Open random cells in the grid
    for(int i=1; i<=ROWS; i++){
        for(int j=1; j<=COLS; j++){
            if(rand()%2==0){
                open(i,j,grid);
            }
        }
    }
    //Run percolation simulation and print the result
    if(percolate(grid)){
        printf("The system percolates.\n");
    }else{
        printf("The system does not percolate.\n");
    }
    
    return 0;
}