//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Romeo and Juliet
// ROMEO AND JULIET'S PATHFINDING ADVENTURE

#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Define the maze as a 2D array
int maze[ROWS][COLS] = {{0,0,0,0,0,0,0,1,0,0},
                        {0,1,0,1,1,1,0,1,0,0},
                        {0,1,0,0,0,1,0,1,0,0},
                        {0,1,1,1,1,1,0,1,0,1},
                        {0,0,0,0,0,0,0,1,0,0},
                        {0,1,0,1,0,1,0,1,0,0},
                        {0,1,0,1,0,1,1,1,1,0},
                        {0,1,0,1,0,0,0,0,1,0},
                        {0,1,1,1,1,1,1,1,1,0},
                        {0,0,0,0,0,0,0,0,0,0}};

struct Node {
    int row;
    int col;
};

// Check if the given row and col are within the bounds of the maze
int isValid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == 0);
}

// Check if the current node is the final destination
int isDestination(int row, int col, struct Node dest) {
    return (row == dest.row && col == dest.col);
}

// Get the neighbour nodes of the current position
void getNeighbors(struct Node curr, struct Node *neighbors) {
    int row = curr.row;
    int col = curr.col;
    
    // Up, down, left, right
    neighbors[0] = (struct Node) {row-1, col};
    neighbors[1] = (struct Node) {row+1, col};
    neighbors[2] = (struct Node) {row, col-1};
    neighbors[3] = (struct Node) {row, col+1};
}

// Calculate the Manhattan distance between two nodes
int calculateDistance(struct Node curr, struct Node dest) {
    return abs(curr.row - dest.row) + abs(curr.col - dest.col);
}

// Calculate the path from start to dest using A* algorithm
void aStar(struct Node start, struct Node dest) {
    struct Node path[ROWS*COLS]; // Array to store the path
    int numNodes = 0; // Number of nodes in the path
    
    // Create the open and closed sets
    struct Node openSet[ROWS*COLS];
    int openSize = 0;
    struct Node closedSet[ROWS*COLS];
    int closedSize = 0;
    
    // Add the starting node to the open set
    openSet[openSize++] = start;
    
    // While the open set is not empty
    while (openSize > 0) {
        // Find the node with the lowest f score in the open set
        int lowest = 0;
        for (int i = 0; i < openSize; i++) {
            if (calculateDistance(openSet[i], dest) < calculateDistance(openSet[lowest], dest)) {
                lowest = i;
            }
        }
        struct Node current = openSet[lowest];
        
        // If we have reached the destination, reconstruct the path and return
        if (isDestination(current.row, current.col, dest)) {
            struct Node node = current;
            while (node.row != start.row || node.col != start.col) {
                path[numNodes++] = node;
                node = closedSet[node.row*COLS + node.col];
            }
            path[numNodes++] = start;
            printf("Romeo: I have found a path to my beloved Juliet!\n");
            for (int i = numNodes-1; i >= 0; i--) {
                printf("(%d,%d) ", path[i].row, path[i].col);
            }
            return;
        }
        
        // Remove the current node from the open set and add it to the closed set
        openSet[lowest] = openSet[--openSize];
        closedSet[current.row*COLS + current.col] = current;
        closedSize++;
        
        // Get the neighbour nodes of the current node
        struct Node neighbors[4];
        getNeighbors(current, neighbors);
        for (int i = 0; i < 4; i++) {
            struct Node neighbor = neighbors[i];
            if (isValid(neighbor.row, neighbor.col)) {
                if (closedSet[neighbor.row*COLS + neighbor.col].row != 0) { // If neighbor is in the closed set, continue
                    continue;
                }
                int newG = calculateDistance(current, neighbor) + calculateDistance(start, neighbor);
                int isNew = 0;
                if (maze[neighbor.row][neighbor.col] == 2){ // Romeo will jump if there is a wall between him and Juliet
                    printf("Romeo: I will jump over this wall to get to my love!\n");
                    isNew = 1;
                }else if (maze[neighbor.row][neighbor.col] == 3){ // Juliet will also jump if there is a wall between them
                    printf("Juliet: I will jump over this wall to be with my Romeo!\n");
                    isNew = 1;
                }else if (maze[neighbor.row][neighbor.col] == 1){ // If there is a wall, skip this neighbor
                    continue;
                }else{ // If the neighbor is not in the open set, add it
                    isNew = 1;
                }
                if (isNew) {
                    neighbor.row = neighbor.row;
                    neighbor.col = neighbor.col;
                    openSet[openSize++] = neighbor;
                    maze[neighbor.row][neighbor.col] = 2;
                }
            }
        }
    }
    printf("Romeo: I could not find a path to Juliet. Alas!\n");
}

int main() {
    printf("Romeo: Ah! My love, Juliet! I must reach her at once!\n");
    struct Node start = (struct Node) {0,0};
    struct Node dest = (struct Node) {9,9};
    aStar(start, dest);
    return 0;
}