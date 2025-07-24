//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for maze size
#define MAZE_ROWS 13
#define MAZE_COLS 17

// Define constants for direction
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

// Define constants for cell state
#define CELL_VISITED 0x10
#define HAS_NORTH_WALL 0x01
#define HAS_EAST_WALL 0x02
#define HAS_SOUTH_WALL 0x04
#define HAS_WEST_WALL 0x08

// Define struct for maze cell
typedef struct MazeCell {
    unsigned char state;
} MazeCell;

// Function to get a random integer within a range
int randomIntInRange(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to print the maze
void printMaze(MazeCell maze[][MAZE_COLS]) {
    printf("\n");
    for (int row = 0; row < MAZE_ROWS; row++) {
        for (int col = 0; col < MAZE_COLS; col++) {
            if (maze[row][col].state & HAS_NORTH_WALL) {
                printf("+--");
            } else {
                printf("+  ");
            }
        }
        printf("+\n");
        for (int col = 0; col < MAZE_COLS; col++) {
            if (maze[row][col].state & HAS_WEST_WALL) {
                printf("|  ");
            } else {
                printf("   ");
            }
        }
        printf("|\n");
    }
    for (int col = 0; col < MAZE_COLS; col++) {
        printf("+--");
    }
    printf("+\n\n");
}

// Function to generate the maze
void generateMaze(MazeCell maze[][MAZE_COLS], int currentRow, int currentCol) {
    // Mark current cell as visited
    maze[currentRow][currentCol].state |= CELL_VISITED;
    
    // Randomly shuffle the directions
    int directions[4] = {NORTH, EAST, SOUTH, WEST};
    for (int i = 0; i < 4; i++) {
        int j = randomIntInRange(i, 3);
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }
    
    // Iterate over the directions
    for (int i = 0; i < 4; i++) {
        int direction = directions[i];
        
        // Calculate the row and column of the neighbor based on the direction
        int neighborRow = currentRow;
        int neighborCol = currentCol;
        if (direction == NORTH) {
            neighborRow--;
        } else if (direction == EAST) {
            neighborCol++;
        } else if (direction == SOUTH) {
            neighborRow++;
        } else if (direction == WEST) {
            neighborCol--;
        }
        
        if (neighborRow >= 0 && neighborRow < MAZE_ROWS && neighborCol >= 0 && neighborCol < MAZE_COLS) {
            if (!(maze[neighborRow][neighborCol].state & CELL_VISITED)) {
                // Remove the wall between the current cell and the neighbor
                if (direction == NORTH) {
                    maze[currentRow][currentCol].state &= ~HAS_NORTH_WALL;
                    maze[neighborRow][neighborCol].state &= ~HAS_SOUTH_WALL;
                } else if (direction == EAST) {
                    maze[currentRow][currentCol].state &= ~HAS_EAST_WALL;
                    maze[neighborRow][neighborCol].state &= ~HAS_WEST_WALL;
                } else if (direction == SOUTH) {
                    maze[currentRow][currentCol].state &= ~HAS_SOUTH_WALL;
                    maze[neighborRow][neighborCol].state &= ~HAS_NORTH_WALL;
                } else if (direction == WEST) {
                    maze[currentRow][currentCol].state &= ~HAS_WEST_WALL;
                    maze[neighborRow][neighborCol].state &= ~HAS_EAST_WALL;
                }
                
                // Recursively generate the maze starting from the neighbor
                generateMaze(maze, neighborRow, neighborCol);
            }
        }
    }
}

int main() {
    // Initialize the maze with all walls
    MazeCell maze[MAZE_ROWS][MAZE_COLS];
    for (int row = 0; row < MAZE_ROWS; row++) {
        for (int col = 0; col < MAZE_COLS; col++) {
            maze[row][col].state = HAS_NORTH_WALL | HAS_EAST_WALL | HAS_SOUTH_WALL | HAS_WEST_WALL;
        }
    }
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate the maze starting from the top-left corner
    generateMaze(maze, 0, 0);
    
    // Print the maze
    printMaze(maze);
    
    return 0;
}