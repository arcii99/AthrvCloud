//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Defining the size of the grid
#define ROW 10
#define COL 10

// Defining the starting and ending position
#define START_ROW 0
#define START_COL 0
#define END_ROW 9
#define END_COL 9

// Defining the walls in the grid
int walls[][2] = {{2, 2}, {2, 3}, {2, 4}, {2, 5}, {3, 2}, {4, 2}, {5, 2}, {6, 6}, {6, 7}, {6, 8}, {7, 8}, {8, 8}};

// Defining the representation of the grid
char grid[ROW][COL];

// Defining the node structure
typedef struct Node Node;

struct Node {
    int row;
    int col;
    int gCost;
    int hCost;
    int fCost;
    Node* parent;
};

// Defining the array of neighbors
const int numNeighbors = 8;
const int neighbors[][2] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1},  {1, 0},  {1, 1}
};

// Declaring functions
int isWall(int row, int col);
int heuristicCost(Node* current);
int isInsideGrid(int row, int col);
void initializeGrid();
void printGrid();
void printPath(Node* current);
void aStar();

int main() {
    // Initializing the grid
    initializeGrid();
    
    // Running the A* algorithm
    aStar();
    
    // Printing the final grid
    printGrid();
    
    return 0;
}

// Function to check if a given position is a wall or not
int isWall(int row, int col) {
    int i;
    for (i = 0; i < sizeof(walls) / sizeof(walls[0]); i++) {
        if (walls[i][0] == row && walls[i][1] == col) {
            return 1;
        }
    }
    return 0;
}

// Function to calculate the heuristic cost of a node
int heuristicCost(Node* current) {
    return abs(current->row - END_ROW) + abs(current->col - END_COL);
}

// Function to check if a given position is inside the grid or not
int isInsideGrid(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL);
}

// Function to initialize the grid
void initializeGrid() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (isWall(i, j)) {
                grid[i][j] = '#';
            }
            else {
                grid[i][j] = '.';
            }
        }
    }
    grid[START_ROW][START_COL] = 'S';
    grid[END_ROW][END_COL] = 'E';
}

// Function to print the grid
void printGrid() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to print the path taken by the algorithm
void printPath(Node* current) {
    if (current == NULL) {
        return;
    }
    printPath(current->parent);
    grid[current->row][current->col] = '*';
}

// Function to run the A* algorithm
void aStar() {
    Node* openList[ROW * COL];
    Node* closedList[ROW * COL];
    int openListLength = 0;
    int closedListLength = 0;
    
    Node* startNode = (Node*) malloc(sizeof(Node));
    startNode->row = START_ROW;
    startNode->col = START_COL;
    startNode->gCost = 0;
    startNode->hCost = heuristicCost(startNode);
    startNode->fCost = startNode->gCost + startNode->hCost;
    startNode->parent = NULL;
    openList[openListLength] = startNode;
    openListLength++;
    
    while (openListLength > 0) {
        // Finding the current node with the lowest fCost
        int i, minIndex = 0;
        for (i = 1; i < openListLength; i++) {
            if (openList[i]->fCost < openList[minIndex]->fCost) {
                minIndex = i;
            }
        }
        Node* currentNode = openList[minIndex];
        
        // Removing the current node from the open list and adding it to the closed list
        int j;
        for (j = minIndex; j < openListLength - 1; j++) {
            openList[j] = openList[j + 1];
        }
        openListLength--;
        closedList[closedListLength] = currentNode;
        closedListLength++;
        
        // If the current node is the end node, print the path
        if (currentNode->row == END_ROW && currentNode->col == END_COL) {
            printPath(currentNode);
            return;
        }
        
        // Generating the neighbors of the current node
        for (i = 0; i < numNeighbors; i++) {
            int neighborRow = currentNode->row + neighbors[i][0];
            int neighborCol = currentNode->col + neighbors[i][1];
            if (!isInsideGrid(neighborRow, neighborCol) || isWall(neighborRow, neighborCol)) {
                continue;
            }
            Node* neighborNode = (Node*) malloc(sizeof(Node));
            neighborNode->row = neighborRow;
            neighborNode->col = neighborCol;
            neighborNode->parent = currentNode;
            neighborNode->gCost = currentNode->gCost + 1;
            neighborNode->hCost = heuristicCost(neighborNode);
            neighborNode->fCost = neighborNode->gCost + neighborNode->hCost;
            
            // Checking if the neighbor is already in the closed list
            int k;
            for (k = 0; k < closedListLength; k++) {
                if (closedList[k]->row == neighborNode->row && closedList[k]->col == neighborNode->col) {
                    free(neighborNode);
                    break;
                }
            }
            
            // Checking if the neighbor is already in the open list
            if (k != closedListLength) {
                continue;
            }
            for (k = 0; k < openListLength; k++) {
                if (openList[k]->row == neighborNode->row && openList[k]->col == neighborNode->col) {
                    if (neighborNode->gCost < openList[k]->gCost) {
                        openList[k]->gCost = neighborNode->gCost;
                        openList[k]->fCost = openList[k]->gCost + openList[k]->hCost;
                        openList[k]->parent = neighborNode->parent;
                    }
                    free(neighborNode);
                    break;
                }
            }
            
            // Adding the neighbor to the open list if it's not already in the open list
            if (k == openListLength) {
                openList[openListLength] = neighborNode;
                openListLength++;
            }
        }
    }
}