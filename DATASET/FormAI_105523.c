//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 20

void generateMaze(char maze[][COL], int rowSize, int colSize);
void printMaze(char maze[][COL], int rowSize, int colSize);

int main() {
    char maze[ROW][COL];

    srand(time(NULL)); // set random seed

    generateMaze(maze, ROW, COL);
    printMaze(maze, ROW, COL);
    
    return 0;
}

void generateMaze(char maze[][COL], int rowSize, int colSize) {
    // initialize maze to all walls
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            maze[i][j] = '#';
        }
    }

    int x = rand() % rowSize;
    int y = rand() % colSize;
    maze[x][y] = ' ';

    // start recursive maze building
    // TODO: add recursive function to build maze
}

void printMaze(char maze[][COL], int rowSize, int colSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}