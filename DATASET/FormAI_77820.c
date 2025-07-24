//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAZE_SIZE 10

void generateMaze(int maze[MAZE_SIZE][MAZE_SIZE]) {
    // Initialize maze with walls
    for (int i=0; i<MAZE_SIZE; i++) {
        for (int j=0; j<MAZE_SIZE; j++) {
            maze[i][j] = 1;
        }
    }
    
    // Randomly select starting position
    int posX = rand() % MAZE_SIZE;
    int posY = rand() % MAZE_SIZE;
    maze[posX][posY] = 0;
    
    // Loop until all cells are visited
    while (true) {
        // Check available directions
        bool up = (posX > 0) && (maze[posX-1][posY] == 1);
        bool down = (posX < MAZE_SIZE-1) && (maze[posX+1][posY] == 1);
        bool left = (posY > 0) && (maze[posX][posY-1] == 1);
        bool right = (posY < MAZE_SIZE-1) && (maze[posX][posY+1] == 1);
        
        // If no direction available, backtrack
        if (!(up || down || left || right)) {
            bool flag = true;
            while (flag) {
                posX = rand() % MAZE_SIZE;
                posY = rand() % MAZE_SIZE;
                if (maze[posX][posY] == 0) {
                    flag = false;
                }
            }
        }
        
        // Move in random direction
        while (true) {
            int direction = rand() % 4;
            if (direction == 0 && up) {
                maze[posX-1][posY] = 0;
                posX--;
                break;
            } else if (direction == 1 && down) {
                maze[posX+1][posY] = 0;
                posX++;
                break;
            } else if (direction == 2 && left) {
                maze[posX][posY-1] = 0;
                posY--;
                break;
            } else if (direction == 3 && right) {
                maze[posX][posY+1] = 0;
                posY++;
                break;
            }
        }
        
        // Check if all cells are visited
        bool visited = true;
        for (int i=0; i<MAZE_SIZE; i++) {
            for (int j=0; j<MAZE_SIZE; j++) {
                if (maze[i][j] == 1) {
                    visited = false;
                    break;
                }
            }
        }
        if (visited) {
            break;
        }
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Generate maze
    int maze[MAZE_SIZE][MAZE_SIZE];
    generateMaze(maze);
    
    // Print maze
    for (int i=0; i<MAZE_SIZE; i++) {
        for (int j=0; j<MAZE_SIZE; j++) {
            if (maze[i][j] == 1) {
                printf("+ ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    return 0;
}