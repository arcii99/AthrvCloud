//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constants for the maze size
#define MAZE_WIDTH 25
#define MAZE_HEIGHT 25

// constants for maze cells
#define MAZE_WALL '#'
#define MAZE_PATH ' '

// function to print the maze
void printMaze(char maze[][MAZE_HEIGHT]) {
    printf("\n");
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            printf("%c ", maze[j][i]);
        }
        printf("\n");
    }
}

// function to generate the maze
void generateMaze(char maze[][MAZE_HEIGHT]) {
    // set all cells to wall
    for (int i = 0; i < MAZE_WIDTH; i++) {
        for (int j = 0; j < MAZE_HEIGHT; j++) {
            maze[i][j] = MAZE_WALL;
        }
    }

    // set the start and end points
    maze[1][1] = MAZE_PATH;
    maze[MAZE_WIDTH - 2][MAZE_HEIGHT - 2] = MAZE_PATH;

    // seed the random number generator
    srand((unsigned) time(NULL));

    // generate the maze
    for (int i = 2; i < MAZE_WIDTH - 2; i += 2) {
        for (int j = 2; j < MAZE_HEIGHT - 2; j += 2) {
            // set cell to path
            maze[i][j] = MAZE_PATH;

            // randomly remove a wall
            int direction = rand() % 4;

            switch (direction) {
                case 0:
                    maze[i - 1][j] = MAZE_PATH;
                    break;
                case 1:
                    maze[i][j - 1] = MAZE_PATH;
                    break;
                case 2:
                    maze[i + 1][j] = MAZE_PATH;
                    break;
                case 3:
                    maze[i][j + 1] = MAZE_PATH;
                    break;
            }
        }
    }
}

// main function
int main() {
    // allocate memory for the maze
    char maze[MAZE_WIDTH][MAZE_HEIGHT];

    // generate the maze
    generateMaze(maze);

    // print the maze
    printMaze(maze);

    return 0;
}