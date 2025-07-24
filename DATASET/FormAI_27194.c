//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

void createMaze(int maze[ROWS][COLS]) {
    int i, j;
    srand((unsigned int)time(NULL));
    
    // Set all cells to walls
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            maze[i][j] = 1; // 1 represents a wall
        }
    }
    
    // Carve out the maze starting from (0,0)
    int currX = 0, currY = 0;
    maze[currX][currY] = 0; // 0 represents a walkway
    
    while(1) {
        // Find neighbors for current cell
        int northX = currX - 2, northY = currY;
        int southX = currX + 2, southY = currY;
        int eastX = currX, eastY = currY + 2;
        int westX = currX, westY = currY - 2;
        
        // Count number of available neighbors
        int numAvailableNeighbors = 0;
        int availableNeighbors[4] = {-1, -1, -1, -1};
        
        if(northX >= 0 && maze[northX][northY] == 1) {
            availableNeighbors[numAvailableNeighbors] = 0;
            numAvailableNeighbors++;
        }
        
        if(southX < ROWS && maze[southX][southY] == 1) {
            availableNeighbors[numAvailableNeighbors] = 1;
            numAvailableNeighbors++;
        }
        
        if(eastY < COLS && maze[eastX][eastY] == 1) {
            availableNeighbors[numAvailableNeighbors] = 2;
            numAvailableNeighbors++;
        }
        
        if(westY >= 0 && maze[westX][westY] == 1) {
            availableNeighbors[numAvailableNeighbors] = 3;
            numAvailableNeighbors++;
        }
        
        // If no neighbors are available, backtrack until a cell with available neighbors is found
        if(numAvailableNeighbors == 0) {
            int backX = currX, backY = currY;
            while(1) {
                if(backX == 0 && backY == 0) {
                    return;
                }
                
                if(backY > 0 && maze[backX][backY - 1] == 0) {
                    backY -= 2;
                    break;
                }
                
                if(backX > 0 && maze[backX - 1][backY] == 0) {
                    backX -= 2;
                    break;
                }
                
                if(backY < COLS - 1 && maze[backX][backY + 1] == 0) {
                    backY += 2;
                    break;
                }
                
                if(backX < ROWS - 1 && maze[backX + 1][backY] == 0) {
                    backX += 2;
                    break;
                }
                
                maze[backX][backY] = 2; // 2 represents a dead end
                if(backY > 0) {
                    backY -= 2;
                }
                else {
                    backX--;
                    backY = COLS - 1;
                }
            }
            
            currX = backX;
            currY = backY;
        }
        // Choose a random neighbor and carve a path
        else {
            int chosenNeighbor = availableNeighbors[rand() % numAvailableNeighbors];
            
            if(chosenNeighbor == 0) {
                maze[currX - 1][currY] = 0;
                currX -= 2;
            }
            else if(chosenNeighbor == 1) {
                maze[currX + 1][currY] = 0;
                currX += 2;
            }
            else if(chosenNeighbor == 2) {
                maze[currX][currY + 1] = 0;
                currY += 2;
            }
            else {
                maze[currX][currY - 1] = 0;
                currY -= 2;
            }
        }
    }
}

void printMaze(int maze[ROWS][COLS]) {
    int i, j;
    
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(maze[i][j] == 0) {
                printf(" ");
            }
            else if(maze[i][j] == 1) {
                printf("#");
            }
            else if(maze[i][j] == 2) {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[ROWS][COLS];
    createMaze(maze);
    printMaze(maze);
    return 0;
}