//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void createMaze(int maze[][COLS], int row, int col);
void printMaze(int maze[][COLS], int row, int col);
void generateMaze(int maze[][COLS], int row, int col);
void recursiveMaze(int maze[][COLS], int row, int col, int x, int y);

int main() {
    int maze[ROWS][COLS];
    srand(time(NULL));
    createMaze(maze, ROWS, COLS);
    printf("Before Maze Generation:\n");
    printMaze(maze, ROWS, COLS);
    generateMaze(maze, ROWS, COLS);
    printf("After Maze Generation:\n");
    printMaze(maze, ROWS, COLS);
    return 0;
}

void createMaze(int maze[][COLS], int row, int col) {
    int i, j;
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            maze[i][j] = 1;
        }
    }
}

void printMaze(int maze[][COLS], int row, int col) {
    int i, j;
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(int maze[][COLS], int row, int col) {
    recursiveMaze(maze, row, col, 1, 1);
}

void recursiveMaze(int maze[][COLS], int row, int col, int x, int y) {
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int randIndex, temp;
    int i, nextX, nextY;
    maze[x][y] = 0;
    for(i = 0; i < 4; i++) {
        randIndex = rand() % 4;
        temp = directions[i][0];
        directions[i][0] = directions[randIndex][0];
        directions[randIndex][0] = temp;
        temp = directions[i][1];
        directions[i][1] = directions[randIndex][1];
        directions[randIndex][1] = temp;
    }
    for(i = 0; i < 4; i++) {
        nextX = x + directions[i][0] * 2;
        nextY = y + directions[i][1] * 2;
        if(nextX > 0 && nextX < row && nextY > 0 && nextY < col && maze[nextX][nextY] == 1) {
            maze[x + directions[i][0]][y + directions[i][1]] = 0;
            recursiveMaze(maze, row, col, nextX, nextY);
        }
    }
}