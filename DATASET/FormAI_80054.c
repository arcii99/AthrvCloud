//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];

void printMaze() {
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == 1)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}

void generateMaze(int row, int col) {
    maze[row][col] = 1;
    int direction = rand() % 4;
    if (direction == 0 && row > 1 && maze[row-2][col] == 0) {
        maze[row-1][col] = 1;
        generateMaze(row-2, col);
    }
    if (direction == 1 && col < COLS-2 && maze[row][col+2] == 0) {
        maze[row][col+1] = 1;
        generateMaze(row, col+2);
    }
    if (direction == 2 && row < ROWS-2 && maze[row+2][col] == 0) {
        maze[row+1][col] = 1;
        generateMaze(row+2, col);
    }
    if (direction == 3 && col > 1 && maze[row][col-2] == 0) {
        maze[row][col-1] = 1;
        generateMaze(row, col-2);
    }
}

int main() {
    srand(time(NULL));

    // initialize maze to all walls
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            maze[i][j] = 0;
        }
    }

    // generate maze starting from middle of top row
    generateMaze(1, COLS/2);

    // print maze
    printMaze();

    return 0;
}