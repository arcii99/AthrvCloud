//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 20

// Definition of Node structure
typedef struct node {
    int row, col;
    int f, g, h;
    struct node *parent;
} Node;

// Grid
int grid[ROWS][COLS];

// Start and end points
Node start, end;

// Function to calculate Manhattan Distance heuristic
int manhattanDistance(Node a, Node b) {
    int dx = abs(a.row - b.row);
    int dy = abs(a.col - b.col);
    return dx + dy;
}

// Function to check if a node is within the grid
int isWithinGrid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

// Function to check if a node is walkable
int isWalkable(int row, int col) {
    return (grid[row][col] == 0);
}

// Function to get all neighbors of a node
void getNeighbors(Node node, Node *neighbors, int *numNeighbors) {
    *numNeighbors = 0;
    int row = node.row, col = node.col;
    Node neighbor;
    // Upper neighbor
    if (isWithinGrid(row-1, col) && isWalkable(row-1, col)) {
        neighbor = (Node) {row-1, col, 0, 0, 0, &node};
        neighbors[*numNeighbors] = neighbor;
        (*numNeighbors)++;
    }
    // Lower neighbor
    if (isWithinGrid(row+1, col) && isWalkable(row+1, col)) {
        neighbor = (Node) {row+1, col, 0, 0, 0, &node};
        neighbors[*numNeighbors] = neighbor;
        (*numNeighbors)++;
    }
    // Left neighbor
    if (isWithinGrid(row, col-1) && isWalkable(row, col-1)) {
        neighbor = (Node) {row, col-1, 0, 0, 0, &node};
        neighbors[*numNeighbors] = neighbor;
        (*numNeighbors)++;
    }
    // Right neighbor
    if (isWithinGrid(row, col+1) && isWalkable(row, col+1)) {
        neighbor = (Node) {row, col+1, 0, 0, 0, &node};
        neighbors[*numNeighbors] = neighbor;
        (*numNeighbors)++;
    }
}

// Function to get the node with the lowest f value
Node getLowestFNode(Node *openList, int numOpen) {
    Node lowestFNode = openList[0];
    for (int i = 1; i < numOpen; i++) {
        if (openList[i].f < lowestFNode.f) {
            lowestFNode = openList[i];
        }
    }
    return lowestFNode;
}

// Function to check if a node is in a list
int isInList(Node *list, int numElements, Node node) {
    for (int i = 0; i < numElements; i++) {
        if (list[i].row == node.row && list[i].col == node.col) {
            return 1;
        }
    }
    return 0;
}

// Function to get the index of a node in a list
int getListIndex(Node *list, int numElements, Node node) {
    for (int i = 0; i < numElements; i++) {
        if (list[i].row == node.row && list[i].col == node.col) {
            return i;
        }
    }
    return -1;
}

// Main A* Pathfinding Algorithm
void aStar() {
    // Initialize open and closed lists
    Node openList[ROWS*COLS];
    Node closedList[ROWS*COLS];
    int numOpen = 0, numClosed = 0;
    // Add start node to open list
    start.f = manhattanDistance(start, end);
    start.g = 0;
    start.h = start.f;
    openList[numOpen] = start;
    numOpen++;
    // Loop until end node is found
    while (numOpen > 0) {
        // Get node with lowest f value
        Node currentNode = getLowestFNode(openList, numOpen);
        // Check if current node is the end node
        if (currentNode.row == end.row && currentNode.col == end.col) {
            printf("Path found!\n");
            // Print path
            Node node = currentNode;
            while (node.parent != NULL) {
                printf("(%d,%d) -> ", node.row, node.col);
                node = *(node.parent);
            }
            printf("(%d,%d)\n", start.row, start.col);
            return;
        }
        // Move current node from open list to closed list
        int currentIndex = getListIndex(openList, numOpen, currentNode);
        for (int i = currentIndex; i < numOpen-1; i++) {
            openList[i] = openList[i+1];
        }
        numOpen--;
        closedList[numClosed] = currentNode;
        numClosed++;
        // Get neighbors of current node
        Node neighbors[4];
        int numNeighbors;
        getNeighbors(currentNode, neighbors, &numNeighbors);
        // Loop through neighbors
        for (int i = 0; i < numNeighbors; i++) {
            Node neighbor = neighbors[i];
            // Check if neighbor is already in closed list
            if (isInList(closedList, numClosed, neighbor)) {
                continue;
            }
            // Calculate g and h values
            int tentativeG = currentNode.g + 1;
            neighbor.h = manhattanDistance(neighbor, end);
            neighbor.f = tentativeG + neighbor.h;
            // Check if neighbor is already in open list
            int neighborIndex = getListIndex(openList, numOpen, neighbor);
            if (neighborIndex == -1) {
                // Add new neighbor to open list
                neighbor.g = tentativeG;
                openList[numOpen] = neighbor;
                numOpen++;
            } else {
                // Update neighbor's g value if this path is shorter
                if (tentativeG < openList[neighborIndex].g) {
                    openList[neighborIndex].g = tentativeG;
                    openList[neighborIndex].f = tentativeG + openList[neighborIndex].h;
                    openList[neighborIndex].parent = currentNode.parent;
                }
            }
        }
    }
    printf("Path not found.\n");
}

int main() {
    // Initialize grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }
    // Set obstacles
    grid[6][5] = 1;
    grid[7][5] = 1;
    grid[8][5] = 1;
    grid[8][6] = 1;
    grid[8][7] = 1;
    grid[8][8] = 1;
    grid[7][8] = 1;
    grid[6][8] = 1;
    // Set start and end points
    start.row = 0;
    start.col = 0;
    end.row = 19;
    end.col = 19;
    // Run A* algorithm
    aStar();
    return 0;
}