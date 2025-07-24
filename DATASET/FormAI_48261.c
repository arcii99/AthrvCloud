//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void print_maze(char maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {

    srand(time(NULL)); // seed the random number generator

    char maze[ROWS][COLS];
    int i, j;

    // initialize maze to all walls
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
                maze[i][j] = '#';
            } else {
                maze[i][j] = ' ';
            }
        }
    }

    // carve out the maze
    int row = 2;
    int col = 2;
    maze[row][col] = ' ';
    while (1) {
        int direction = rand() % 4;
        if (direction == 0 && row > 2) { // move up
            row--;
            if (maze[row][col] == '#') {
                maze[row+1][col] = ' ';
                maze[row][col] = ' ';
            }
        } else if (direction == 1 && col < COLS-3) { // move right
            col++;
            if (maze[row][col] == '#') {
                maze[row][col-1] = ' ';
                maze[row][col] = ' ';
            }
        } else if (direction == 2 && row < ROWS-3) { // move down
            row++;
            if (maze[row][col] == '#') {
                maze[row-1][col] = ' ';
                maze[row][col] = ' ';
            }
        } else if (direction == 3 && col > 2) { // move left
            col--;
            if (maze[row][col] == '#') {
                maze[row][col+1] = ' ';
                maze[row][col] = ' ';
            }
        }

        // check if maze is complete
        int complete = 1;
        for (i = 1; i < ROWS-1; i++) {
            for (j = 1; j < COLS-1; j++) {
                if (maze[i][j] == '#') {
                    complete = 0;
                }
            }
        }
        if (complete) {
            break;
        }
    }

    // print the maze
    print_maze(maze);

    return 0;
}