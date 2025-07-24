//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

typedef struct {
    int f;
    int g;
    int h;
    int row;
    int col;
} node_t;

int heuristic(int row, int col, int destRow, int destCol) {
    return abs(destRow - row) + abs(destCol - col);
}

bool isValid(int row, int col) {
    return (row >= 0 && row < ROW) && (col >= 0 && col < COL);
}

bool isUnblocked(int grid[][COL], int row, int col) {
    return grid[row][col] == 0;
}

bool isDestination(int row, int col, node_t destNode) {
    return (row == destNode.row) && (col == destNode.col);
}

void printPath(int parent[][COL], node_t srcNode, node_t destNode) {
    int row = destNode.row;
    int col = destNode.col;

    while (row != srcNode.row || col != srcNode.col) {
        printf("(%d, %d) -> ", row, col);
        int tempRow = parent[row][col] / COL;
        int tempCol = parent[row][col] % COL;
        row = tempRow;
        col = tempCol;
    }

    printf("(%d, %d)\n", srcNode.row, srcNode.col);
}

void aStarSearch(int grid[][COL], node_t srcNode, node_t destNode) {
    int row[] = {-1, 0, 0, 1};
    int col[] = {0, -1, 1, 0};

    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));

    int parent[ROW][COL];
    memset(parent, -1, sizeof(parent));

    node_t priorityQueue[ROW * COL];
    int front = -1, rear = -1;

    priorityQueue[++rear] = srcNode;
    srcNode.f = 0;

    while (front != rear) {
        node_t currNode = priorityQueue[++front];
        int currRow = currNode.row;
        int currCol = currNode.col;
        closedList[currRow][currCol] = true;

        if (isDestination(currRow, currCol, destNode)) {
            printPath(parent, srcNode, destNode);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newRow = currRow + row[i];
            int newCol = currCol + col[i];

            if (!isValid(newRow, newCol)) 
                continue;
            
            if (!isUnblocked(grid, newRow, newCol)) 
                continue;

            if (closedList[newRow][newCol]) 
                continue;

            node_t newNode = {0};
            newNode.g = currNode.g + 1;
            newNode.h = heuristic(newRow, newCol, destNode.row, destNode.col);
            newNode.f = newNode.g + newNode.h;

            newNode.row = newRow;
            newNode.col = newCol;
            priorityQueue[++rear] = newNode;
            parent[newRow][newCol] = currRow * COL + currCol;
        }
    }

    printf("Path does not exist!\n");
}

int main() {
    int grid[ROW][COL] = 
    {
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0}
    };

    node_t srcNode = {0};
    srcNode.row = 0;
    srcNode.col = 0;

    node_t destNode = {0};
    destNode.row = 4;
    destNode.col = 4;

    aStarSearch(grid, srcNode, destNode);

    return 0;
}