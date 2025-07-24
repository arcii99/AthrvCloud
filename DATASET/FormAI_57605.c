//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generateMaze(int maze[][COLS]);
void printMaze(int maze[][COLS]);

int main() {
    int maze[ROWS][COLS];
    
    srand(time(NULL)); // Seed the random number generator
    
    generateMaze(maze);
    printMaze(maze);
    
    return 0;
}

void generateMaze(int maze[][COLS]) {
    // Initialize maze with all walls
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            maze[i][j] = 1;
        }
    }
    
    // Make first cell the starting point
    maze[0][0] = 0;
    
    int currentRow = 0;
    int currentCol = 0;
    int visitedCells = 1;
    int totalCells = ROWS * COLS;
    
    while(visitedCells < totalCells) {
        int possibleDirections[4]; // Array to store possible directions to move in
        int numDirections = 0; // Number of possible directions
        int nextRow, nextCol;
        
        // Check if cell to left is a valid move
        if(currentCol > 0 && maze[currentRow][currentCol-1] == 1) {
            possibleDirections[numDirections++] = 0; // 0 represents left
        }
        
        // Check if cell above is a valid move
        if(currentRow > 0 && maze[currentRow-1][currentCol] == 1) {
            possibleDirections[numDirections++] = 1; // 1 represents up
        }
        
        // Check if cell to right is a valid move
        if(currentCol < COLS-1 && maze[currentRow][currentCol+1] == 1) {
            possibleDirections[numDirections++] = 2; // 2 represents right
        }
        
        // Check if cell below is a valid move
        if(currentRow < ROWS-1 && maze[currentRow+1][currentCol] == 1) {
            possibleDirections[numDirections++] = 3; // 3 represents down
        }
        
        if(numDirections > 0) {
            int randomDirection = possibleDirections[rand() % numDirections]; // Choose a random direction from the possible directions
            
            switch(randomDirection) {
                case 0: // Move left
                    nextRow = currentRow;
                    nextCol = currentCol - 1;
                    break;
                case 1: // Move up
                    nextRow = currentRow - 1;
                    nextCol = currentCol;
                    break;
                case 2: // Move right
                    nextRow = currentRow;
                    nextCol = currentCol + 1;
                    break;
                case 3: // Move down
                    nextRow = currentRow + 1;
                    nextCol = currentCol;
                    break;
            }
            
            maze[nextRow][nextCol] = 0; // Break down wall of the next cell
            currentRow = nextRow;
            currentCol = nextCol;
            visitedCells++;
        } else {
            int i;
            for(i=0; i<numDirections; i++) {
                printf("%d ", possibleDirections[i]);
            }
            printf("\n");
            
            // Backtrack to a cell with unvisited neighbors
            for(int i=currentRow; i>=0; i--) {
                for(int j=currentCol; j>=0; j--) {
                    if(maze[i][j] == 0) {
                        currentRow = i;
                        currentCol = j;
                        break;
                    }
                }
            }
        }
    }
}

void printMaze(int maze[][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] == 1) {
                printf("#"); // Wall
            } else {
                printf(" "); // Path
            }
        }
        printf("\n");
    }
}