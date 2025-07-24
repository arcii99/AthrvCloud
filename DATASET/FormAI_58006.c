//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Node structure for A* algorithm
typedef struct Node {
    int x, y;
    int f, g, h;
    struct Node* parent;
} Node;

// Function to calculate the Manhattan distance heuristic
int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// A* pathfinding algorithm implementation
void findPath(int maze[][COLS], int startX, int startY, int endX, int endY) {
    // Initialize the start and end nodes
    Node start = {startX, startY, 0, 0, 0, NULL};
    Node end = {endX, endY, 0, 0, 0, NULL};
    
    // Initialize the open and closed lists
    Node* openList[100];
    int openListSize = 0;
    Node* closedList[100];
    int closedListSize = 0;
    
    // Add the start node to the open list
    openList[openListSize++] = &start;
    
    while (openListSize > 0) {
        // Sort the open list by f value
        for (int i = 0; i < openListSize - 1; i++) {
            for (int j = i + 1; j < openListSize; j++) {
                if (openList[j]->f < openList[i]->f) {
                    Node* temp = openList[i];
                    openList[i] = openList[j];
                    openList[j] = temp;
                }
            }
        }
        
        // Get the node with the lowest f value
        Node* current = openList[0];
        
        // Remove the node from the open list
        for (int i = 0; i < openListSize - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openListSize--;
        
        // Add the node to the closed list
        closedList[closedListSize++] = current;
        
        // Check if the current node is the end node
        if (current->x == end.x && current->y == end.y) {
            Node* path[100];
            Node* node = current;
            int pathSize = 0;
            
            // Build the path from end to start by following parent pointers
            while (node != NULL) {
                path[pathSize++] = node;
                node = node->parent;
            }
            
            // Print the path from start to end
            printf("Path Found!\n");
            for (int i = pathSize - 1; i >= 0; i--) {
                printf("(%d, %d) -> ", path[i]->x, path[i]->y);
            }
            printf("\n");
            return;
        }
        
        // Check the neighbors of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // Skip the current node
                if (i == 0 && j == 0) {
                    continue;
                }
                
                int nextX = current->x + i;
                int nextY = current->y + j;
                
                // Skip nodes outside the maze bounds
                if (nextX < 0 || nextX >= ROWS || nextY < 0 || nextY >= COLS) {
                    continue;
                }
                
                // Skip nodes that are walls
                if (maze[nextX][nextY] == 1) {
                    continue;
                }
                
                // If the neighbor is already in the closed list, skip it
                int skip = 0;
                for (int k = 0; k < closedListSize; k++) {
                    if (closedList[k]->x == nextX && closedList[k]->y == nextY) {
                        skip = 1;
                        break;
                    }
                }
                if (skip) {
                    continue;
                }
                
                // Calculate the f, g, and h values for the neighbor
                int g = current->g + 1;
                int h = manhattanDistance(nextX, nextY, end.x, end.y);
                int f = g + h;
                
                // Check if the neighbor is already in the open list
                Node* neighbor = NULL;
                for (int k = 0; k < openListSize; k++) {
                    if (openList[k]->x == nextX && openList[k]->y == nextY) {
                        neighbor = openList[k];
                        break;
                    }
                }
                
                // If the neighbor is not in the open list, add it
                if (neighbor == NULL) {
                    neighbor = (Node*)malloc(sizeof(Node));
                    neighbor->x = nextX;
                    neighbor->y = nextY;
                    neighbor->f = f;
                    neighbor->g = g;
                    neighbor->h = h;
                    neighbor->parent = current;
                    openList[openListSize++] = neighbor;
                }
                // If the neighbor is already in the open list, update its values if necessary
                else if (f < neighbor->f) {
                    neighbor->f = f;
                    neighbor->g = g;
                    neighbor->h = h;
                    neighbor->parent = current;
                }
            }
        }
    }
    
    // If no path is found, print an error message
    printf("No Path Found\n");
}

// Driver function to test the A* algorithm
int main() {
    int maze[ROWS][COLS] = {
        {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 1, 1, 1, 0}
    };
    
    findPath(maze, 0, 0, 9, 9);
    
    return 0;
}