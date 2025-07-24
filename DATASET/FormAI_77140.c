//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 10
#define COL 10

void printMaze(int maze[ROW][COL]) {
    int i, j;
    printf("\n");
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            if(maze[i][j] == 0) {
                printf("#");
            } else if(maze[i][j] == 1) {
                printf(".");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}

void generateMaze(int maze[ROW][COL]) {
    int i, j;
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            if(i == 0 || i == ROW - 1 || j == 0 || j == COL - 1) {
                maze[i][j] = 0;
            } else {
                maze[i][j] = 1;
            }
        }
    }
    srand(time(NULL));
    int x = rand() % (ROW - 2) + 1;
    int y = rand() % (COL - 2) + 1;
    maze[x][y] = 2;
}

int isSafe(int x, int y, int maze[ROW][COL]) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] != 0 && maze[x][y] != 2);
}

int findPath(int maze[ROW][COL], int x, int y, int destX, int destY) {
    if(x == destX && y == destY) {
        return 1;
    }
    maze[x][y] = 0;
    if(isSafe(x - 1, y, maze) && findPath(maze, x - 1, y, destX, destY)) {
        return 1;
    }
    if(isSafe(x + 1, y, maze) && findPath(maze, x + 1, y, destX, destY)) {
        return 1;
    }
    if(isSafe(x, y - 1, maze) && findPath(maze, x, y - 1, destX, destY)) {
        return 1;
    }
    if(isSafe(x, y + 1, maze) && findPath(maze, x, y + 1, destX, destY)) {
        return 1;
    }
    maze[x][y] = 1;
    return 0;
}

int main() {
    int maze[ROW][COL];
    generateMaze(maze);
    printf("Maze:\n");
    printMaze(maze);

    int startX, startY, destX, destY;
    printf("\nEnter the starting point coordinates (x,y): ");
    scanf("%d,%d", &startX, &startY);
    printf("Enter the destination coordinates (x,y): ");
    scanf("%d,%d", &destX, &destY);

    if(findPath(maze, startX, startY, destX, destY)) {
        printf("\nThere is a path from (%d,%d) to (%d,%d)", startX, startY, destX, destY);
        printf("\nPath:\n");
        maze[startX][startY] = 2;
        maze[destX][destY] = 2;
        printMaze(maze);
    } else {
        printf("\nThere is no path from (%d,%d) to (%d,%d)", startX, startY, destX, destY);
    }

    return 0;
}