//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int maze[MAX_ROWS][MAX_COLS];
    int i, j, startRow, startCol, endRow, endCol;

    // Generate random maze
    srand(time(NULL));
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (i == 0 || i == MAX_ROWS - 1 || j == 0 || j == MAX_COLS - 1) {
                // Generate border walls
                maze[i][j] = 1;
            } else {
                // Generate inner walls
                maze[i][j] = rand() % 2;
            }
        }
    }

    // Set start and end points
    startRow = rand() % MAX_ROWS;
    startCol = 0;
    maze[startRow][startCol] = 0;
    endRow = rand() % MAX_ROWS;
    endCol = MAX_COLS - 1;
    maze[endRow][endCol] = 0;

    // Print maze
    printf("Generated Maze:\n");
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (maze[i][j] == 1) {
                printf("#");
            } else if (i == startRow && j == startCol) {
                printf("S");
            } else if (i == endRow && j == endCol) {
                printf("E");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Solve maze (BFS)
    int q[MAX_ROWS * MAX_COLS][2];
    int front = 0, rear = 0;
    int visited[MAX_ROWS * MAX_COLS];
    for (i = 0; i < MAX_ROWS * MAX_COLS; i++) {
        visited[i] = 0;
    }
    visited[startRow * MAX_COLS + startCol] = 1;
    q[rear][0] = startRow;
    q[rear][1] = startCol;
    rear++;
    while (front < rear) {
        int currRow = q[front][0];
        int currCol = q[front][1];
        front++;
        if (currRow == endRow && currCol == endCol) {
            break;
        }
        if (currRow > 0 && maze[currRow - 1][currCol] == 0 && !visited[(currRow - 1) * MAX_COLS + currCol]) {
            visited[(currRow - 1) * MAX_COLS + currCol] = 1;
            q[rear][0] = currRow - 1;
            q[rear][1] = currCol;
            rear++;
        }
        if (currRow < MAX_ROWS - 1 && maze[currRow + 1][currCol] == 0 && !visited[(currRow + 1) * MAX_COLS + currCol]) {
            visited[(currRow + 1) * MAX_COLS + currCol] = 1;
            q[rear][0] = currRow + 1;
            q[rear][1] = currCol;
            rear++;
        }
        if (currCol > 0 && maze[currRow][currCol - 1] == 0 && !visited[currRow * MAX_COLS + currCol - 1]) {
            visited[currRow * MAX_COLS + currCol - 1] = 1;
            q[rear][0] = currRow;
            q[rear][1] = currCol - 1;
            rear++;
        }
        if (currCol < MAX_COLS - 1 && maze[currRow][currCol + 1] == 0 && !visited[currRow * MAX_COLS + currCol + 1]) {
            visited[currRow * MAX_COLS + currCol + 1] = 1;
            q[rear][0] = currRow;
            q[rear][1] = currCol + 1;
            rear++;
        }
    }

    // Print solution
    if (visited[endRow * MAX_COLS + endCol]) {
        printf("Solution:\n");
        for (i = 0; i < MAX_ROWS; i++) {
            for (j = 0; j < MAX_COLS; j++) {
                if (maze[i][j] == 1) {
                    printf("#");
                } else if (i == startRow && j == startCol) {
                    printf("S");
                } else if (i == endRow && j == endCol) {
                    printf("E");
                } else if (visited[i * MAX_COLS + j]) {
                    printf(".");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    } else {
        printf("No solution found :(\n");
    }

    return 0;
}