//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 15

void generateMaze(char maze[][COLS]);
void printMaze(char maze[][COLS]);

int main() {
    char maze[ROWS][COLS];
    generateMaze(maze);
    printMaze(maze);

    return 0;
}

void generateMaze(char maze[][COLS]) {
    srand(time(NULL));
    int i, j;
    // Initialize all cells to wall
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = '#';
        }
    }
    // Start with a random cell
    int row = rand() % ROWS;
    int col = rand() % COLS;
    maze[row][col] = '.';
    int count = 1;
    // Continue until all cells are visited
    while (count < ROWS * COLS) {
        // Check all neighboring cells
        if (row > 0 && maze[row-1][col] == '#') { // Up
            maze[--row][col] = '.';
            ++count;
        } else if (row < ROWS - 1 && maze[row+1][col] == '#') { // Down
            maze[++row][col] = '.';
            ++count;
        } else if (col > 0 && maze[row][col-1] == '#') { // Left
            maze[row][--col] = '.';
            ++count;
        } else if (col < COLS - 1 && maze[row][col+1] == '#') { // Right
            maze[row][++col] = '.';
            ++count;
        } else { // All surrounding cells have been visited, backtrack
            int found = 0;
            while (!found) {
                row = rand() % ROWS;
                col = rand() % COLS;
                if (maze[row][col] == '.') {
                    found = 1;
                }
            }
        }
    }
}

void printMaze(char maze[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}