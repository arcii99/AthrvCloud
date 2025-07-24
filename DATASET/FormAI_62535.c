//FormAI DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int grid[HEIGHT][WIDTH];

void initGrid(){
    // Initialize the grid with random values
    srand(time(NULL));
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid(){
    // Print the current state of the grid
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(grid[i][j] == 1){
                printf("* ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
}

int getNeighbors(int row, int col){
    // Get the number of alive neighbors of a cell in the grid
    int count = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int r = row + i;
            int c = col + j;
            if(r >= 0 && r < HEIGHT && c >= 0 && c < WIDTH && grid[r][c] == 1){
                count++;
            }
        }
    }
    if(grid[row][col] == 1){
        count--;
    }
    return count;
}

void updateGrid(){
    // Update the grid based on the rules of the game
    int newGrid[HEIGHT][WIDTH];
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            int neighbors = getNeighbors(i, j);
            if(grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)){
                newGrid[i][j] = 0;
            }
            else if(grid[i][j] == 0 && neighbors == 3){
                newGrid[i][j] = 1;
            }
            else{
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    // Copy the new grid to the original grid
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main(){
    // Initialize the grid and print the initial state
    initGrid();
    printf("Initial State:\n");
    printGrid();
    // Run the game for 50 generations
    for(int i = 1; i <= 50; i++){
        printf("Generation %d:\n", i);
        updateGrid();
        printGrid();
    }
    return 0;
}