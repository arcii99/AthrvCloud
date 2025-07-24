//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define dimensions of maze
#define MAZE_WIDTH 15
#define MAZE_HEIGHT 10

// Define cell values for maze
#define WALL 1
#define SPACE 0

// Define function to print maze
void print_maze(int maze[MAZE_WIDTH][MAZE_HEIGHT]) {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            if (maze[x][y] == WALL) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize maze with all walls
    int maze[MAZE_WIDTH][MAZE_HEIGHT] = {0};
    for (int x = 0; x < MAZE_WIDTH; x++) {
        for (int y = 0; y < MAZE_HEIGHT; y++) {
            maze[x][y] = WALL;
        }
    }
    
    // Choose random starting position
    int startX = rand() % MAZE_WIDTH;
    int startY = rand() % MAZE_HEIGHT;
    maze[startX][startY] = SPACE;
    
    // Generate maze
    int currentX = startX, currentY = startY;
    while (1) {
        // Check if maze is complete
        int spacesFound = 0;
        for (int x = 0; x < MAZE_WIDTH; x++) {
            for (int y = 0; y < MAZE_HEIGHT; y++) {
                if (maze[x][y] == SPACE) {
                    spacesFound++;
                }
            }
        }
        if (spacesFound == MAZE_WIDTH * MAZE_HEIGHT) {
            break;
        }
        
        // Choose random direction to move
        int direction = rand() % 4;
        if (direction == 0 && currentX > 0 && maze[currentX - 1][currentY] == WALL) {
            maze[currentX - 1][currentY] = SPACE;
            currentX--;
        } else if (direction == 1 && currentX < MAZE_WIDTH - 1 && maze[currentX + 1][currentY] == WALL) {
            maze[currentX + 1][currentY] = SPACE;
            currentX++;
        } else if (direction == 2 && currentY > 0 && maze[currentX][currentY - 1] == WALL) {
            maze[currentX][currentY - 1] = SPACE;
            currentY--;
        } else if (direction == 3 && currentY < MAZE_HEIGHT - 1 && maze[currentX][currentY + 1] == WALL) {
            maze[currentX][currentY + 1] = SPACE;
            currentY++;
        }
    }
    
    // Print maze
    print_maze(maze);
    
    return 0;
}