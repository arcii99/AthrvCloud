//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10 // number of rows in maze
#define COLS 10 // number of columns in maze

// function prototypes
void createMaze(char maze[][COLS]);
void displayMaze(char maze[][COLS]);

int main()
{
    srand(time(NULL)); // initialize random seed

    char maze[ROWS][COLS]; // create maze array

    createMaze(maze); // generate maze
    displayMaze(maze); // display maze

    return 0;
}

void createMaze(char maze[][COLS])
{
    int i, j;
    // initialize maze with walls
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = '#';
        }
    }
    // create paths in maze
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == '#') {
                int r = rand() % 4; // choose random path
                if (r == 0) { // go up
                    if (i > 0 && maze[i-1][j] == '#') {
                        maze[i][j] = ' ';
                        maze[i-1][j] = ' ';
                    }
                } else if (r == 1) { // go right
                    if (j < COLS-1 && maze[i][j+1] == '#') {
                        maze[i][j] = ' ';
                        maze[i][j+1] = ' ';
                    }
                } else if (r == 2) { // go down
                    if (i < ROWS-1 && maze[i+1][j] == '#') {
                        maze[i][j] = ' ';
                        maze[i+1][j] = ' ';
                    }
                } else { // go left
                    if (j > 0 && maze[i][j-1] == '#') {
                        maze[i][j] = ' ';
                        maze[i][j-1] = ' ';
                    }
                }
            }
        }
    }
}

void displayMaze(char maze[][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]); // print maze character
        }
        printf("\n"); // end of row
    }
}