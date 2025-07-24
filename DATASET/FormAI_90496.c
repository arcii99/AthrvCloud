//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

int maze[MAZE_SIZE][MAZE_SIZE]; // Global array to store the maze

void generateMaze(int row, int col) {
    int r, c, i;
    maze[row][col] = 0; // Mark the current cell as visited
    
    // Possible moves from current cell
    int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, down, left, right
    
    // Shuffle the moves array
    for(i=0; i<4; i++) {
        int tempRow = row + moves[i][0];
        int tempCol = col + moves[i][1];
        
        // Check if the move doesn't go out of bounds
        if(tempRow >=1 && tempRow < MAZE_SIZE-1 && tempCol >= 1 && tempCol < MAZE_SIZE-1 && maze[tempRow][tempCol] != 0) {
            int j = rand() % 4;
            int temp = moves[j][0];
            moves[j][0] = moves[i][0];
            moves[i][0] = temp;
            temp = moves[j][1];
            moves[j][1] = moves[i][1];
            moves[i][1] = temp;
        }
    }
    
    // Recursively visit the neighboring cells
    for(i=0; i<4; i++) {
        r = row + moves[i][0];
        c = col + moves[i][1];
        
        if(maze[r][c] == 1) {
            maze[(row+r)/2][(col+c)/2] = 0;
            generateMaze(r, c);
        }
    }
}

// Helper function to print the maze
void printMaze() {
    int i, j;
    for(i=0; i<MAZE_SIZE; i++) {
        for(j=0; j<MAZE_SIZE; j++) {
            if(maze[i][j] == 1) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand((unsigned) time(NULL));
    int i, j;
    
    // Initialize the maze
    for(i=0; i<MAZE_SIZE; i++) {
        for(j=0; j<MAZE_SIZE; j++) {
            if(i == 0 || j == 0 || i == MAZE_SIZE-1 || j == MAZE_SIZE-1) {
                maze[i][j] = 1; // Boundaries
            } else {
                maze[i][j] = 2; // Unvisited
            }
        }
    }
    
    // Generate the maze starting from the center
    generateMaze(MAZE_SIZE/2, MAZE_SIZE/2);
    
    // Print the maze
    printMaze();
    
    return 0;
}