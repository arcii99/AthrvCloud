//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 0, 1, 1, 0, 0 },
    { 0, 1, 1, 1, 1, 1, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 1, 1, 1, 1, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 0, 1, 0, 1, 1, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 1, 1, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 }
};

bool visited[ROWS][COLS] = {false};
int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int startRow, startCol, endRow, endCol;

void printMaze(int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void findStartEnd() {
    // Find the start and end points of the maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1 && !visited[i][j]) {
                // Found a new island, it is the starting point
                startRow = i;
                startCol = j;

                // Use DFS to find all connected islands, 
                // and mark them as visited
                visited[i][j] = true;
                for (int k = 0; k < 4; k++) {
                    int newRow = i + directions[k][0];
                    int newCol = j + directions[k][1];
                    if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                    }
                }

                // If all islands connected to the starting point have been found,
                // this is also the end point of the maze
                if (i >= ROWS-1 || maze[i+1][j] == 0) {
                    endRow = i;
                    endCol = j;
                    return;
                }
            }
        }
    }
}

void findRoute(int row, int col) {
    // Use DFS to find the route from the starting point to the end point
    visited[row][col] = true;
    for (int i = 0; i < 4; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];
        if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] == 1 && !visited[newRow][newCol]) {
            printf("(%d,%d) -> ", newRow, newCol);
            if (newRow == endRow && newCol == endCol) {
                printf("Done!\n");
                return;
            }
            findRoute(newRow, newCol);
        }
    }
}

int main() {
    printf("The maze is:\n");
    printMaze(ROWS, COLS);
    findStartEnd();
    printf("The starting point of the maze is: (%d,%d)\n", startRow, startCol);
    printf("The end point of the maze is: (%d,%d)\n", endRow, endCol);
    printf("The route to the end of the maze is:\n(%d,%d) -> ", startRow, startCol);
    findRoute(startRow, startCol);
    return 0;
}