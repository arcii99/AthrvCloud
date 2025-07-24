//FormAI DATASET v1.0 Category: Game of Life ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
    Happy Game of Life Program
    Written By [Your Name]
*/

#define ROWS 25
#define COLS 50

// Function to initialize the grid with random cells
void initializeGrid(int grid[][COLS]) {
    int i, j;
    srand(time(0));
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the grid
void printGrid(int grid[][COLS]) {
    int i, j;
    printf("------------------------\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] == 1 ? '*' : '-');
        }
        printf("\n");
    }
    printf("------------------------\n\n");
}

// Function to update the cells based on the game rules
void updateCells(int grid[][COLS]) {
    int i, j, neighbours;
    int temp[ROWS][COLS];
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            neighbours = 0;
            if(i > 0 && grid[i-1][j] == 1) neighbours++; // top cell
            if(i < ROWS-1 && grid[i+1][j] == 1) neighbours++; // bottom cell
            if(j > 0 && grid[i][j-1] == 1) neighbours++; // left cell
            if(j < COLS-1 && grid[i][j+1] == 1) neighbours++; // right cell
            if(i > 0 && j > 0 && grid[i-1][j-1] == 1) neighbours++; // top-left cell
            if(i > 0 && j < COLS-1 && grid[i-1][j+1] == 1) neighbours++; // top-right cell
            if(i < ROWS-1 && j > 0 && grid[i+1][j-1] == 1) neighbours++; // bottom-left cell
            if(i < ROWS-1 && j < COLS-1 && grid[i+1][j+1] == 1) neighbours++; // bottom-right cell
            
            if(grid[i][j] == 1) {
                if(neighbours < 2 || neighbours > 3) {
                    temp[i][j] = 0; // cell dies
                } else {
                    temp[i][j] = 1; // cell survives
                }
            } else {
                if(neighbours == 3) {
                    temp[i][j] = 1; // cell is born
                } else {
                    temp[i][j] = 0; // cell remains dead
                }
            }
        }
    }
    // update the original grid with new cells
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            grid[i][j] = temp[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    int generation = 0;
    initializeGrid(grid);
    printf("Welcome to Happy Game of Life!\n\n");
    while(1) {
        printf("Generation: %d\n", generation++);
        printGrid(grid);
        updateCells(grid);
    }
    return 0;
}