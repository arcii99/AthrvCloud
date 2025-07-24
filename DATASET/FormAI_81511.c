//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maze dimensions
#define WIDTH 20
#define HEIGHT 10

// Maze cell states
#define CELL_WALL 0
#define CELL_PATH 1
#define CELL_START 2
#define CELL_END 3

// Function prototypes
void generateMaze(int maze[HEIGHT][WIDTH], int startX, int startY);
void printMaze(int maze[HEIGHT][WIDTH]);

int main() {
    // Set up random seed
    srand(time(NULL));
    
    // Initialize maze to all walls
    int maze[HEIGHT][WIDTH] = {0};
    
    // Generate maze starting from (1, 1)
    generateMaze(maze, 1, 1);
    
    // Add start and end points
    maze[1][0] = CELL_START;
    maze[HEIGHT - 2][WIDTH - 1] = CELL_END;
    
    // Print maze
    printMaze(maze);
    
    return 0;
}

void generateMaze(int maze[HEIGHT][WIDTH], int startX, int startY) {
    // Mark the starting cell as part of the maze
    maze[startY][startX] = CELL_PATH;
    
    // Possible directions to move from current cell
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Shuffle directions randomly
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int tempX = directions[i][0];
        int tempY = directions[i][1];
        directions[i][0] = directions[j][0];
        directions[i][1] = directions[j][1];
        directions[j][0] = tempX;
        directions[j][1] = tempY;
    }
    
    // Repeat for each direction
    for (int i = 0; i < 4; i++) {
        int newX = startX + directions[i][1];
        int newY = startY + directions[i][0];
        
        // Check if new cell is within bounds and not already in maze
        if (newY > 0 && newY < HEIGHT - 1 && newX > 0 && newX < WIDTH - 1 && maze[newY][newX] == CELL_WALL) {
            // Mark the new cell as part of the maze
            maze[newY][newX] = CELL_PATH;
            
            // Recursively call generateMaze with new cell as starting point
            generateMaze(maze, newX, newY);
        }
    }
}

void printMaze(int maze[HEIGHT][WIDTH]) {
    // Print top border
    printf("+");
    for (int i = 0; i < WIDTH; i++) {
        printf("-");
    }
    printf("+\n");
    
    // Print maze cells
    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            switch (maze[i][j]) {
                case CELL_WALL:
                    printf("#");
                    break;
                case CELL_PATH:
                    printf(" ");
                    break;
                case CELL_START:
                    printf("S");
                    break;
                case CELL_END:
                    printf("E");
                    break;
            }
        }
        printf("|\n");
    }
    
    // Print bottom border
    printf("+");
    for (int i = 0; i < WIDTH; i++) {
        printf("-");
    }
    printf("+\n");
}