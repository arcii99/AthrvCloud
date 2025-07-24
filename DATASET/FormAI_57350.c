//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Global variable to keep track of the solution path
int path[ROWS*COLS][2];
int path_length = 0;

// Heuristic function to estimate the distance between two points
int heuristic(int start_x, int start_y, int goal_x, int goal_y) {
    int dx = abs(start_x - goal_x);
    int dy = abs(start_y - goal_y);
    return dx + dy;
}

// A* Search Algorithm
void AStar_search(int maze[ROWS][COLS], int start_x, int start_y, int goal_x, int goal_y) {
    // Create a list of open nodes and closed nodes
    int open_list[ROWS*COLS][2];
    int closed_list[ROWS*COLS][2];
    int open_list_length = 1;
    int closed_list_length = 0;
    
    // Initialize the starting node
    open_list[0][0] = start_x;
    open_list[0][1] = start_y;
    int current_x = start_x;
    int current_y = start_y;
    
    // Loop until the goal node is found or there are no more nodes to expand
    while (open_list_length > 0) {
        // Find the node in the open list with the lowest f-value
        int current_f = ROWS*COLS;
        int current_index = 0;
        for (int i=0; i<open_list_length; i++) {
            int x = open_list[i][0];
            int y = open_list[i][1];
            int f = heuristic(x, y, goal_x, goal_y);
            if (f < current_f) {
                current_f = f;
                current_index = i;
                current_x = x;
                current_y = y;
            }
        }
        
        // Move the current node from the open list to the closed list
        open_list[current_index][0] = open_list[open_list_length-1][0];
        open_list[current_index][1] = open_list[open_list_length-1][1];
        open_list_length--;
        
        closed_list[closed_list_length][0] = current_x;
        closed_list[closed_list_length][1] = current_y;
        closed_list_length++;
        
        // Check if the goal node has been reached
        if (current_x == goal_x && current_y == goal_y) {
            // Reconstruct the path by following the parent pointers
            int i = closed_list_length-1;
            int x = closed_list[i][0];
            int y = closed_list[i][1];
            path_length = 0;
            while (i > 0) {
                i--;
                int px = closed_list[i][0];
                int py = closed_list[i][1];
                if ((px == x-1 && py == y) || (px == x+1 && py == y)
                    || (px == x && py == y-1) || (px == x && py == y+1)) {
                    path[path_length][0] = px;
                    path[path_length][1] = py;
                    path_length++;
                    x = px;
                    y = py;
                }
            }
            return;
        }
        
        // Expand the current node by considering all its neighbors
        for (int i=-1; i<=1; i++) {
            for (int j=-1; j<=1; j++) {
                int neighbor_x = current_x + i;
                int neighbor_y = current_y + j;
                if (neighbor_x >= 0 && neighbor_x < ROWS
                    && neighbor_y >= 0 && neighbor_y < COLS
                    && !(i == 0 && j == 0)  // Don't consider the current node
                    && maze[neighbor_x][neighbor_y] == 0) {
                    // Check if the neighbor has already been visited
                    int skip = 0;
                    for (int k=0; k<closed_list_length; k++) {
                        if (closed_list[k][0] == neighbor_x
                            && closed_list[k][1] == neighbor_y) {
                            skip = 1;
                            break;
                        }
                    }
                    if (skip) {
                        continue;
                    }
                    // Compute the g-value
                    int g = heuristic(neighbor_x, neighbor_y, start_x, start_y);
                    // Compute the f-value
                    int f = g + heuristic(neighbor_x, neighbor_y, goal_x, goal_y);
                    // Add the neighbor to the open list
                    open_list[open_list_length][0] = neighbor_x;
                    open_list[open_list_length][1] = neighbor_y;
                    open_list_length++;
                }
            }
        }
    }
}

int main() {
    // Create a 2D maze
    int maze[ROWS][COLS] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,0,1,1,1,1,1,0,0},
        {0,1,0,0,0,0,0,1,0,0},
        {0,1,1,1,0,1,0,1,0,0},
        {0,0,0,1,0,1,0,1,0,0},
        {0,0,0,1,0,1,0,1,0,0},
        {0,1,1,1,0,1,0,1,0,0},
        {0,1,0,0,0,0,0,1,0,0},
        {0,1,0,1,1,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    
    // Find a path through the maze
    int start_x = 1;
    int start_y = 1;
    int goal_x = 8;
    int goal_y = 8;
    AStar_search(maze, start_x, start_y, goal_x, goal_y);
    
    // Print the solution path
    printf("Solution Path:\n");
    for (int i=path_length-1; i>=0; i--) {
        printf("(%d, %d)\n", path[i][0], path[i][1]);
    }
    
    return 0;
}