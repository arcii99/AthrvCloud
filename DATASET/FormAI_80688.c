//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

// Node structure
typedef struct Node {
    int row, col, f, g, h;
    struct Node* parent;
} Node;

// Initialize a node with the given values
Node* initializeNode(int row, int col, int f, int g, int h, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->f = f;
    node->g = g;
    node->h = h;
    node->parent = parent;
    return node;
}

// Check if the given node is valid and walkable
bool isValid(int grid[][COL], int row, int col) {
    return (row >= 0 && row < ROW) && (col >= 0 && col < COL) && (grid[row][col] == 1);
}

// Check if the given node is the goal node
bool isGoalNode(Node* node, int endRow, int endCol) {
    return (node->row == endRow) && (node->col == endCol);
}

// Calculate the heuristic value (h) using Manhattan distance
int calculateHeuristicValue(int realRow, int realCol, int endRow, int endCol) {
    return abs(realRow - endRow) + abs(realCol - endCol);
}

// Find the path using the A* algorithm
Node* findPath(int grid[][COL], int startRow, int startCol, int endRow, int endCol) {
    int row, col, newG, i, neighbourRow, neighbourCol;
    bool visited[ROW][COL];
    
    // Initialize visited array with false
    for (row = 0; row < ROW; row++) {
        for (col = 0; col < COL; col++) {
            visited[row][col] = false;   
        }
    }
    
    // Create a start node with all values set to 0
    Node* startNode = initializeNode(startRow, startCol, 0, 0, 0, NULL);
    
    // Initialize list of open and closed nodes
    Node* openList = startNode;
    Node* closedList = NULL;
    
    // Loop until we reach the goal node
    while (openList != NULL) {
        
        // Find the node with the lowest f value
        Node* currentNode = openList;
        Node* tempNode = openList->parent;
        while (tempNode != NULL) {
            if (tempNode->f < currentNode->f) {
                currentNode = tempNode;
            }
            tempNode = tempNode->parent;
        }
        
        // Move current node from open list to closed list
        Node* tempList = openList;
        if (openList == currentNode) {
            openList = openList->parent;
            tempList->parent = NULL;
        } else {
            while (tempList != NULL) {
                if (tempList == currentNode) {
                    tempList->parent->parent = tempList->parent;
                    tempList->parent = NULL;
                    break;
                }
                tempList = tempList->parent;
            }
        }
        currentNode->parent = closedList;
        closedList = currentNode;
        
        // Check if we reached the end node
        if (isGoalNode(currentNode, endRow, endCol)) {
            return currentNode;
        }
        
        // Add the neighbours of the current node to the open list
        for (i = 0; i < 4; i++) {
            neighbourRow = currentNode->row + (i == 0) - (i == 1);
            neighbourCol = currentNode->col + (i == 2) - (i == 3);
            if (isValid(grid, neighbourRow, neighbourCol)) {
                Node* neighbourNode = initializeNode(neighbourRow, neighbourCol, 0, 0, 0, currentNode);
                neighbourNode->g = currentNode->g + 1;
                neighbourNode->h = calculateHeuristicValue(neighbourRow, neighbourCol, endRow, endCol);
                neighbourNode->f = neighbourNode->g + neighbourNode->h;
                visited[neighbourRow][neighbourCol] = true;
                Node* tempList = openList;
                while (tempList != NULL) {
                    if (tempList->row == neighbourRow && tempList->col == neighbourCol) {
                        if (neighbourNode->f < tempList->f) {
                            if (tempList == openList) {
                                openList = neighbourNode;
                                neighbourNode->parent = NULL;
                            } else {
                                neighbourNode->parent = tempList->parent;
                                tempList->parent = neighbourNode;
                            }
                            neighbourNode->parent = currentNode;
                            neighbourNode->f = neighbourNode->g + neighbourNode->h;
                        }
                        free(neighbourNode);
                        neighbourNode = NULL;
                        break;
                    }
                    tempList = tempList->parent;
                }
                if (neighbourNode != NULL) {
                    neighbourNode->parent = currentNode;
                    Node* tempList = closedList;
                    while (tempList != NULL) {
                        if (tempList->row == neighbourRow && tempList->col == neighbourCol) {
                            if (neighbourNode->f < tempList->f) {
                                if (tempList == closedList) {
                                    closedList = neighbourNode;
                                    neighbourNode->parent = NULL;
                                } else {
                                    neighbourNode->parent = tempList->parent;
                                    tempList->parent = neighbourNode;
                                    neighbourNode->parent = currentNode;
                                }
                                neighbourNode->f = neighbourNode->g + neighbourNode->h;
                            }
                            free(neighbourNode);
                            neighbourNode = NULL;
                            break;
                        }
                        tempList = tempList->parent;
                    }
                    if (neighbourNode != NULL) {
                        if (openList == NULL) {
                            openList = neighbourNode;
                        } else {
                            Node* tempList = openList;
                            while (tempList->parent != NULL && tempList->f < neighbourNode->f) {
                                tempList = tempList->parent;
                            }
                            if (tempList == openList && tempList->f >= neighbourNode->f) {
                                neighbourNode->parent = tempList->parent;
                                tempList->parent = neighbourNode;
                                neighbourNode->parent = currentNode;
                                openList = neighbourNode;
                            } else {
                                neighbourNode->parent = tempList->parent;
                                tempList->parent = neighbourNode;
                                neighbourNode->parent = currentNode;
                            }
                        }
                    }
                }
            }
        }
    }
    
    // No path found
    return NULL;
}

int main()
{
    int grid[ROW][COL] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    
    Node* goalNode = findPath(grid, 1, 1, 8, 8);
    printf("Path: ");
    int count = 0;
    while (goalNode != NULL) {
        printf("(%d, %d)", goalNode->row, goalNode->col);
        count++;
        if (goalNode->parent != NULL) {
            printf(" -> ");
        }
        goalNode = goalNode->parent;
    }
    printf("\nNumber of steps: %d\n", count);
    
    return 0;
}