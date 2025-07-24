//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAZE_HEIGHT 10
#define MAZE_WIDTH 10
#define WALL_CHAR 'X'
#define PATH_CHAR ' '
#define START_CHAR 'S'
#define END_CHAR 'E'

// Function Prototypes
void generateMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH]);
void printMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH]);

// Main Function
int main(void) {
    // Initialize the random number generator
    srand(time(NULL));

    // Declare the maze array
    char maze[MAZE_HEIGHT][MAZE_WIDTH];

    // Generate the maze
    generateMaze(maze);

    // Print the maze
    printMaze(maze);

    return 0;
}

// Function to generate a random maze
void generateMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    // Initialize the maze with all walls
    for(int i=0; i<MAZE_HEIGHT; i++) {
        for(int j=0; j<MAZE_WIDTH; j++) {
            maze[i][j] = WALL_CHAR;
        }
    }

    // Choose a random starting point
    int startX = rand() % MAZE_WIDTH;
    int startY = rand() % MAZE_HEIGHT;

    // Set the start point
    maze[startY][startX] = START_CHAR;

    // Choose a random ending point different from the start point
    int endX, endY;
    do {
        endX = rand() % MAZE_WIDTH;
        endY = rand() % MAZE_HEIGHT;
    } while(endX == startX && endY == startY);

    // Set the end point
    maze[endY][endX] = END_CHAR;

    // Randomly carve out the maze paths
    int currentX = startX, currentY = startY;
    while(currentX != endX || currentY != endY) {
        // Pick a random direction
        int direction = rand() % 4;

        // Try to move in that direction
        switch(direction) {
            case 0: // Up
                if(currentY > 0 && maze[currentY-1][currentX] == WALL_CHAR) {
                    maze[currentY-1][currentX] = PATH_CHAR;
                    currentY--;
                }
                break;
            case 1: // Down
                if(currentY < MAZE_HEIGHT-1 && maze[currentY+1][currentX] == WALL_CHAR) {
                    maze[currentY+1][currentX] = PATH_CHAR;
                    currentY++;
                }
                break;
            case 2: // Left
                if(currentX > 0 && maze[currentY][currentX-1] == WALL_CHAR) {
                    maze[currentY][currentX-1] = PATH_CHAR;
                    currentX--;
                }
                break;
            case 3: // Right
                if(currentX < MAZE_WIDTH-1 && maze[currentY][currentX+1] == WALL_CHAR) {
                    maze[currentY][currentX+1] = PATH_CHAR;
                    currentX++;
                }
                break;
        }
    }
}

// Function to print the maze
void printMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    for(int i=0; i<MAZE_HEIGHT; i++) {
        for(int j=0; j<MAZE_WIDTH; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}