//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10
#define MAX_NODES 100

// The node structure
typedef struct Node {
    int x;
    int y;
    int fCost;
    int gCost;
    int hCost;
    struct Node *parent;
} Node;

// Initialize values for a node
void initNode(Node *node) {
    node->x = 0;
    node->y = 0;
    node->fCost = 0;
    node->gCost = 0;
    node->hCost = 0;
    node->parent = NULL;
}

// Initialize the grid
void initGrid(int grid[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j] = 0;
        }
    }
}

// Check if the current node is valid
bool isValid(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

// Check if the current node is a blocked node
bool isBlocked(int grid[][COL], int x, int y) {
    return (grid[x][y] == 1);
}

// Check if the current node is the destination
bool isDestination(int x, int y, int destX, int destY) {
    return (x == destX && y == destY);
}

// Calculate the H cost for the current node
int calculateHCost(int x, int y, int destX, int destY) {
    return abs(destX - x) + abs(destY - y);
}

// Insert a node into the open list
void insertIntoOpenList(Node **openList, Node *node, int *openListSize) {
    int i = (*openListSize)++;
    while (i > 0) {
        int parentIndex = (i - 1) / 2;
        if ((*openList)[parentIndex].fCost <= node->fCost) {
            break;
        }
        (*openList)[i] = (*openList)[parentIndex];
        i = parentIndex;
    }
    (*openList)[i] = *node;
}

// Get the node with the lowest F cost from the open list
Node* getLowestFCostNode(Node **openList, int *openListSize) {
    Node *node = &(*openList)[0];
    (*openList)[0] = (*openList)[--(*openListSize)];
    int i = 0;
    while (true) {
        int child1 = 2 * i + 1;
        int child2 = 2 * i + 2;
        if (child1 >= *openListSize) {
            break;
        }
        int minChildIndex = (child2 >= *openListSize || (*openList)[child1].fCost <= (*openList)[child2].fCost) ? child1 : child2;
        if ((*openList)[i].fCost <= (*openList)[minChildIndex].fCost) {
            break;
        }
        Node temp = (*openList)[i];
        (*openList)[i] = (*openList)[minChildIndex];
        (*openList)[minChildIndex] = temp;
        i = minChildIndex;
    }
    return node;
}

// Get the neighbors of the current node
void getNeighbors(int grid[][COL], Node *currentNode, Node *neighbors[], int *neighborsSize, int destX, int destY) {
    *neighborsSize = 0;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if ((x == 0 && y == 0) || (!isValid(currentNode->x + x, currentNode->y + y))
                || (isBlocked(grid, currentNode->x + x, currentNode->y + y))) {
                continue;
            }
            Node *neighbor = malloc(sizeof(Node));
            initNode(neighbor);
            neighbor->x = currentNode->x + x;
            neighbor->y = currentNode->y + y;
            neighbor->gCost = currentNode->gCost + 1;
            neighbor->hCost = calculateHCost(neighbor->x, neighbor->y, destX, destY);
            neighbor->fCost = neighbor->gCost + neighbor->hCost;
            neighbor->parent = currentNode;
            neighbors[(*neighborsSize)++] = neighbor;
        }
    }
}

// Check if the node is already in the open list
bool isOpen(Node **openList, Node *node, int *openListSize) {
    for (int i = 0; i < *openListSize; i++) {
        if ((*openList)[i].x == node->x && (*openList)[i].y == node->y) {
            return true;
        }
    }
    return false;
}

// Check if the node is already in the closed list
bool isClosed(Node **closedList, Node *node, int *closedListSize) {
    for (int i = 0; i < *closedListSize; i++) {
        if ((*closedList)[i].x == node->x && (*closedList)[i].y == node->y) {
            return true;
        }
    }
    return false;
}

// Get the path from the destination to the start
void getPath(Node *node) {
    if (node == NULL) {
        return;
    }
    getPath(node->parent);
    printf("(%d,%d) ", node->x, node->y);
}

// Find the shortest path using A* algorithm
void findPath(int grid[][COL], int startX, int startY, int destX, int destY) {
    Node *openList[MAX_NODES];
    int openListSize = 0;
    Node *closedList[MAX_NODES];
    int closedListSize = 0;

    Node *startNode = malloc(sizeof(Node));
    initNode(startNode);
    startNode->x = startX;
    startNode->y = startY;
    startNode->hCost = calculateHCost(startX, startY, destX, destY);
    startNode->fCost = startNode->hCost;
    insertIntoOpenList(openList, startNode, &openListSize);

    while (openListSize > 0) {
        Node *currentNode = getLowestFCostNode(openList, &openListSize);
        if (isDestination(currentNode->x, currentNode->y, destX, destY)) {
            getPath(currentNode);
            printf("\n");
            return;
        }
        closedList[closedListSize++] = currentNode;

        Node *neighbors[MAX_NODES];
        int neighborsSize = 0;
        getNeighbors(grid, currentNode, neighbors, &neighborsSize, destX, destY);

        for (int i = 0; i < neighborsSize; i++) {
            Node *neighbor = neighbors[i];
            if (isClosed(closedList, neighbor, &closedListSize)) {
                continue;
            }
            if (isOpen(openList, neighbor, &openListSize)) {
                for (int j = 0; j < openListSize; j++) {
                    if (openList[j]->x == neighbor->x && openList[j]->y == neighbor->y) {
                        if (neighbor->gCost < openList[j]->gCost) {
                            openList[j]->gCost = neighbor->gCost;
                            openList[j]->fCost = neighbor->fCost;
                            openList[j]->parent = neighbor->parent;
                        }
                        break;
                    }
                }
            } else {
                insertIntoOpenList(openList, neighbor, &openListSize);
            }
        }
    }
}

int main() {
    int grid[ROW][COL];
    initGrid(grid);

    // Add some obstacles
    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[1][3] = 1;
    grid[2][3] = 1;
    grid[3][3] = 1;
    grid[3][2] = 1;

    // Find the shortest path
    findPath(grid, 0, 0, 9, 9);

    return 0;
}