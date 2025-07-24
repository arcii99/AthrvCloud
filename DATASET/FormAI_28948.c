//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

void createMaze(int maze[ROW][COL]);
void printMaze(int maze[ROW][COL]);
void generatePath(int maze[ROW][COL], int row, int col);
int isPath(int maze[ROW][COL], int row, int col);
int isWall(int maze[ROW][COL], int row, int col);

int main() {
    int maze[ROW][COL];
    createMaze(maze);
    generatePath(maze, 0, 0);
    printMaze(maze);
    return 0;
}

void createMaze(int maze[ROW][COL]) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            int num = rand() % 2;
            maze[i][j] = num;
        }
    }
    maze[0][0] = 0;
    maze[ROW - 1][COL - 1] = 0;
}

void printMaze(int maze[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 0) {
                printf("  ");
            } else {
                printf("[]");
            }
        }
        printf("\n");
    }
}

void generatePath(int maze[ROW][COL], int row, int col) {
    maze[row][col] = 0;
    const int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0; i < 4; i++) {
        int newRow = row + move[i][0];
        int newCol = col + move[i][1];
        if (newRow < 0 || newRow >= ROW || newCol < 0 || newCol >= COL) {
            continue;
        }
        if (isPath(maze, newRow, newCol) || isWall(maze, newRow, newCol)) {
            continue;
        }
        if (newRow == ROW - 1 && newCol == COL - 1) {
            maze[newRow][newCol] = 0;
            break;
        }
        if (rand() % 2 == 0) {
            maze[row + move[i][0] / 2][col + move[i][1] / 2] = 0;
        }
        generatePath(maze, newRow, newCol);
    }
}

int isPath(int maze[ROW][COL], int row, int col) {
    if (maze[row][col] == 0) {
        return 1;
    } else {
        return 0;
    }
}

int isWall(int maze[ROW][COL], int row, int col) {
    if (maze[row][col] == 1) {
        return 1;
    } else {
        return 0;
    }
}