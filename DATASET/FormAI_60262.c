//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10
#define INF 1000000

// Structure for storing a cell's coordinates and f, g, and h values
struct Cell {
    int row, col;
    int f, g, h;
};

// Initialize a grid with random values
void initGrid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand()%2;
        }
    }
}

// Print the grid
void printGrid(int grid[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Check if a cell is valid and walkable
bool isValid(int row, int col, int grid[ROWS][COLS]) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false;
    }
    if (grid[row][col] == 1) {
        return false;
    }
    return true;
}

// Calculate the heuristic (h) value using Manhattan distance
int calculateH(int startRow, int startCol, int endRow, int endCol) {
    return abs(startRow - endRow) + abs(startCol - endCol);
}

// Find the cell with the lowest f value in an open list
struct Cell* findLowestF(struct Cell** openList, int openSize) {
    if (openSize == 0) {
        return NULL;
    }
    struct Cell* lowestF = openList[0];
    for (int i = 1; i < openSize; i++) {
        if (openList[i]->f < lowestF->f) {
            lowestF = openList[i];
        }
    }
    return lowestF;
}

// Find the path from start to end using A* Pathfinding Algorithm
void findPath(int grid[ROWS][COLS], int startRow, int startCol, int endRow, int endCol) {
    int gScores[ROWS][COLS];
    int fScores[ROWS][COLS];
    struct Cell* parent[ROWS][COLS];
    struct Cell* openList[ROWS*COLS];
    int openSize = 0;
    bool closedList[ROWS][COLS];
    
    // Initialize g and f scores to infinity
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gScores[i][j] = INF;
            fScores[i][j] = INF;
        }
    }
    
    // Set g score of start cell to 0
    gScores[startRow][startCol] = 0;
    
    // Calculate f score of start cell using heuristic
    fScores[startRow][startCol] = calculateH(startRow, startCol, endRow, endCol);
    
    // Add start cell to open list
    struct Cell* start = (struct Cell*) malloc(sizeof(struct Cell));
    start->row = startRow;
    start->col = startCol;
    start->f = fScores[startRow][startCol];
    start->g = gScores[startRow][startCol];
    start->h = calculateH(startRow, startCol, endRow, endCol);
    openList[0] = start;
    openSize++;
    
    while (openSize > 0) {
        // Search for cell with lowest f value in open list
        struct Cell* current = findLowestF(openList, openSize);
        if (current->row == endRow && current->col == endCol) {
            // Path found, reconstruct path
            int path[ROWS*COLS][2];
            int pathLength = 0;
            struct Cell* temp = current;
            while (temp != NULL) {
                path[pathLength][0] = temp->row;
                path[pathLength][1] = temp->col;
                pathLength++;
                temp = parent[temp->row][temp->col];
            }
            for (int i = pathLength-1; i >= 0; i--) {
                printf("(%d,%d) ", path[i][0], path[i][1]);
            }
            printf("\n");
            return;
        }
        // Remove current cell from open list and add to closed list
        for (int i = 0; i < openSize; i++) {
            if (openList[i]->row == current->row && openList[i]->col == current->col) {
                for (int j = i; j < openSize-1; j++) {
                    openList[j] = openList[j+1];
                }
                openSize--;
                break;
            }
        }
        closedList[current->row][current->col] = true;
        // Check neighbors of current cell
        int neighbors[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
        for (int i = 0; i < 8; i++) {
            int neighborRow = current->row + neighbors[i][0];
            int neighborCol = current->col + neighbors[i][1];
            if (isValid(neighborRow, neighborCol, grid) && !closedList[neighborRow][neighborCol]) {
                int gScore = gScores[current->row][current->col] + 1;
                if (gScore < gScores[neighborRow][neighborCol]) {
                    // Update g, h, and f scores of neighbor cell
                    gScores[neighborRow][neighborCol] = gScore;
                    fScores[neighborRow][neighborCol] = gScore + calculateH(neighborRow, neighborCol, endRow, endCol);
                    // Add neighbor cell to open list if not already added
                    struct Cell* neighbor = (struct Cell*) malloc(sizeof(struct Cell));
                    neighbor->row = neighborRow;
                    neighbor->col = neighborCol;
                    neighbor->f = fScores[neighborRow][neighborCol];
                    neighbor->g = gScores[neighborRow][neighborCol];
                    neighbor->h = calculateH(neighborRow, neighborCol, endRow, endCol);
                    bool inOpenList = false;
                    for (int j = 0; j < openSize; j++) {
                        if (openList[j]->row == neighbor->row && openList[j]->col == neighbor->col) {
                            inOpenList = true;
                            break;
                        }
                    }
                    if (!inOpenList) {
                        openList[openSize] = neighbor;
                        openSize++;
                    }
                    // Set parent of neighbor cell to current cell
                    parent[neighborRow][neighborCol] = current;
                }
            }
        }
        free(current);
    }
    // If no path found
    printf("No Path Found\n");
}

int main() {
    srand(time(NULL));
    int grid[ROWS][COLS];
    initGrid(grid);
    printGrid(grid);
    int startRow, startCol, endRow, endCol;
    printf("Enter start row and column: ");
    scanf("%d%d", &startRow, &startCol);
    printf("Enter end row and column: ");
    scanf("%d%d", &endRow, &endCol);
    findPath(grid, startRow, startCol, endRow, endCol);
    return 0;
}