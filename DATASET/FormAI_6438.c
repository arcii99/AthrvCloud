//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: inquisitive
#include<stdio.h>

// Define the maze using a 2D array
int maze[5][5] = {
    {0, 0, 0, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0}
};

int visited[5][5] = {0}; // keep track of visited cells

int path[25]; // store the path

int path_index = 0; // index of next empty slot in path[]

// Function to find the route through the maze
void findRoute(int row, int col) {
    visited[row][col] = 1; // Mark the current cell as visited
    
    // base case: we've reached the end of the maze
    if (row == 4 && col == 4) { 
        printf("Route: ");
        for (int i = 0; i < path_index; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }
    
    // try moving right
    if (col < 4 && maze[row][col+1] == 0 && visited[row][col+1] == 0) {
        path[path_index++] = 1; // add 1 to path
        findRoute(row, col+1);
        path_index--; // undo the last move
    }
    
    // try moving down
    if (row < 4 && maze[row+1][col] == 0 && visited[row+1][col] == 0) {
        path[path_index++] = 2; // add 2 to path
        findRoute(row+1, col);
        path_index--; // undo the last move
    }
    
    // try moving left
    if (col > 0 && maze[row][col-1] == 0 && visited[row][col-1] == 0) {
        path[path_index++] = 3; // add 3 to path
        findRoute(row, col-1);
        path_index--; // undo the last move
    }
    
    // try moving up
    if (row > 0 && maze[row-1][col] == 0 && visited[row-1][col] == 0) {
        path[path_index++] = 4; // add 4 to path
        findRoute(row-1, col);
        path_index--; // undo the last move
    }
    
    visited[row][col] = 0; // unmark the current cell as visited
}

int main() {
    findRoute(0, 0);
    return 0;
}