//FormAI DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20 // define number of rows
#define COLS 40 // define number of columns

int grid[ROWS][COLS];

int get_random(){
    return rand() % 2; // returns a random integer 0 or 1
}

void set_initial_state(){
    srand(time(0)); // set the seed of the random number generator

    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            grid[i][j] = get_random(); // set each cell to a random value
        }
    }
}

void display_grid(){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(grid[i][j] == 0){
                printf("."); // print a dot for a dead cell
            } else {
                printf("*"); // print an asterisk for a live cell
            }
        }
        printf("\n"); // move to the next line after each row
    }
}

int get_cell_state(int i, int j){
    if(i<0 || i>=ROWS || j<0 || j>=COLS){
        return 0; // if the cell is out of bounds, return 0 to indicate it is dead
    } else {
        return grid[i][j];
    }
}

int get_neighbor_count(int i, int j){
    int count = 0;
    count += get_cell_state(i-1, j-1);
    count += get_cell_state(i-1, j);
    count += get_cell_state(i-1, j+1);
    count += get_cell_state(i, j-1);
    count += get_cell_state(i, j+1);
    count += get_cell_state(i+1, j-1);
    count += get_cell_state(i+1, j);
    count += get_cell_state(i+1, j+1);
    return count;
}

void update_grid(){
    int new_grid[ROWS][COLS];

    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            int count = get_neighbor_count(i, j);

            if(count < 2 || count > 3){
                new_grid[i][j] = 0; // if the cell has fewer than 2 or more than 3 neighbors, it dies
            } else if(count == 3){
                new_grid[i][j] = 1; // if the cell has 3 neighbors, it comes to life or stays alive
            } else {
                new_grid[i][j] = grid[i][j]; // if the cell has 2 neighbors, it stays in its current state
            }
        }
    }

    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            grid[i][j] = new_grid[i][j]; // copy the updated grid to the original grid
        }
    }
}

int main(){
    set_initial_state(); // set the initial state of the grid
    for(int i=0; i<10; i++){
        printf("Generation %d:\n", i+1);
        display_grid(); // display the grid
        update_grid(); // update the grid
        printf("\n");
    }

    return 0;
}