//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define row and column size of the grid
#define ROW 6
#define COL 6

// Define the struct for a node
struct node {
    int x;
    int y;
    int f;
    int g;
    int h;
    struct node* parent;
};

// Define the function to find the shortest path
struct node* findPath(int grid[][COL], struct node* start, struct node* end) {
    // Define variables for the open and closed list of nodes
    struct node* openList[ROW*COL];
    struct node* closedList[ROW*COL];
    int openSize = 0;
    int closedSize = 0;

    // Initialize the start node
    start->f = 0;
    start->g = 0;
    start->h = 0;
    start->parent = NULL;

    // Add the start node to the open list
    openList[openSize++] = start;

    // Loop until the open list is empty or the end node is found
    while (openSize > 0) {
        // Find the node in the open list with the lowest f value
        int index = 0;
        for (int i = 0; i < openSize; i++) {
            if (openList[i]->f < openList[index]->f) {
                index = i;
            }
        }

        // Remove the node with the lowest f value from the open list
        struct node* current = openList[index];
        openList[index] = openList[--openSize];

        // If the current node is the end node, return the path
        if (current->x == end->x && current->y == end->y) {
            return current;
        }

        // Add the current node to the closed list
        closedList[closedSize++] = current;

        // Generate the child nodes
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                // Skip the current node and diagonal nodes
                if ((dx == 0 && dy == 0) || (dx != 0 && dy != 0)) {
                    continue;
                }

                // Calculate the coordinates of the child node
                int x = current->x + dx;
                int y = current->y + dy;

                // Skip nodes outside of the grid
                if (x < 0 || x >= ROW || y < 0 || y >= COL) {
                    continue;
                }

                // Skip nodes that are obstacles
                if (grid[x][y] == 1) {
                    continue;
                }

                // Calculate the child node's g, h, and f values
                int g = current->g + 1;
                int h = (int)(10 * sqrt(pow(x - end->x, 2) + pow(y - end->y, 2)));
                int f = g + h;

                // Check if the child node is in the closed list
                int inClosedList = 0;
                for (int i = 0; i < closedSize; i++) {
                    if (closedList[i]->x == x && closedList[i]->y == y) {
                        inClosedList = 1;
                        break;
                    }
                }
                if (inClosedList) {
                    continue;
                }

                // Check if the child node is in the open list
                int inOpenList = 0;
                for (int i = 0; i < openSize; i++) {
                    if (openList[i]->x == x && openList[i]->y == y) {
                        inOpenList = 1;
                        break;
                    }
                }

                // If the child node is not in the open list, add it in
                if (!inOpenList) {
                    struct node* child = (struct node*) malloc(sizeof(struct node));
                    child->x = x;
                    child->y = y;
                    child->g = g;
                    child->h = h;
                    child->f = f;
                    child->parent = current;
                    openList[openSize++] = child;
                }

                // If the child node is in the open list, update its g value and parent if necessary
                else {
                    for (int i = 0; i < openSize; i++) {
                        if (openList[i]->x == x && openList[i]->y == y) {
                            struct node* child = openList[i];
                            if (g < child->g) {
                                child->g = g;
                                child->f = g + child->h;
                                child->parent = current;
                            }
                        }
                    }
                }
            }
        }
    }

    // If the end node is not found, return NULL
    return NULL;
}

// Define the main function
int main() {
    // Initialize the grid with obstacles
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    // Define the start and end nodes
    struct node start = {0, 0};
    struct node end = {5, 5};

    // Find the shortest path
    struct node* path = findPath(grid, &start, &end);

    // Print the path
    while (path != NULL) {
        printf("(%d, %d) -> ", path->x, path->y);
        path = path->parent;
    }
    printf("Done.\n");

    return 0;
}