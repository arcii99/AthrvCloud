//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROW 20 // Maze must have even row and column sizes
#define COL 40

int maze[ROW][COL];

void initializeMaze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            maze[i][j] = 1;
        }
    }
}

int isSafe(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 1);
}

int isWall(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 0);
}

int canGo(int row, int col) {
    return ((row+1)%2==0 && (col+1)%2==0);
}

int isIntersection(int row, int col) {
    int count = 0;
    if (isWall(row-1, col)) count++;
    if (isWall(row+1, col)) count++;
    if (isWall(row, col-1)) count++;
    if (isWall(row, col+1)) count++;
    return (count > 1);
}

void generateMaze(int row, int col) {
    srand(time(NULL));
    maze[0][0] = 0; // Entrance of maze
    maze[row-1][col-1] = 0; // Exit of maze
    int posX = 1, posY = 1;
    int updateX[] = {-2, 0, 2, 0}; // Up, Right, Down, Left
    int updateY[] = {0, 2, 0, -2};
    int shuffle[] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp = shuffle[i];
        shuffle[i] = shuffle[j];
        shuffle[j] = temp;
    }
    for (int i = 0; i < 4; i++) {
        int nextX = posX + updateX[shuffle[i]];
        int nextY = posY + updateY[shuffle[i]];
        if (isSafe(nextX, nextY)) {
            maze[nextX][nextY] = 0;
            if (canGo(nextX, nextY)) {
                maze[posX + (nextX - posX)/2][posY + (nextY - posY)/2] = 0;
                generateMaze(nextX, nextY);
            }
            posX = nextX;
            posY = nextY;
        }
    }
}

void printMaze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    initializeMaze();
    generateMaze(1, 1);
    printMaze();
    return 0;
}