//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 15
#define COL 15

void generateMaze(int maze[ROW][COL]) {
    int i, j, k;
    // Initialize all cells as walls
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            maze[i][j] = 1;
        }
    }
    // Randomly generate starting point
    srand(time(0));
    int startX = rand() % COL;
    if (startX == 0) startX++;
    if (startX == COL - 1) startX--;
    int startY = rand() % ROW;
    if (startY == 0) startY++;
    if (startY == ROW - 1) startY--;
    // Generate maze by removing walls using depth-first search
    maze[startY][startX] = 0; // starting point is not a wall
    int visited[ROW][COL] = {0};
    int stackX[ROW * COL], stackY[ROW * COL];
    int top = 0;
    stackX[top] = startX;
    stackY[top] = startY;
    while (top >= 0) {
        int currX = stackX[top];
        int currY = stackY[top];
        visited[currY][currX] = 1;
        int directions[4] = {0, 1, 2, 3}; // 0 = up, 1 = right, 2 = down, 3 = left
        for (k = 3; k > 0; k--) { // shuffle directions
            int r = rand() % (k + 1);
            int tmp = directions[r];
            directions[r] = directions[k];
            directions[k] = tmp;
        }
        int moved = 0;
        for (k = 0; k < 4; k++) {
            int nextX = currX, nextY = currY;
            if (directions[k] == 0) { // up
                if (currY > 1 && visited[currY - 2][currX] == 0) {
                    maze[currY - 1][currX] = 0; // remove wall
                    nextY -= 2;
                    moved = 1;
                }
            } else if (directions[k] == 1) { // right
                if (currX < COL - 2 && visited[currY][currX + 2] == 0) {
                    maze[currY][currX + 1] = 0; // remove wall
                    nextX += 2;
                    moved = 1;
                }
            } else if (directions[k] == 2) { // down
                if (currY < ROW - 2 && visited[currY + 2][currX] == 0) {
                    maze[currY + 1][currX] = 0; // remove wall
                    nextY += 2;
                    moved = 1;
                }
            } else { // left
                if (currX > 1 && visited[currY][currX - 2] == 0) {
                    maze[currY][currX - 1] = 0; // remove wall
                    nextX -= 2;
                    moved = 1;
                }
            }
            if (moved) {
                stackX[++top] = nextX;
                stackY[top] = nextY;
                break;
            }
        }
        if (!moved) {
            top--;
        }
    }
}

void printMaze(int maze[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (maze[i][j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[ROW][COL];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}