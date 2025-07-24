//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: random
// Welcome to the amazing world of C Pathfinding!

// We will create a unique program that generates a maze and finds the fastest path to the exit!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Creating the maze
void createMaze(int maze[][COLS]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1) {
                maze[i][j] = 1;
            } else if (rand() % 3 == 0) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = 0;
            }
        }
    }
    maze[1][0] = maze[ROWS - 2][COLS - 1] = 0;
}

// Printing the maze
void printMaze(int maze[][COLS], int playerRow, int playerCol) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == playerRow && j == playerCol) {
                printf("P");
            } else if (maze[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Searching for the exit using BFS algorithm
void searchExit(int row, int col, int maze[][COLS]) {
    // Creating queue using array
    int queue[ROWS * COLS][2];
    int queueStart = 0, queueEnd = 0;
    int visited[ROWS][COLS] = {0};
    int directions[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // Up, Right, Down, Left

    // Adding the starting point to the queue
    visited[row][col] = 1;
    queue[queueEnd][0] = row;
    queue[queueEnd][1] = col;
    queueEnd++;

    // BFS algorithm
    while (queueStart != queueEnd) {
        int currentRow = queue[queueStart][0];
        int currentCol = queue[queueStart][1];
        queueStart++;

        // Checking if we reached the exit
        if (currentRow == ROWS - 2 && currentCol == COLS - 1) {
            printf("Congratulations! You found the exit!\n");
            return;
        }

        // Exploring adjacent cells
        int i;
        for (i = 0; i < 4; i++) {
            int nextRow = currentRow + directions[i][0];
            int nextCol = currentCol + directions[i][1];
            if (nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS 
                && maze[nextRow][nextCol] == 0 && visited[nextRow][nextCol] == 0) {
                visited[nextRow][nextCol] = 1;
                queue[queueEnd][0] = nextRow;
                queue[queueEnd][1] = nextCol;
                queueEnd++;
            }
        }
    }

    printf("Sorry! You were not able to find the exit!\n");
}

int main() {
    int maze[ROWS][COLS];
    createMaze(maze);
    printMaze(maze, 1, 0);
    searchExit(1, 0, maze);
    return 0;
}