//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#define ROW 7 // Number of rows in the maze
#define COL 13 // Number of columns in the maze

int maze[ROW][COL] = { // Define the maze using a 2D array of integers
    {1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,0,0,0,1},
    {1,0,0,1,0,0,0,1,0,0,0,0,1},
    {1,0,0,0,0,1,1,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int visited[ROW][COL]; // Initialize visited array

// Recursive function to find the route from start to finish
int findRoute(int x, int y) {
    if (x == ROW - 2 && y == COL - 2) { // Base case: reached the finish
        printf("Love found the route through the maze! \n");
        return 1;
    } else if (maze[x][y] == 1 || visited[x][y] == 1) { // Wall or already visited
        return 0;
    } else {
        visited[x][y] = 1; // Mark the current cell as visited
        if (findRoute(x + 1, y) || findRoute(x - 1, y) || findRoute(x, y + 1) || findRoute(x, y - 1)) { // Recursively search in all directions
            printf("(%d,%d) \n", x, y); // Print the current cell's coordinates
            return 1;
        }
        return 0;
    }
}

int main() {
    printf("Welcome to the Maze of love! \n");
    printf("Guide us to the end by finding the route through the maze \n\n");
    printf("Starting at (1,1) \n\n");
    
    if (findRoute(1, 1)) { // Start search from the top left corner
        printf("\n");
    } else {
        printf("Love is lost in the maze... \n");
    }
    
    return 0;
}