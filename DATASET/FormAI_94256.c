//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 10
#define COL 10

// Node structure
typedef struct {
    int x, y;   // coordinates of the node
    int f, g, h; // cost variables
    int visited;   
    int parent_x, parent_y; // parent node
} Node;

// Function to initialize the nodes
void initNodes(Node nodes[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            nodes[i][j].x = i;
            nodes[i][j].y = j;
            nodes[i][j].f = 0;
            nodes[i][j].g = 0;
            nodes[i][j].h = 0;
            nodes[i][j].visited = 0;
            nodes[i][j].parent_x = -1;
            nodes[i][j].parent_y = -1;
        }
    }
}

// Function to calculate the heuristic cost (Manhattan distance)
int calculateHeuristic(int x1, int y1, int x2, int y2) {
    return (abs(x1 - x2) + abs(y1 - y2));
}

// Function to check if a node is valid/accessible
int isValid(int x, int y) {
    return x >= 0 && x < ROW && y >= 0 && y < COL;
}

// Function to check if a node is blocked by an obstacle
int isUnBlocked(int grid[][COL], int x, int y) {
    return grid[x][y] == 0;
}

// Function to check if a node has been visited
int isNotVisited(int visited[][COL], int x, int y) {
    return !visited[x][y];
}

// Function to find the path using A* algorithm
void aStar(Node nodes[ROW][COL], int grid[][COL], int startX, int startY, int endX, int endY) {
    // Define the possible directions the algorithm can move
    int rowDir[] = {-1, 0, 1, 0};
    int colDir[] = {0, 1, 0, -1};
    
    // Create a closed list to mark the visited nodes
    int visited[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            visited[i][j] = 0;
        }
    }
    
    // Create an open list to store the nodes to be visited
    int openList[(ROW * COL) + 1][2];
    int openListCount = 0;
    
    // Mark the start node as visited and add it to the open list
    visited[startX][startY] = 1;
    nodes[startX][startY].f = 0;
    nodes[startX][startY].g = 0;
    nodes[startX][startY].h = 0;
    openList[openListCount][0] = startX;
    openList[openListCount][1] = startY;
    openListCount++;
    
    // While there are still nodes to be visited
    while (openListCount > 0) {
        // Find the node with the lowest f value (the best candidate node)
        int currentX = openList[0][0], currentY = openList[0][1];
        int bestNodeIndex = 0;
        for (int i = 1; i < openListCount; i++) {
            if (nodes[openList[i][0]][openList[i][1]].f < nodes[currentX][currentY].f) {
                currentX = openList[i][0];
                currentY = openList[i][1];
                bestNodeIndex = i;
            }
        }
        
        // Remove the best candidate node from the open list
        openList[bestNodeIndex][0] = openList[openListCount - 1][0];
        openList[bestNodeIndex][1] = openList[openListCount - 1][1];
        openListCount--;
        
        // Set the current node as visited
        visited[currentX][currentY] = 1;
        nodes[currentX][currentY].visited = 1;
        
        // If the current node is the end node, exit the loop and backtrack to find the path
        if (currentX == endX && currentY == endY) {
            return;
        }
        
        // Consider all the neighbors of the current node
        for (int i = 0; i < 4; i++) {
            int newX = currentX + rowDir[i];
            int newY = currentY + colDir[i];
            
            // If the neighbor is valid and not blocked by an obstacle
            if (isValid(newX, newY) && isUnBlocked(grid, newX, newY)) {
                // If the neighbor has not been visited before or the g cost (distance from start node) is less than before
                if (isNotVisited(visited, newX, newY) || (nodes[currentX][currentY].g + 1) < nodes[newX][newY].g) {
                    // Calculate the g, h and f cost for the neighbor
                    nodes[newX][newY].g = nodes[currentX][currentY].g + 1;
                    nodes[newX][newY].h = calculateHeuristic(newX, newY, endX, endY);
                    nodes[newX][newY].f = nodes[newX][newY].g + nodes[newX][newY].h;
                    nodes[newX][newY].parent_x = currentX;
                    nodes[newX][newY].parent_y = currentY;
                    
                    // Add the neighbor to the open list
                    openList[openListCount][0] = newX;
                    openList[openListCount][1] = newY;
                    openListCount++;
                }
            }
        }
    }
    
    // If there is no path to the end node
    if (!nodes[endX][endY].visited) {
        printf("\nThere is no path to the end node.\n");
        return;
    }
    
    // Backtrack from the end node to find the path
    int pathLength = 0;
    int currentX = endX, currentY = endY;
    while (currentX != startX || currentY != startY) {
        pathLength++;
        int tempX = currentX;
        currentX = nodes[currentX][currentY].parent_x;
        currentY = nodes[tempX][currentY].parent_y;
    }
    
    // Print the path
    printf("\nLength of the shortest path: %d\n", pathLength);
    printf("\nThe path (from end node to start node):\n");
    currentX = endX, currentY = endY;
    while (currentX != startX || currentY != startY) {
        printf("(%d, %d) --> ", currentX, currentY);
        int tempX = currentX;
        currentX = nodes[currentX][currentY].parent_x;
        currentY = nodes[tempX][currentY].parent_y;
    }
    printf("(%d, %d)\n", startX, startY);
}

// Main function
int main() {
    // The obstacle array (0 -> unblocked, 1 -> blocked)
    int grid[ROW][COL] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
                          {0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
                          {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
                          {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                          {0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    
    // The nodes array
    Node nodes[ROW][COL];
    
    // Initialize the nodes
    initNodes(nodes);
    
    // Define the start and end nodes
    int startX = 0, startY = 0, endX = 9, endY = 9;
    
    // Find the path using A* algorithm
    aStar(nodes, grid, startX, startY, endX, endY);
    
    return 0;
}