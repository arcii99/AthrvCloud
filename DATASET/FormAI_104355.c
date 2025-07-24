//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROW 5
#define COL 5

typedef struct Node {
    int row, col;
    struct Node *parent;
    float f, g, h;
    bool visited, blocked;
} Node;

Node grid[ROW][COL];

// Helper function to calculate Euclidean distance
float euclideanDistance(int row1, int col1, int row2, int col2) {
    return sqrt(pow(row2 - row1, 2) + pow(col2 - col1, 2));
}

// Function to check if a given cell is blocked or not
bool isBlocked(int row, int col) {
    return grid[row][col].blocked;
}

// Function to check if a given cell is within the bounds of the grid
bool isInBounds(int row, int col) {
    return row >= 0 && row < ROW && col >= 0 && col < COL;
}

// Function to print the grid
void printGrid() {
    printf("GRID:\n");
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            if (grid[row][col].blocked) {
                printf("X ");
            } else if (grid[row][col].visited) {
                printf(". ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

// Function to initialise the grid
void initialiseGrid() {
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            grid[row][col].row = row;
            grid[row][col].col = col;
            grid[row][col].visited = false;
            grid[row][col].blocked = false;
            grid[row][col].f = -1;
            grid[row][col].g = -1;
            grid[row][col].h = -1;
            grid[row][col].parent = NULL;
        }
    }
    
    // Add some walls to the grid
    grid[1][2].blocked = true;
    grid[2][2].blocked = true;
    grid[3][2].blocked = true;
    grid[4][2].blocked = true;
    grid[0][4].blocked = true;
    grid[1][4].blocked = true;
    grid[2][4].blocked = true;
}

// Function to check if a given node is the goal node
bool isGoalNode(Node *node, int goalRow, int goalCol) {
    return node->row == goalRow && node->col == goalCol;
}

// Function to calculate the f value of a node
float calculateF(Node *node, int goalRow, int goalCol) {
    node->h = euclideanDistance(node->row, node->col, goalRow, goalCol);
    node->f = node->g + node->h;
    return node->f;
}

// Function to return the node with the lowest f value in a list of nodes
Node *getLowestFNode(Node *openList[], int openListSize) {
    Node *lowestNode = openList[0];
    for (int i = 1; i < openListSize; i++) {
        if (openList[i]->f < lowestNode->f) {
            lowestNode = openList[i];
        }
    }
    return lowestNode;
}

// Function to print the path to the goal node
void printPath(Node *goalNode) {
    printf("PATH:\n");
    Node *currentNode = goalNode;
    while (currentNode != NULL) {
        printf("(%d,%d)", currentNode->row, currentNode->col);
        currentNode = currentNode->parent;
        if (currentNode != NULL) {
            printf(" -> ");
        }
    }
}

// Main function to perform A* search on the grid
bool aStarSearch(int startRow, int startCol, int goalRow, int goalCol) {
    Node *startNode = &grid[startRow][startCol];
    Node *goalNode = &grid[goalRow][goalCol];
    
    if (startNode->blocked || goalNode->blocked) {
        printf("START OR GOAL NODE IS BLOCKED\n");
        return false;
    }
    
    Node *openList[ROW * COL] = {NULL};
    int openListSize = 0;
    startNode->g = 0;
    calculateF(startNode, goalRow, goalCol);
    openList[0] = startNode;
    openListSize++;
    
    while (openListSize > 0) {
        Node *currentNode = getLowestFNode(openList, openListSize);
        if (isGoalNode(currentNode, goalRow, goalCol)) {
            printPath(goalNode);
            return true;
        }
        
        currentNode->visited = true;
        for (int row = -1; row <= 1; row++) {
            for (int col = -1; col <= 1; col++) {
                int neighbourRow = currentNode->row + row;
                int neighbourCol = currentNode->col + col;
                if (!isInBounds(neighbourRow, neighbourCol) || (row == 0 && col == 0)) {
                    continue;
                }
                Node *neighbourNode = &grid[neighbourRow][neighbourCol];
                if (isBlocked(neighbourRow, neighbourCol) || neighbourNode->visited) {
                    continue;
                }
                float tentativeG = currentNode->g + euclideanDistance(currentNode->row, currentNode->col, neighbourRow, neighbourCol);
                if (tentativeG < neighbourNode->g || neighbourNode->g == -1) {
                    neighbourNode->parent = currentNode;
                    neighbourNode->g = tentativeG;
                    calculateF(neighbourNode, goalRow, goalCol);
                    if (neighbourNode->visited) {
                        neighbourNode->visited = false;
                    }
                    if (neighbourNode->f == -1) {
                        openList[openListSize] = neighbourNode;
                        openListSize++;
                    }
                }
            }
        }
    }
    
    printf("NO PATH FOUND\n");
    return false;
}

int main() {
    initialiseGrid();
    printGrid();
    printf("\n");
    aStarSearch(0, 0, 4, 4);
}