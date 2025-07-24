//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

// Structure for storing cell information
struct Cell {
    int row, col;
    int fValue, gValue, hValue;
    struct Cell* parent;
};

// Calculate Manhattan distance between two cells
int manhattanDistance(int row1, int col1, int row2, int col2) {
    return abs(row1 - row2) + abs(col1 - col2);
}

// Check if a cell is within bounds of the grid
bool inBounds(int row, int col) {
    return (row >= 0 && col >= 0 && row < ROW && col < COL);
}

// Check if a cell is unblocked and can be traversed
bool isUnblocked(int grid[ROW][COL], int row, int col) {
    return (grid[row][col] == 0);
}

// Check if a cell is the destination cell
bool isDestination(int row, int col, struct Cell dest) {
    return (row == dest.row && col == dest.col);
}

// Initialize a cell with default values
struct Cell* initializeCell(int row, int col) {
    struct Cell* cell = (struct Cell*)malloc(sizeof(struct Cell));
    cell->row = row;
    cell->col = col;
    cell->fValue = 0;
    cell->gValue = 0;
    cell->hValue = 0;
    cell->parent = NULL;
    return cell;
}

// Find the path from start cell to destination cell
void findPath(int grid[ROW][COL], struct Cell start, struct Cell dest) {
    // Check if the start and destination cells are valid
    if (!inBounds(start.row, start.col) || !inBounds(dest.row, dest.col)) {
        printf("Invalid start or destination cell!\n");
        return;
    }
    if (!isUnblocked(grid, start.row, start.col) || !isUnblocked(grid, dest.row, dest.col)) {
        printf("Start or destination cell is blocked!\n");
        return;
    }
    if (isDestination(start.row, start.col, dest)) {
        printf("Start and destination cells are the same!\n");
        return;
    }

    // Initialize open and closed lists
    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));
    struct Cell* openList[ROW*COL];
    int openListSize = 0;

    // Add start cell to the open list
    openList[openListSize++] = &start;

    // Loop through all cells in the grid
    while (openListSize > 0) {
        // Find the cell with the smallest f value in the open list
        struct Cell* currentCell = openList[0];
        int currentIndex = 0;
        for (int i = 0; i < openListSize; i++) {
            if (openList[i]->fValue < currentCell->fValue) {
                currentCell = openList[i];
                currentIndex = i;
            }
        }

        // Remove the current cell from the open list and add it to the closed list
        openList[currentIndex] = openList[--openListSize];
        closedList[currentCell->row][currentCell->col] = true;

        // Check if the current cell is the destination cell
        if (isDestination(currentCell->row, currentCell->col, dest)) {
            struct Cell* pathCell = currentCell;
            while (pathCell != NULL) {
                grid[pathCell->row][pathCell->col] = 2;
                pathCell = pathCell->parent;
            }
            return;
        }

        // Generate neighbors of the current cell
        struct Cell* neighbors[8];
        int neighborCount = 0;
        for (int row = currentCell->row - 1; row <= currentCell->row + 1; row++) {
            for (int col = currentCell->col - 1; col <= currentCell->col + 1; col++) {
                if (inBounds(row, col) && (row != currentCell->row || col != currentCell->col)) {
                    if (isUnblocked(grid, row, col)) {
                        struct Cell* neighborCell = initializeCell(row, col);
                        neighbors[neighborCount++] = neighborCell;
                    }
                }
            }
        }

        // Loop through all neighbors of the current cell
        for (int i = 0; i < neighborCount; i++) {
            struct Cell* neighbor = neighbors[i];

            // Check if neighbor is already in the closed list
            if (closedList[neighbor->row][neighbor->col]) {
                continue;
            }

            // Calculate g and h values for neighbor
            int newGValue = currentCell->gValue + 1;
            int newHValue = manhattanDistance(neighbor->row, neighbor->col, dest.row, dest.col);
            int newFValue = newGValue + newHValue;

            // Check if neighbor is already in the open list
            bool neighborInOpenList = false;
            for (int j = 0; j < openListSize; j++) {
                if (openList[j]->row == neighbor->row && openList[j]->col == neighbor->col) {
                    neighborInOpenList = true;
                    break;
                }
            }

            // Add neighbor to the open list if not already in the open list
            if (!neighborInOpenList) {
                neighbor->fValue = newFValue;
                neighbor->gValue = newGValue;
                neighbor->hValue = newHValue;
                neighbor->parent = currentCell;
                openList[openListSize++] = neighbor;
            }
            // Update neighbor's g value and parent if a better path is found
            else if (newGValue < neighbor->gValue) {
                neighbor->gValue = newGValue;
                neighbor->fValue = neighbor->gValue + neighbor->hValue;
                neighbor->parent = currentCell;
            }
        }
    }
    printf("No path found!\n");
}

// Print the grid
void printGrid(int grid[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int grid[ROW][COL] = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    struct Cell start = {0, 0};
    struct Cell dest = {9, 9};
    findPath(grid, start, dest);
    printGrid(grid);
    return 0;
}