//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Cyberpunk
#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int row;
    int col;
} Node;

// Function to find neighbors of a node
void findNeighbors(int* grid, int rows, int cols, Node node, int* neighbors) {
    int index = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int row = node.row + i;
            int col = node.col + j;
            if (row < 0 || row >= rows || col < 0 || col >= cols) continue;
            if (*(grid + row * cols + col) == 0) continue;
            *(neighbors + index) = row * cols + col;
            index++;
        }
    }
}

// Function to find the shortest path between two nodes
int findPath(int* grid, int rows, int cols, Point start, Point end, int* path) {
    int startIdx = start.y * cols + start.x;
    int endIdx = end.y * cols + end.x;
    int frontier[rows * cols];
    int frontierSize = 1;
    *(frontier + 0) = startIdx;
    int cameFrom[rows * cols];
    for (int i = 0; i < rows * cols; i++) *(cameFrom + i) = -1;
    int costSoFar[rows * cols];
    for (int i = 0; i < rows * cols; i++) *(costSoFar + i) = -1;
    *(costSoFar + startIdx) = 0;
    while (frontierSize > 0) {
        int currentIdx = *(frontier + 0);
        if (currentIdx == endIdx) {
            int pathIndex = 0;
            *(path + pathIndex) = endIdx;
            while (currentIdx != startIdx) {
                currentIdx = *(cameFrom + currentIdx);
                pathIndex++;
                *(path + pathIndex) = currentIdx;
            }
            return pathIndex + 1;
        }
        for (int i = 0; i < rows * cols; i++) {
            if (i == currentIdx) continue;
            if (*(grid + i) == 0) continue;
            if (*(cameFrom + i) != -1) continue;
            int neighbors[8];
            findNeighbors(grid, rows, cols, (Node){i / cols, i % cols}, neighbors);
            for (int j = 0; j < 8; j++) {
                if (*(neighbors + j) == -1) break;
                if (*(costSoFar + neighbors[j]) == -1 ||
                    *(costSoFar + neighbors[j]) >
                    *(costSoFar + currentIdx) + 1) {
                    *(cameFrom + neighbors[j]) = currentIdx;
                    *(costSoFar + neighbors[j]) = *(costSoFar + currentIdx) + 1;
                    *(frontier + frontierSize) = *(neighbors + j);
                    frontierSize++;
                }
            }
        }
        *(frontier + 0) = *(frontier + frontierSize - 1);
        frontierSize--;
    }
    return -1;
}

int main() {
    // Define the grid
    int rows = 10;
    int cols = 10;
    int grid[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // Define the start and end points
    Point start = {.x = 0, .y = 0};
    Point end = {.x = cols - 1, .y = rows - 1};

    // Find the shortest path
    int path[rows * cols];
    int pathLength = findPath((int*)grid, rows, cols, start, end, path);

    // Print the grid
    printf("Pathfinding Grid:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == start.y && j == start.x) printf("S");
            else if (i == end.y && j == end.x) printf("E");
            else printf("%d", grid[i][j]);
        }
        printf("\n");
    }

    // Print the path
    printf("\nPath:\n");
    for (int i = pathLength - 1; i >= 0; i--) {
        printf("(%d, %d) ", path[i] % cols, path[i] / cols);
    }

    return 0;
}