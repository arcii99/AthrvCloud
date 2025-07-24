//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void printMaze(int maze[][COLS], int rows, int cols);
void generateMaze(int maze[][COLS], int rows, int cols, int wall, int path);

int main() {
    int maze[ROWS][COLS];
    int wall = 1;
    int path = 0;

    //initialize maze to all walls
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            maze[i][j] = wall;
        }
    }

    //seed random number generator
    srand(time(0));

    //generate maze
    generateMaze(maze, ROWS, COLS, wall, path);

    //print maze
    printMaze(maze, ROWS, COLS);

    return 0;
}

void generateMaze(int maze[][COLS], int rows, int cols, int wall, int path) {
    int row = rand() % rows;
    int col = rand() % cols;

    //set starting cell as path
    maze[row][col] = path;

    //check if adjacent cells are walls and break through walls randomly
    if(row > 0 && maze[row-1][col] == wall && rand()%2 == 0) {
        maze[row-1][col] = path;
        generateMaze(maze, rows, cols, wall, path);
    }
    if(col > 0 && maze[row][col-1] == wall && rand()%2 == 0) {
        maze[row][col-1] = path;
        generateMaze(maze, rows, cols, wall, path);
    }
    if(row < rows-1 && maze[row+1][col] == wall && rand()%2 == 0) {
        maze[row+1][col] = path;
        generateMaze(maze, rows, cols, wall, path);
    }
    if(col < cols-1 && maze[row][col+1] == wall && rand()%2 == 0) {
        maze[row][col+1] = path;
        generateMaze(maze, rows, cols, wall, path);
    }
}

void printMaze(int maze[][COLS], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(maze[i][j] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}