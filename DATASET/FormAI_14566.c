//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constants
#define WIDTH 21
#define HEIGHT 21
#define WALL 219
#define SPACE ' '

// function declarations
void generate_maze(int maze[HEIGHT][WIDTH]);
void print_maze(int maze[HEIGHT][WIDTH]);

// main function
int main() {
    int maze[HEIGHT][WIDTH];
    srand(time(NULL));
    generate_maze(maze);
    print_maze(maze);
    return 0;
}

// function to generate the maze
void generate_maze(int maze[HEIGHT][WIDTH]) {
    int i, j;
    // initialize the maze with all walls
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            maze[i][j] = WALL;
        }
    }
    // carve out the maze one cell at a time
    for (i = 1; i < HEIGHT-1; i += 2) {
        for (j = 1; j < WIDTH-1; j += 2) {
            maze[i][j] = SPACE;
            // randomly remove a wall to connect to adjacent cells
            int direction = rand() % 4;
            switch (direction) {
                case 0: // up
                    if (i > 1) {
                        maze[i-1][j] = SPACE;
                    }
                    break;
                case 1: // down
                    if (i < HEIGHT-2) {
                        maze[i+1][j] = SPACE;
                    }
                    break;
                case 2: // left
                    if (j > 1) {
                        maze[i][j-1] = SPACE;
                    }
                    break;
                case 3: // right
                    if (j < WIDTH-2) {
                        maze[i][j+1] = SPACE;
                    }
                    break;
            }
        }
    }
}

// function to print the maze
void print_maze(int maze[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}