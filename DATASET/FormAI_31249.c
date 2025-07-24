//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

void generateMaze(int maze[MAZE_SIZE][MAZE_SIZE]);
void printMaze(int maze[MAZE_SIZE][MAZE_SIZE]);

int main() {
    int maze[MAZE_SIZE][MAZE_SIZE];
    srand(time(NULL));
    generateMaze(maze);
    printMaze(maze);
    return 0;
}

void generateMaze(int maze[MAZE_SIZE][MAZE_SIZE]) {
    // Initialize maze with all walls
    for(int i=0; i<MAZE_SIZE; i++) {
        for(int j=0; j<MAZE_SIZE; j++) {
            maze[i][j] = 15; // 0000 1111: All walls
        }
    }
    // Starting position
    int x = 0;
    int y = 0;
    maze[x][y] -= 8; // Remove top wall
    // Depth First Search algorithm
    int stackX[MAZE_SIZE*MAZE_SIZE];
    int stackY[MAZE_SIZE*MAZE_SIZE];
    int stackSize = 0;
    do {
        // Find all unvisited neighbors
        int neighbors[4];
        int neighborCount = 0;
        if(x > 0 && maze[x-1][y] == 15) { // Top
            neighbors[neighborCount] = 0;
            neighborCount++;
        }
        if(y < MAZE_SIZE-1 && maze[x][y+1] == 15) { // Right
            neighbors[neighborCount] = 1;
            neighborCount++;
        }
        if(x < MAZE_SIZE-1 && maze[x+1][y] == 15) { // Bottom
            neighbors[neighborCount] = 2;
            neighborCount++;
        }
        if(y > 0 && maze[x][y-1] == 15) { // Left
            neighbors[neighborCount] = 3;
            neighborCount++;
        }
        if(neighborCount > 0) {
            // Choose random unvisited neighbor
            int randomIndex = rand() % neighborCount;
            int direction = neighbors[randomIndex];
            // Remove wall between current cell and neighbor
            switch (direction) {
                case 0: // Top
                    maze[x][y] -= 8; // Remove top wall
                    x--;
                    maze[x][y] -= 2; // Remove bottom wall of neighbor
                    break;
                case 1: // Right
                    maze[x][y] -= 4; // Remove right wall
                    y++;
                    maze[x][y] -= 1; // Remove left wall of neighbor
                    break;
                case 2: // Bottom
                    maze[x][y] -= 2; // Remove bottom wall
                    x++;
                    maze[x][y] -= 8; // Remove top wall of neighbor
                    break;
                case 3: // Left
                    maze[x][y] -= 1; // Remove left wall
                    y--;
                    maze[x][y] -= 4; // Remove right wall of neighbor
                    break;
            }
            // Push current cell onto stack
            stackX[stackSize] = x;
            stackY[stackSize] = y;
            stackSize++;
        }
        else if(stackSize > 0) {
            // Pop cell from stack
            stackSize--;
            x = stackX[stackSize];
            y = stackY[stackSize];
        }
    } while(stackSize > 0);
}

void printMaze(int maze[MAZE_SIZE][MAZE_SIZE]) {
    // Print maze
    for(int i=0; i<MAZE_SIZE; i++) {
        // Print top walls
        for(int j=0; j<MAZE_SIZE; j++) {
            printf("+");
            if((maze[i][j] & 8) == 8) { // Top wall
                printf("---");
            }
            else {
                printf("   ");
            }
        }
        printf("+\n");
        // Print left and right walls
        for(int j=0; j<MAZE_SIZE; j++) {
            if((maze[i][j] & 1) == 1) { // Left wall
                printf("|");
            }
            else {
                printf(" ");
            }
            printf("   ");
            if((maze[i][j] & 4) == 4) { // Right wall
                printf("|");
            }
            else {
                printf(" ");
            }
        }
        // Print right wall of last cell in row
        if((maze[i][MAZE_SIZE-1] & 4) == 4) { // Right wall
            printf("|");
        }
        else {
            printf(" ");
        }
        printf("\n");
    }
    // Print bottom walls
    for(int j=0; j<MAZE_SIZE; j++) {
        printf("+");
        if((maze[MAZE_SIZE-1][j] & 2) == 2) { // Bottom wall
            printf("---");
        }
        else {
            printf("   ");
        }
    }
    printf("+\n");
}