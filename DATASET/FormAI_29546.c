//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>
#define ROW 5
#define COL 5

// Function to print the path taken by the algorithm
void printPath(int path[][COL], int destX, int destY) {
    printf("Path Taken:\n");
    while(!(destX == 0 && destY == 0)) {
        printf("(%d,%d)\n", destX, destY);
        int tempX = path[destX][destY]/10;
        destY = path[destX][destY]%10;
        destX = tempX;
    }
    printf("(0,0)\n");
    return;
}

// Function to check if given position is valid
bool isValid(int row_num, int col_num) {
    return (row_num >= 0) && (row_num < ROW) && (col_num >= 0) && (col_num < COL);
}

// Function to check if given position is blocked
bool isBlocked(int grid[][COL], int row_num, int col_num) {
    return (grid[row_num][col_num] == 1);
}

// Breadth first search algorithm for pathfinding
bool bfs(int grid[][COL], int srcX, int srcY, int destX, int destY) {
    int dirX[] = {-1, 0, 1, 0};
    int dirY[] = {0, 1, 0, -1};
    int visited[ROW][COL] = {0};
    int path[ROW][COL] = {0};

    visited[srcX][srcY] = 1;

    // Queue to hold the cells that need to be explored
    int xQueue[ROW*COL];
    int yQueue[ROW*COL];
    int front = 0;
    int rear = 0;
    xQueue[rear] = srcX;
    yQueue[rear] = srcY;
    rear++;

    bool pathFound = false;

    while(front < rear) {
        int currX = xQueue[front];
        int currY = yQueue[front];
        front++;

        if(currX == destX && currY == destY) {
            pathFound = true;
            break;
        }

        for(int i = 0; i < 4; i++) {
            int nextX = currX + dirX[i];
            int nextY = currY + dirY[i];

            if(isValid(nextX, nextY) && !visited[nextX][nextY] && !isBlocked(grid, nextX, nextY)) {
                visited[nextX][nextY] = 1;
                path[nextX][nextY] = currX*10 + currY;
                xQueue[rear] = nextX;
                yQueue[rear] = nextY;
                rear++;
            }
        }
    }

    if(pathFound) {
        printPath(path, destX, destY);
        return true;
    }

    printf("No Path Found.\n");
    return false;
}

// Main function to test the algorithm
int main() {
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 0, 0, 0}
    };
    int srcX = 0, srcY = 0, destX = 4, destY = 4;
    bfs(grid, srcX, srcY, destX, destY);
    return 0;
}