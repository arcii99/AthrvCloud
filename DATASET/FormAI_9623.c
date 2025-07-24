//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

// Function to print the path from start to end
void printPath(int path[][COLS], int row, int col) {
    printf("(%d, %d) ", row, col);
    if (row == 0 && col == 0) {
        return;
    }
    if (path[row][col] == 1) {
        printPath(path, row, col-1);
    } else if (path[row][col] == 2) {
        printPath(path, row-1, col);
    } else if (path[row][col] == 3) {
        printPath(path, row, col+1);
    } else if (path[row][col] == 4) {
        printPath(path, row+1, col);
    }
}

// Function to find the shortest path
void shortestPath(int maze[][COLS], int startRow, int startCol, int endRow, int endCol) {
    int queue[ROWS*COLS][2], path[ROWS][COLS];
    int visited[ROWS][COLS], front = 0, rear = 0;
    int rowDiff[] = {-1, 0, 1, 0};
    int colDiff[] = {0, 1, 0, -1};
    
    visited[startRow][startCol] = 1;
    path[startRow][startCol] = -1;
    queue[rear][0] = startRow;
    queue[rear][1] = startCol;
    ++rear;

    while (front != rear) {
        int curRow = queue[front][0];
        int curCol = queue[front][1];
        ++front;
        
        if (curRow == endRow && curCol == endCol) {
            printf("\nThe shortest path is:\n");
            printPath(path, endRow, endCol);
            return;
        }
        
        for (int i = 0; i < 4; ++i) {
            int nextRow = curRow + rowDiff[i];
            int nextCol = curCol + colDiff[i];
            
            if (nextRow < 0 || nextRow >= ROWS || nextCol < 0 || nextCol >= COLS) {
                continue;
            }
            
            if (maze[nextRow][nextCol] == 0 || visited[nextRow][nextCol] == 1) {
                continue;
            }
            
            queue[rear][0] = nextRow;
            queue[rear][1] = nextCol;
            ++rear;
            visited[nextRow][nextCol] = 1;
            path[nextRow][nextCol] = i + 1;
        }
    }
    
    printf("\nThere is no possible path.\n");
    return;
}

int main() {
    int maze[][COLS] = {{1, 0, 1, 1, 1},
                        {1, 0, 1, 0, 1},
                        {1, 1, 1, 0, 1},
                        {0, 0, 0, 0, 1},
                        {1, 1, 1, 0, 1}};
    
    int startRow = 0, startCol = 0;
    int endRow = 4, endCol = 4;
    
    printf("The maze is:\n");
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    shortestPath(maze, startRow, startCol, endRow, endCol);
    
    return 0;
}