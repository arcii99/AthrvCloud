//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the dimensions of our grid
#define ROWS 10
#define COLS 10

// Define Node structure
typedef struct _Node {
    int row;
    int col;
    int gCost;
    int hCost;
    int fCost;
    struct _Node *parent;
    bool blocked;
} Node;

// Function prototypes
int calculateHCost(int currentRow, int currentCol, int endRow, int endCol);
bool isCoordinateValid(int row, int col);
void setObstacles(Node grid[][COLS]);
Node* findPath(Node grid[][COLS], int startRow, int startCol, int endRow, int endCol);

// Function to calculate the H Cost for A* algorithm
int calculateHCost(int currentRow, int currentCol, int endRow, int endCol) {
    int hCost = abs(currentRow - endRow) + abs(currentCol - endCol);
    return hCost;
}

// Function to validate whether coordinate is within the bounds of the grid
bool isCoordinateValid(int row, int col) {
    bool isValid = true;
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        isValid = false;
    }
    return isValid;
}

// Function to randomly set blocked cells on grid
void setObstacles(Node grid[][COLS]) {
    double obstacleDensity = 0.4; // Percentage of cells that are blocked
    int numObstacles = ROWS*COLS*obstacleDensity;
    
    int i,j;
    for (i=0; i<numObstacles; i++) {
        int randRow = rand() % ROWS;
        int randCol = rand() % COLS;
        
        if (!grid[randRow][randCol].blocked) {
            grid[randRow][randCol].blocked = true;
        }
        else {
            // Try a different cell
            i--;
        }
    }
}

// Function to find the optimal path from start cell to end cell using A* algorithm
Node* findPath(Node grid[][COLS], int startRow, int startCol, int endRow, int endCol) {
    // Define open and closed lists
    Node *openList[ROWS*COLS];
    Node *closedList[ROWS*COLS];
    
    // Initialize lists
    int i;
    for (i=0; i<ROWS*COLS; i++) {
        openList[i] = NULL;
        closedList[i] = NULL;
    }
    
    // Initialize start node
    Node *startNode = &grid[startRow][startCol];
    startNode->gCost = 0;
    startNode->hCost = calculateHCost(startRow, startCol, endRow, endCol);
    startNode->fCost = startNode->gCost + startNode->hCost;
    openList[0] = startNode;
    
    // Initialize variables for loop
    int numOpenNodes = 1;
    int numClosedNodes = 0;
    
    // Loop until optimal path is found or no path exists
    while (numOpenNodes > 0) {
        // Find node with lowest F Cost in open list
        Node *currentNode = openList[0];
        int currentFVal = currentNode->fCost;
        int currentIdx = 0;
        for (i=1; i<numOpenNodes; i++) {
            if (openList[i]->fCost < currentFVal) {
                currentNode = openList[i];
                currentFVal = currentNode->fCost;
                currentIdx = i;
            }
        }
        
        // Move current node to closed list
        openList[currentIdx] = NULL;
        closedList[numClosedNodes] = currentNode;
        numOpenNodes--;
        numClosedNodes++;
        
        // Check if current node is the end node
        if (currentNode->row == endRow && currentNode->col == endCol) {
            return currentNode;
        }
        
        // Check each neighbor of current node
        int rowOffset[] = {-1, 0, 1, 0};
        int colOffset[] = {0, 1, 0, -1};
        for (i=0; i<4; i++) {
            int neighborRow = currentNode->row + rowOffset[i];
            int neighborCol = currentNode->col + colOffset[i];
            
            if (isCoordinateValid(neighborRow, neighborCol)) {
                Node *neighborNode = &grid[neighborRow][neighborCol];
                
                // Skip if neighbor node is blocked or already in closed list
                if (neighborNode->blocked || neighborNode->parent) {
                    continue;
                }
                
                // Calculate G Cost and F Cost for neighbor node
                int neighborGCost = currentNode->gCost + 1;
                int neighborHCost = calculateHCost(neighborRow, neighborCol, endRow, endCol);
                int neighborFCost = neighborGCost + neighborHCost;
                
                // Update neighbor node and add to open list
                neighborNode->gCost = neighborGCost;
                neighborNode->hCost = neighborHCost;
                neighborNode->fCost = neighborFCost;
                neighborNode->parent = currentNode;
                openList[numOpenNodes] = neighborNode;
                numOpenNodes++;
            }
        }
    }
    
    // No path exists
    return NULL;
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Create grid
    Node grid[ROWS][COLS];
    
    // Initialize grid
    int i,j;
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].gCost = 0;
            grid[i][j].hCost = 0;
            grid[i][j].fCost = 0;
            grid[i][j].parent = NULL;
            grid[i][j].blocked = false;
        }
    }
    
    // Set obstacles on grid
    setObstacles(grid);
    
    // Find optimal path
    Node *endNode = findPath(grid, 0, 0, ROWS-1, COLS-1);
    
    // Print path
    if (endNode) {
        Node *currentNode = endNode;
        while (currentNode) {
            printf("(%d,%d) ", currentNode->row, currentNode->col);
            currentNode = currentNode->parent;
        }
    }
    else {
        printf("No path found.");
    }
    
    return 0;
}