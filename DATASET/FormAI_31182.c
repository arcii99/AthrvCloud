//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

int maze[ROW][COL];

int generateRandomNumber(int limit) {
    return (rand() % limit);
}

void initializeMaze() {
    srand(time(0));
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (generateRandomNumber(10) > 7) {
                maze[i][j] = 1;
            }
            else {
                maze[i][j] = 0;
            }
        }
    }
}

void printMaze() {
    printf("\nMAP:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int navigateMaze(int row, int col) {
    if (row < 0 || col < 0 || row > ROW - 1 || col > COL - 1 || maze[row][col] == 1) {
        return 0;
    }
    else if (maze[row][col] == 2) {
        printf("\nYou have reached your destination!\n");
        return 1;
    }
    else {
        maze[row][col] = 1;
        if (navigateMaze(row, col + 1) == 1) { // East
            return 1;
        }
        if (navigateMaze(row, col - 1) == 1) { // West
            return 1;
        }
        if (navigateMaze(row + 1, col) == 1) { // South
            return 1;
        }
        if (navigateMaze(row - 1, col) == 1) { // North
            return 1;
        }
        maze[row][col] = 0;
        return 0;
    }
}

int main() {

    printf("Welcome to the Maze Route Finder!\n");

    initializeMaze();
    printMaze();

    int startRow, startCol;
    printf("\nEnter the starting point coordinates (row col): ");
    scanf("%d %d", &startRow, &startCol);
    maze[startRow][startCol] = 0;

    int endRow, endCol;
    printf("\nEnter the end point coordinates (row col): ");
    scanf("%d %d", &endRow, &endCol);
    maze[endRow][endCol] = 2;

    if (navigateMaze(startRow, startCol) == 0) {
        printf("\nThere is no path to the destination.\n");
        return 0;
    }

    printf("\nROUTE:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 1) {
                printf("X ");
            }
            else if (maze[i][j] == 2) {
                printf("E ");
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    return 0;
}