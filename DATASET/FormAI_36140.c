//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defining the size of the grid
#define ROW 10
#define COL 10

// Defining the start and end locations
#define START_ROW 0
#define START_COL 0
#define END_ROW 9
#define END_COL 9

// Defining the obstacles in the grid with a value of 0
int obstacles[ROW][COL] = {
    {0,1,0,1,0,0,0,0,1,0},
    {0,1,0,0,1,0,0,0,0,0},
    {0,0,1,0,0,0,1,0,1,0},
    {0,0,0,0,0,0,0,1,0,0},
    {0,1,0,1,0,0,0,0,0,1},
    {0,0,0,0,0,1,0,0,1,0},
    {0,0,1,0,0,0,0,0,0,0},
    {1,0,0,0,1,0,1,0,0,0},
    {0,0,0,0,0,0,0,1,0,1},
    {0,0,0,0,0,0,0,0,0,0}
};

// Defining the size of a block
#define BLOCK_SIZE 50

// Defining the structure for the nodes
typedef struct node {
    int row, col;
    double g, h, f;
    struct node* parent;
} node;

// Function to check if a node is a valid location in the grid
int isValid(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL);
}

// Function to check if a node is an obstacle or not
int isObstacle(int row, int col) {
    return (!isValid(row, col) || obstacles[row][col] == 1);
}

// Function to calculate the Euclidean distance between two nodes
double euclideanDistance(int row1, int col1, int row2, int col2) {
    return sqrt(pow(row1 - row2, 2) + pow(col1 - col2, 2));
}

// Function to create a new node
node* newNode(int row, int col, double g, double h, double f, node* parent) {
    node* temp = (node*) malloc(sizeof(node));
    temp->row = row;
    temp->col = col;
    temp->g = g;
    temp->h = h;
    temp->f = f;
    temp->parent = parent;
    return temp;
}

// Function to print the path
void printPath(node* current) {
    if (current->parent == NULL) {
        printf("(%d,%d)", current->row, current->col);
        return;
    }
    printPath(current->parent);
    printf(" -> (%d,%d)", current->row, current->col);
}

// The A* Pathfinding Algorithms
void aStar() {
    // Creating the open and closed lists
    node* openList[ROW*COL];
    node* closedList[ROW*COL];
    int openListCount = 0, closedListCount = 0;

    // Creating the start and end nodes
    node* startNode = newNode(START_ROW, START_COL, 0.0, euclideanDistance(START_ROW, START_COL, END_ROW, END_COL), euclideanDistance(START_ROW, START_COL, END_ROW, END_COL), NULL);
    node* endNode = newNode(END_ROW, END_COL, 0.0, 0.0, 0.0, NULL);

    // Adding the start node to the open list
    openList[openListCount++] = startNode;

    // Looping until the goal node is found or the open list is empty
    while (openListCount > 0) {
        // Finding the node with the lowest f value in the open list
        int currentNodeIndex = 0;
        for (int i = 0; i < openListCount; i++) {
            if (openList[i]->f < openList[currentNodeIndex]->f) {
                currentNodeIndex = i;
            }
        }

        // Removing the current node from the open list and adding it to the closed list
        node* currentNode = openList[currentNodeIndex];
        openList[currentNodeIndex] = openList[--openListCount];
        closedList[closedListCount++] = currentNode;

        // If the current node is the goal node, print the path and return
        if (currentNode->row == END_ROW && currentNode->col == END_COL) {
            printPath(currentNode);
            return;
        }

        // Generating the children of the current node
        node* children[8];
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                if (i != 0 && j != 0) continue;
                int childRow = currentNode->row + i;
                int childCol = currentNode->col + j;
                if (isObstacle(childRow, childCol)) continue;
                double g = currentNode->g + euclideanDistance(currentNode->row, currentNode->col, childRow, childCol);
                double h = euclideanDistance(childRow, childCol, END_ROW, END_COL);
                double f = g + h;
                node* childNode = newNode(childRow, childCol, g, h, f, currentNode);
                children[childRow * COL + childCol] = childNode;
            }
        }

        // Looping through the children and adding them to the open list if they are not in the open or closed lists already
        for (int i = 0; i < 8; i++) {
            if (children[i] == NULL) continue;
            int inOpenList = 0, inClosedList = 0;
            for (int j = 0; j < openListCount; j++) {
                if (openList[j]->row == children[i]->row && openList[j]->col == children[i]->col) {
                    inOpenList = 1;
                    break;
                }
            }
            for (int j = 0; j < closedListCount; j++) {
                if (closedList[j]->row == children[i]->row && closedList[j]->col == children[i]->col) {
                    inClosedList = 1;
                    break;
                }
            }
            if (!inOpenList && !inClosedList) {
                openList[openListCount++] = children[i];
            }
        }
    }

    // If the goal node is not found and the open list is empty, return
    printf("No path found.");
}

// The main function
int main() {
    aStar();
    return 0;
}