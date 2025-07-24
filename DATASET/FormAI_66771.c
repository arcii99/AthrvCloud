//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define the grid dimensions
#define ROWS 5
#define COLS 5

// define the node structure
typedef struct Node {
    int row, col;
    int fScore, gScore, hScore;
    bool isWall, isClosed, isOpen;
    struct Node* parent;
} Node;

// define the grid
Node grid[ROWS][COLS];

// define the start and end nodes
Node* startNode;
Node* endNode;

// define the open and closed sets
Node* openSet[ROWS * COLS];
int openSetSize = 0;

Node* closedSet[ROWS * COLS];
int closedSetSize = 0;

// define the heuristic function (Manhattan distance)
int heuristic(Node* a, Node* b) {
    return abs(a->row - b->row) + abs(a->col - b->col);
}

// define the function to check if a node is in the array
bool contains(Node** array, int size, Node* node) {
    for(int i = 0; i < size; i++) {
        if(array[i] == node) {
            return true;
        }
    }
    return false;
}

// define the function to remove a node from the array
void removeNode(Node** array, int size, Node* node) {
    int i;
    for(i = 0; i < size; i++) {
        if(array[i] == node) {
            break;
        }
    }
    for(int j = i; j < size-1; j++) {
        array[j] = array[j+1];
    }
    array[size-1] = NULL;
}

// define the function to get the node with the lowest fScore
Node* getLowestFScoreNode() {
    Node* lowest = openSet[0];
    for(int i = 1; i < openSetSize; i++) {
        if(openSet[i]->fScore < lowest->fScore) {
            lowest = openSet[i];
        }
    }
    return lowest;
}

// define the function to get the neighbors of a node
Node** getNeighbors(Node* node) {
    int row = node->row;
    int col = node->col;
    Node** neighbors = malloc(sizeof(Node*) * 4);
    int count = 0;
    if(row > 0 && !grid[row-1][col].isWall) {
        neighbors[count++] = &grid[row-1][col];
    }
    if(row < ROWS-1 && !grid[row+1][col].isWall) {
        neighbors[count++] = &grid[row+1][col];
    }
    if(col > 0 && !grid[row][col-1].isWall) {
        neighbors[count++] = &grid[row][col-1];
    }
    if(col < COLS-1 && !grid[row][col+1].isWall) {
        neighbors[count++] = &grid[row][col+1];
    }
    neighbors = realloc(neighbors, sizeof(Node*) * count);
    return neighbors;
}

// define the function to print the grid with path
void printGrid() {
    printf("\033[2J");
    printf("\033[0;0H");
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            if(&grid[row][col] == startNode) {
                printf("S");
            } else if(&grid[row][col] == endNode) {
                printf("E");
            } else if(grid[row][col].isWall) {
                printf("#");
            } else if(grid[row][col].isOpen) {
                printf("-");
            } else if(grid[row][col].isClosed) {
                printf(".");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// define the main function
int main() {

    // initialize the grid
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            grid[row][col].row = row;
            grid[row][col].col = col;
            grid[row][col].isWall = false;
            grid[row][col].isClosed = false;
            grid[row][col].isOpen = false;
            grid[row][col].fScore = 0;
            grid[row][col].gScore = 0;
            grid[row][col].hScore = 0;
            grid[row][col].parent = NULL;
        }
    }

    // add walls to the grid
    grid[1][1].isWall = true;
    grid[1][2].isWall = true;
    grid[1][3].isWall = true;
    grid[2][3].isWall = true;
    grid[3][3].isWall = true;

    // set the start and end nodes
    startNode = &grid[0][0];
    endNode = &grid[ROWS-1][COLS-1];

    // initialize the start node
    startNode->gScore = 0;
    startNode->hScore = heuristic(startNode, endNode);
    startNode->fScore = startNode->gScore + startNode->hScore;
    startNode->isOpen = true;
    openSet[openSetSize++] = startNode;

    // perform the A* algorithm
    while(openSetSize > 0) {

        // get the node with the lowest fScore
        Node* current = getLowestFScoreNode();

        // check if we have reached the goal
        if(current == endNode) {
            // print the path
            Node* node = endNode;
            while(node != startNode) {
                node->isClosed = false;
                node = node->parent;
            }
            printGrid();
            break;
        }

        // move the current node from the open to the closed set
        removeNode(openSet, openSetSize, current);
        openSetSize--;
        current->isClosed = true;
        closedSet[closedSetSize++] = current;

        // get the neighbors of the current node
        Node** neighbors = getNeighbors(current);

        // loop through the neighbors
        for(int i = 0; i < 4; i++) {

            // get the neighbor
            Node* neighbor = neighbors[i];

            // check if the neighbor is already in the closed set
            if(contains(closedSet, closedSetSize, neighbor)) {
                continue;
            }

            // calculate the tentative gScore
            int tentativeGScore = current->gScore + 1;

            // check if the neighbor is already in the open set
            if(!contains(openSet, openSetSize, neighbor)) {
                openSet[openSetSize++] = neighbor;
                neighbor->isOpen = true;
            } else if(tentativeGScore >= neighbor->gScore) {
                continue;
            }

            // update the neighbor
            neighbor->parent = current;
            neighbor->gScore = tentativeGScore;
            neighbor->hScore = heuristic(neighbor, endNode);
            neighbor->fScore = neighbor->gScore + neighbor->hScore;
        }

        // free the memory allocated for the neighbors
        free(neighbors);

        // print the grid
        printGrid();
    }

    return 0;
}