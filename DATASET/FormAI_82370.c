//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // size of the maze
#define WALL 1
#define PATH 0

// function to print the maze
void print_maze(int maze[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (maze[i][j] == WALL) {
                printf("█"); // wall
            } else if (maze[i][j] == PATH) {
                printf(" "); // path
            }
        }
        printf("\n");
    }
}

// function to generate the maze
void generate_maze(int maze[][SIZE], int x, int y) {
    int i, dx, dy, j, temp;
    int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // direction array

    for (i = 0; i < 4; i++) {
        // shuffle direction array randomly
        j = rand() % 4;
        dx = dir[j][0];
        dy = dir[j][1];

        // check if the new cell is within the maze boundaries
        if (x + dx >= 0 && x + dx < SIZE && y + dy >= 0 && y + dy < SIZE) {
            if (maze[x + dx][y + dy] == WALL) {
                // check how many walls are neighboring the new cell
                temp = 0;
                for (j = 0; j < 4; j++) {
                    dx = dir[j][0];
                    dy = dir[j][1];
                    if (x + dx >= 0 && x + dx < SIZE && y + dy >= 0 && y + dy < SIZE) {
                        if (maze[x + dx][y + dy] == WALL) {
                            temp++;
                        }
                    }
                }
                // if there are less than 2 walls neighboring the new cell, make it a path cell
                if (temp < 2) {
                    maze[x + dx][y + dy] = PATH;
                    generate_maze(maze, x + dx, y + dy);
                }
            }
        }
    }
}

int main() {
    int maze[SIZE][SIZE];
    srand(time(NULL));

    // initialize the maze with walls
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            maze[i][j] = WALL;
        }
    }

    // generate the maze
    generate_maze(maze, SIZE / 2, SIZE / 2);

    // print the maze
    print_maze(maze);

    return 0;
}