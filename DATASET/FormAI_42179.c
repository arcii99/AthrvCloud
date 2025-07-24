//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 21 // This should be an odd integer

int maze[MAZE_SIZE][MAZE_SIZE];

void generateMaze() {
    // Initialize maze with walls everywhere
    for(int i=0; i<MAZE_SIZE; i++) {
        for(int j=0; j<MAZE_SIZE; j++) {
            if(i%2 == 1 && j%2 == 1) {
                maze[i][j] = 0; // This is where the paths will be
            } else {
                maze[i][j] = 1; // This is where the walls will be
            }
        }
    }

    // Randomly remove walls to create a path
    srand(time(0));
    int start = rand() % (MAZE_SIZE-2) + 1; // Start at a random odd row
    maze[start][0] = 0; // Create entrance at leftmost wall
    int currentRow = start;
    int currentCol = 1;

    while(currentCol < MAZE_SIZE-1) {
        int direction = rand() % 4 + 1; // Choose a random direction
        switch(direction) {
            case 1: // Up
                if(currentRow-2 >= 0 && maze[currentRow-2][currentCol] == 1) {
                    maze[currentRow-1][currentCol] = 0;
                    maze[currentRow-2][currentCol] = 0;
                    currentRow -= 2;
                }
                break;
            case 2: // Right
                if(currentCol+2 < MAZE_SIZE-1 && maze[currentRow][currentCol+2] == 1) {
                    maze[currentRow][currentCol+1] = 0;
                    maze[currentRow][currentCol+2] = 0;
                    currentCol += 2;
                }
                break;
            case 3: // Down
                if(currentRow+2 < MAZE_SIZE-1 && maze[currentRow+2][currentCol] == 1) {
                    maze[currentRow+1][currentCol] = 0;
                    maze[currentRow+2][currentCol] = 0;
                    currentRow += 2;
                }
                break;
            case 4: // Left
                if(currentCol-2 >= 1 && maze[currentRow][currentCol-2] == 1) {
                    maze[currentRow][currentCol-1] = 0;
                    maze[currentRow][currentCol-2] = 0;
                    currentCol -= 2;
                }
                break;
        }
    }

    maze[start][MAZE_SIZE-1] = 0; // Create exit at rightmost wall
}

void printMaze() {
    for(int i=0; i<MAZE_SIZE; i++) {
        for(int j=0; j<MAZE_SIZE; j++) {
            if(maze[i][j] == 1) {
                printf("█"); // Wall
            } else {
                printf(" "); // Path
            }
        }
        printf("\n");
    }
}

int main() {
    generateMaze();
    printMaze();
    return 0;
}