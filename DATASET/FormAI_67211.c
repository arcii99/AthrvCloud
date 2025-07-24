//FormAI DATASET v1.0 Category: Game of Life ; Style: surrealist
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

// Define grid size 
#define ROW 10
#define COL 10

// Define function to initialize the grid randomly 
void initializeGrid(int grid[][COL]) { 

    srand(time(NULL));
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j] = rand() % 2;
        }
    }
} 

// Define function to print the grid 
void printGrid(int grid[][COL]) { 

    printf("\n\n");      
    printf("------------------------------\n");
    for (int i = 0; i < ROW; i++) { 

        for (int j = 0; j < COL; j++) { 

            if (grid[i][j] == 1) 
                printf("|*"); 
            else
                printf("| "); 
        } 
        printf("|\n"); 
        printf("------------------------------\n");
    } 
} 

// Define function to calculate next generation 
void nextGeneration(int grid[][COL]) { 

    int newGrid[ROW][COL]; 

    for (int i = 1; i < ROW - 1; i++) { 
        for (int j = 1; j < COL - 1; j++) { 

            int aliveNeighbours = 0; 

            for (int k = -1; k <= 1; k++){
                for (int l = -1; l <= 1; l++){
                    aliveNeighbours += grid[i+k][j+l]; 
                }
            }

            aliveNeighbours -= grid[i][j]; 

            if ((grid[i][j] == 1) && (aliveNeighbours < 2)) 
                newGrid[i][j] = 0; 
            else if ((grid[i][j] == 1) && (aliveNeighbours > 3)) 
                newGrid[i][j] = 0; 
            else if ((grid[i][j] == 0) && (aliveNeighbours == 3)) 
                newGrid[i][j] = 1; 
            else
                newGrid[i][j] = grid[i][j]; 
        } 
    } 

    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            grid[i][j] = newGrid[i][j]; 
        }
    }
} 

// Define main function 
int main() {
    
    int grid[ROW][COL] = {0}; 

    initializeGrid(grid);
    printGrid(grid); 

    getchar();
    while (1) {

        system("clear");
        nextGeneration(grid);
        printGrid(grid); 

        getchar(); 
    } 

    return 0; 
}