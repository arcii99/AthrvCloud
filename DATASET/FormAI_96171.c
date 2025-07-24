//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 21

// Function declarations
void createMaze(char maze[][COLS]);
void printMaze(char maze[][COLS]);

int main() {
    char maze[ROWS][COLS];
    srand(time(NULL)); // Seed the random number generator
    
    // Fill the maze with walls
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            if(row % 2 == 0 || col % 2 == 0)
                maze[row][col] = '#'; // Wall
            else
                maze[row][col] = '.'; // Path
        }
    }
    
    // Create the maze
    createMaze(maze);
    
    // Print the maze
    printMaze(maze);
    
    return 0;
}

void createMaze(char maze[][COLS]) {
    // Starting coordinates
    int x = 1;
    int y = 1;
    
    // Mark starting point as visited
    maze[y][x] = ' ';
    
    // Loop until all cells have been visited
    while(1) {
        // Create a list of neighboring cells
        int neighbors[4][2] = {{-2, 0}, {0, -2}, {2, 0}, {0, 2}};
        
        // Shuffle the neighbors
        for(int i = 0; i < 4; i++) {
            int swapIndex = rand() % 4;
            int tempX = neighbors[swapIndex][0];
            int tempY = neighbors[swapIndex][1];
            neighbors[swapIndex][0] = neighbors[i][0];
            neighbors[swapIndex][1] = neighbors[i][1];
            neighbors[i][0] = tempX;
            neighbors[i][1] = tempY;
        }
        
        int foundNeighbor = 0;
        
        // Try to find a neighbor that has not been visited yet
        for(int i = 0; i < 4; i++) {
            int neighborX = x + neighbors[i][0];
            int neighborY = y + neighbors[i][1];
            
            if(neighborX < 1 || neighborX >= COLS || neighborY < 1 || neighborY >= ROWS)
                continue; // Neighbor is outside the boundary
            
            if(maze[neighborY][neighborX] == '#') {
                // Mark the neighbor as visited and remove the wall
                maze[neighborY][neighborX] = ' ';
                maze[y+(neighbors[i][1]/2)][x+(neighbors[i][0]/2)] = ' ';
                
                // Move to the neighbor cell
                x = neighborX;
                y = neighborY;
                
                foundNeighbor = 1;
                break;
            }
        }
        
        // If no unvisited neighbor was found, backtrack to a previous cell
        if(!foundNeighbor) {
            int backTrack = 0;
            for(int row = 1; row < ROWS-1 && !backTrack; row += 2) {
                for(int col = 1; col < COLS-1 && !backTrack; col += 2) {
                    if(maze[row][col] == ' ') {
                        // Check if any neighboring cells are unvisited
                        int visitedNeighbors = 0;
                        for(int i = 0; i < 4; i++) {
                            int neighborX = col + neighbors[i][0];
                            int neighborY = row + neighbors[i][1];
                            
                            if(maze[neighborY][neighborX] == ' ')
                                visitedNeighbors++;
                        }
                        
                        if(visitedNeighbors < 2) {
                            // Backtrack to this cell
                            x = col;
                            y = row;
                            backTrack = 1;
                        }
                    }
                }
            }
            
            if(!backTrack)
                break; // All cells have been visited
        }
    }      
}

void printMaze(char maze[][COLS]) {
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            printf("%c", maze[row][col]);
        }
        printf("\n");
    }
}