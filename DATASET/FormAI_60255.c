//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 10
#define COLS 10

// Define data structure for a single node in the grid
typedef struct node {
    int row;
    int col;
    int g;
    int h;
    int f;
    struct node *parent;
} node;

// Define the grid as a 2D array of nodes
node grid[ROWS][COLS];

// Define helper functions for the A* algorithm
int heuristic(int r1, int c1, int r2, int c2) {
    // Calculate the heuristic value based on the Euclidean distance between two nodes
    return sqrt(pow(r2 - r1, 2) + pow(c2 - c1, 2));
}

node* lowest_f_cost(node **open_set, int open_set_size) {
    // Find the node with the lowest f score in the open set
    node *lowest = open_set[0];
    for (int i = 1; i < open_set_size; i++) {
        if (open_set[i]->f < lowest->f) {
            lowest = open_set[i];
        }
    }
    return lowest;
}

int main() {
    // Initialize the grid with random values for g and h
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].g = rand() % 10;
            grid[i][j].h = rand() % 10;
            grid[i][j].f = grid[i][j].g + grid[i][j].h;
            grid[i][j].parent = NULL;
        }
    }
    
    // Define the start and end nodes
    node *start = &grid[0][0];
    node *end = &grid[ROWS - 1][COLS - 1];
    
    // Initialize the open and closed sets
    int open_set_size = 1;
    node *open_set[ROWS * COLS];
    open_set[0] = start;
    int closed_set_size = 0;
    node *closed_set[ROWS * COLS];
    
    // Start the A* algorithm
    while (open_set_size > 0) {
        // Find the node with the lowest f cost in the open set
        node *current = lowest_f_cost(open_set, open_set_size);
        
        if (current == end) {
            // We have found the shortest path
            break;
        }
        
        // Remove the current node from the open set and add it to the closed set
        for (int i = 0; i < open_set_size; i++) {
            if (open_set[i] == current) {
                for (int j = i; j < open_set_size - 1; j++) {
                    open_set[j] = open_set[j + 1];
                }
                open_set_size--;
                break;
            }
        }
        closed_set[closed_set_size++] = current;
        
        // Check each neighboring node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int row = current->row + i;
                int col = current->col + j;
                if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
                    // Node is out of bounds
                    continue;
                }
                node *neighbor = &grid[row][col];
                if (neighbor == current) {
                    // Don't check the current node
                    continue;
                }
                if (neighbor->g == 0 && neighbor != end) {
                    // Node is impassable
                    continue;
                }
                if (neighbor->f <= current->f) {
                    // Neighbor node has already been evaluated
                    continue;
                }
                
                // Calculate the g, h, and f scores for the neighbor node
                int tentative_g = current->g + 1;
                int tentative_h = heuristic(row, col, end->row, end->col);
                int tentative_f = tentative_g + tentative_h;
                
                // Add the neighbor node to the open set if it is not already there
                int found = 0;
                for (int k = 0; k < open_set_size; k++) {
                    if (open_set[k] == neighbor) {
                        found = 1;
                        if (tentative_f < neighbor->f) {
                            // Update the neighbor node's scores
                            neighbor->g = tentative_g;
                            neighbor->h = tentative_h;
                            neighbor->f = tentative_f;
                            neighbor->parent = current;
                        }
                        break;
                    }
                }
                if (!found) {
                    open_set[open_set_size++] = neighbor;
                    neighbor->g = tentative_g;
                    neighbor->h = tentative_h;
                    neighbor->f = tentative_f;
                    neighbor->parent = current;
                }
            }
        }
    }
    
    // Trace back the shortest path from the end to the start node
    node *path[ROWS * COLS];
    int path_size = 0;
    node *current = end;
    while (current != start) {
        path[path_size++] = current;
        current = current->parent;
    }
    path[path_size++] = start;
    
    // Print the grid with the shortest path highlighted
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int is_path = 0;
            for (int k = 0; k < path_size; k++) {
                if (path[k] == &grid[i][j]) {
                    is_path = 1;
                    break;
                }
            }
            if (is_path) {
                printf("\033[1m*\033[0m ");
            } else if (grid[i][j].g == 0 && &grid[i][j] != start) {
                printf("\033[1mx\033[0m ");
            } else {
                printf("%d ", grid[i][j].g);
            }
        }
        printf("\n");
    }
    
    return 0;
}