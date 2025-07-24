//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 10
#define COL 10
#define MAX_SIZE 100

// Structure to represent a cell in the grid
struct cell {
    int x, y;
    int f, g, h; // f = g + h
    int parentX, parentY;
};

// Function to allocate dynamic memory for the grid
int **createGrid() {
    int **grid = (int **) malloc(sizeof(int *) * ROW);
    for (int i = 0; i < ROW; i++) {
        grid[i] = (int *) malloc(sizeof(int) * COL);
    }
    return grid;
}

// Function to initialize the grid with values and obstacles
void initializeGrid(int **grid) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j] = 0; // 0 represents unblocked cell
        }
    }
    grid[1][2] = -1; // -1 represents blocked cell
    grid[2][2] = -1;
    grid[3][2] = -1;
    grid[4][2] = -1;
    grid[5][2] = -1;
}

// Function to check if a given cell is valid (within the grid and unblocked)
int isCellValid(int **grid, int row, int col) {
    if (row >= 0 && row < ROW && col >= 0 && col < COL && grid[row][col] != -1) {
        return 1;
    }
    return 0;
}

// Function to compute heuristic value of a cell (Euclidean distance)
int computeHeuristicValue(int currentX, int currentY, int targetX, int targetY) {
    int xDistance = abs(currentX - targetX);
    int yDistance = abs(currentY - targetY);
    int h = (int) sqrt((double) (xDistance * xDistance) + (yDistance * yDistance));
    return h;
}

// Function to find the path from start to target using A* algorithm
int findPath(int **grid, int startX, int startY, int targetX, int targetY) {
    int openList[MAX_SIZE][2];
    int closedList[MAX_SIZE][2];
    int fScore[MAX_SIZE][MAX_SIZE];

    // Initialize fScore matrix to infinite
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            fScore[i][j] = INT_MAX;
        }
    }

    // Set starting cell
    struct cell start = {startX, startY, 0, 0, 0, -1, -1};
    struct cell target = {targetX, targetY, 0, 0, 0, -1, -1};

    // Initialize openList with starting cell
    int openListCount = 0;
    openList[openListCount][0] = start.x;
    openList[openListCount][1] = start.y;
    fScore[start.x][start.y] = start.h;
    openListCount++;

    while (openListCount > 0) {
        // Find the cell with lowest f score
        int currentX, currentY;
        int minF = INT_MAX;
        int currentIndex;
        for (int i = 0; i < openListCount; i++) {
            int x = openList[i][0];
            int y = openList[i][1];
            if (fScore[x][y] < minF) {
                minF = fScore[x][y];
                currentX = x;
                currentY = y;
                currentIndex = i;
            }
        }

        // Remove current cell from openList and add to closedList
        openList[currentIndex][0] = openList[openListCount - 1][0];
        openList[currentIndex][1] = openList[openListCount - 1][1];
        openListCount--;
        closedList[openListCount][0] = currentX;
        closedList[openListCount][1] = currentY;

        // Check if target cell has been reached
        if (currentX == targetX && currentY == targetY) {
            return 1;
        }

        // Check neighbors of current cell
        for (int row = -1; row <= 1; row++) {
            for (int col = -1; col <= 1; col++) {
                int neighborX = currentX + row;
                int neighborY = currentY + col;

                // Skip if out of bounds or already in closedList or blocked
                if (!isCellValid(grid, neighborX, neighborY) ||
                    ((neighborX == currentX) && (neighborY == currentY)) ||
                    (grid[neighborX][neighborY] == -1)) {
                    continue;
                }

                // Compute tentative g score
                int tentativeG = fScore[currentX][currentY] + 1;

                // Add neighbor to openList if not already in it
                int found = 0;
                for (int i = 0; i < openListCount; i++) {
                    if (openList[i][0] == neighborX && openList[i][1] == neighborY) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    openList[openListCount][0] = neighborX;
                    openList[openListCount][1] = neighborY;
                    openListCount++;
                }

                // Update neighbor's parent and g and f score if better path found
                if (tentativeG < fScore[neighborX][neighborY]) {
                    fScore[neighborX][neighborY] = tentativeG + 
                    computeHeuristicValue(neighborX, neighborY, targetX, targetY);
                    struct cell currentCell = {currentX, currentY, 0, tentativeG, 0, -1, -1};
                    struct cell neighborCell = {neighborX, neighborY, 0, 0, 0, -1, -1};
                    neighborCell.parentX = currentX;
                    neighborCell.parentY = currentY;
                }
            }
        }
    }

    return 0; // Target not reached
}

// Driver function
int main() {
    int **grid = createGrid();
    initializeGrid(grid);
    int startX = 0, startY = 0;
    int targetX = 9, targetY = 9;
    if (findPath(grid, startX, startY, targetX, targetY)) {
        printf("Path found!");
    } else {
        printf("Path not found.");
    }
    return 0;
}