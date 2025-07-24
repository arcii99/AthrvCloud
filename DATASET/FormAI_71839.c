//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: random
#include <stdio.h>
#define rows 5
#define cols 5

int map[rows][cols] = {
    {0, 0, 0, 0, 0},
    {0, 2, 2, 0, 0},
    {0, 2, 0, 2, 0},
    {0, 0, 2, 2, 0},
    {0, 0, 0, 0, 0}
};

int start[2] = {1, 1};
int finish[2] = {3, 3};

int isValid(int row, int col) {
    return (row >= 0) && (row < rows) && (col >= 0) && (col < cols);
}

int isDestination(int row, int col) {
    return (row == finish[0]) && (col == finish[1]);
}

int findShortestPath(int map[][cols], int visited[][cols], int row, int col, int destRow, int destCol) {
    if (!isValid(row, col))
        return 0;
    if (visited[row][col] || map[row][col] == 2)
        return 0;
    visited[row][col] = 1;

    if (isDestination(row, col))
        return 1;
    
    if (findShortestPath(map, visited, row-1, col, destRow, destCol))
        return 1;
    if (findShortestPath(map, visited, row+1, col, destRow, destCol))
        return 1;
    if (findShortestPath(map, visited, row, col-1, destRow, destCol))
        return 1;
    if (findShortestPath(map, visited, row, col+1, destRow, destCol))
        return 1;

    return 0;
}

int main(void) {
    int visited[rows][cols];
    int row, col;
    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            visited[row][col] = 0;
        }
    }

    if (findShortestPath(map, visited, start[0], start[1], finish[0], finish[1])) {
        printf("Path Found!\n");
    } else {
        printf("Path Not Found!\n");
    }
    
    return 0;
}