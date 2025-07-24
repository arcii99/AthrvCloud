//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

// Node struct to store details about each cell in the grid
typedef struct node {
    int row, col;
    int g, h, f;
    struct node *parent;
} Node;

// Create a grid of nodes with random weights assigned to each cell
void createGrid(int grid[][COL], Node nodes[][COL]) {
    srand(time(NULL)); // Seed random number generator
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            nodes[i][j].row = i;
            nodes[i][j].col = j;
            nodes[i][j].g = 0;
            nodes[i][j].h = (rand()%10)+1; // Assign random heuristic value (1-10)
            nodes[i][j].f = 0;
            nodes[i][j].parent = NULL;
            grid[i][j] = rand()%2; // Assign random weight (0 or 1)
        }
    }
    printf("Grid with random weights and heuristic values created.\n\n");
}

// Function to print details of each node
void printNode(Node *n) {
    printf("Node: (%d,%d) Cost: %d Heuristic: %d Total: %d\n", n->row, n->col, n->g, n->h, n->f);
}

// Function to print the entire grid of nodes with weights and heuristic values
void printGrid(int grid[][COL], Node nodes[][COL]) {
    printf("Grid:\n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(grid[i][j]) printf("[ 1] "); // Print weight of 1 as " 1"
            else printf("[ 0] "); // Print weight of 0 as " 0"
        }
        printf("\n");
    }
    printf("\nHeuristic Grid:\n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("[%2d] ", nodes[i][j].h); // Print heuristic value of each node
        }
        printf("\n");
    }
    printf("----------------------------------------------------\n");
}

// Function to check if a given node is within the bounds of the grid
bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Function to check if a given node is blocked (i.e., weight of cell is 0)
bool isBlocked(int grid[][COL], int row, int col) {
    return grid[row][col] == 0;
}

// Function to check if a given node is the goal node
bool isGoal(int row, int col, int goalRow, int goalCol) {
    return row == goalRow && col == goalCol;
}

// Function to calculate the F value of a node (F = G + H)
int calculateF(Node *n) {
    return n->g + n->h;
}

// Function to backtrace the path taken from the start node to the goal node
void printPath(Node *current) {
    if(current == NULL) return;
    printPath(current->parent);
    printf("(%d,%d) -> ", current->row, current->col);
}

// A* pathfinding algorithm to find the cheapest path from start to goal
void findPath(int grid[][COL], Node nodes[][COL], int startRow, int startCol, int goalRow, int goalCol) {
    if(!isValid(startRow, startCol) || !isValid(goalRow, goalCol)) {
        printf("Invalid start/goal node.\n");
        return;
    }
    if(isBlocked(grid, startRow, startCol) || isBlocked(grid, goalRow, goalCol)) {
        printf("Start or goal node is blocked.\n");
        return;
    }
    if(isGoal(startRow, startCol, goalRow, goalCol)) {
        printf("Start and goal nodes are the same.\n");
        return;
    }

    Node *startNode = &nodes[startRow][startCol];
    Node *goalNode = &nodes[goalRow][goalCol];

    bool closedList[ROW][COL]; // List of nodes already evaluated
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            closedList[i][j] = false; // Initialize all nodes as not evaluated
        }
    }

    // Initialize the start node's F value to 0 and add it to the open list
    startNode->g = 0;
    startNode->f = calculateF(startNode);

    Node *openList[ROW*COL]; // List of nodes to be evaluated
    int openSize = 1;
    openList[0] = startNode;

    while(openSize > 0) {
        // Find the node with the lowest F value in the open list
        Node *currentNode = openList[0];
        int currentIndex = 0;
        for(int i=1; i<openSize; i++) {
            if(openList[i]->f < currentNode->f) {
                currentNode = openList[i];
                currentIndex = i;
            }
        }

        // Move the current node from the open list to the closed list
        openList[currentIndex] = openList[openSize-1];
        openSize--;
        closedList[currentNode->row][currentNode->col] = true;

        // If the goal node has been reached, print the path and return
        if(isGoal(currentNode->row, currentNode->col, goalRow, goalCol)) {
            printf("Cheapest path found! Path: ");
            printPath(currentNode);
            printf("\n\n");
            return;
        }

        // Expand the current node's children
        Node *children[4];
        int numChildren = 0;
        int row = currentNode->row;
        int col = currentNode->col;

        // Generate the possible children nodes
        int adjRow[4] = {row-1, row, row+1, row}; // Top, Right, Bottom, Left
        int adjCol[4] = {col, col+1, col, col-1};
        for(int i=0; i<4; i++) {
            if(isValid(adjRow[i], adjCol[i]) && !isBlocked(grid, adjRow[i], adjCol[i])) {
                children[numChildren++] = &nodes[adjRow[i]][adjCol[i]];
            }
        }

        // Evaluate each child node
        for(int i=0; i<numChildren; i++) {
            Node *child = children[i];
            if(closedList[child->row][child->col]) continue; // Node has already been evaluated
            int tentativeG = currentNode->g + grid[child->row][child->col]; // G value of the child node

            // Add the child node to the open list if it is not already there
            bool isNewNode = false;
            if(!child->parent || tentativeG < child->g) {
                isNewNode = true;
                child->g = tentativeG;
                child->f = calculateF(child);
                child->parent = currentNode;
                if(!isNewNode) {
                    openList[openSize++] = child;
                }
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    int grid[ROW][COL];
    Node nodes[ROW][COL];
    createGrid(grid, nodes);
    printGrid(grid, nodes);
    findPath(grid, nodes, 0, 0, 9, 9); // Find the path from (0,0) to (9,9)
    return 0;
}