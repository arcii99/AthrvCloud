//FormAI DATASET v1.0 Category: Game of Life ; Style: invasive
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
  
#define ROW 20
#define COL 20

int grid[ROW][COL]; 
  
void initialize() 
{ 
    int i, j; 
  
    // Initialize the grid with random values 
    for (i = 0; i < ROW; i++) 
        for (j = 0; j < COL; j++) 
            grid[i][j] = rand() % 2; 
} 
  
void printGrid() 
{ 
    int i, j; 
  
    for (i = 0; i < COL; i++) { 
        for (j = 0; j < ROW; j++) 
            printf("%c ", grid[i][j] ? '#' : '-'); 
        printf("\n"); 
    } 
} 

int countNeighbours(int row, int col) 
{ 
    int count = 0; 
  
    // Count the neighbours of the cell 
    for (int i = -1; i <= 1; i++) 
        for (int j = -1; j <= 1; j++) 
            count += grid[row + i][col + j]; 
  
    // Subtract the current cell 
    count -= grid[row][col]; 
    return count; 
} 

void updateGrid() 
{ 
    int i, j; 
  
    // Create a new grid and copy the values from the old one 
    int newGrid[ROW][COL]; 
    for (i = 1; i < ROW - 1; i++) 
        for (j = 1; j < COL - 1; j++) { 
            int neighbours = countNeighbours(i, j); 
  
            if (grid[i][j] == 1 && neighbours < 2) 
                newGrid[i][j] = 0; 
            else if (grid[i][j] == 1 && neighbours > 3) 
                newGrid[i][j] = 0; 
            else if (grid[i][j] == 0 && neighbours == 3) 
                newGrid[i][j] = 1; 
            else
                newGrid[i][j] = grid[i][j]; 
        } 
  
    // Copy the new grid to the old one 
    for (i = 1; i < ROW - 1; i++) 
        for (j = 1; j < COL - 1; j++) 
            grid[i][j] = newGrid[i][j]; 
} 

int main() 
{ 
    srand(time(NULL)); 
    initialize(); 
  
    while (1) { 
        printf("Current status of the grid:\n"); 
        printGrid(); 
        printf("\n"); 
  
        updateGrid(); 
  
        // Wait for some time to see the changes 
        sleep(1); 
    } 
  
    return 0; 
}