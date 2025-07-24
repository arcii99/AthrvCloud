//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Alan Touring
#include <stdio.h>

#define ROW 10
#define COL 10

// To store the coordinates of a point
struct Point {
    int x;
    int y;
};

void printPath(struct Point path[], int n) {
    printf("The path is: ");
    for (int i=0; i<n; i++) {
        printf("(%d,%d) ", path[i].x, path[i].y);
    }
    printf("\n");
}

// Helper function to check if a point is valid or not
int is_valid_point(int maze[][COL], int row, int col, int vis[][COL], int x, int y) {
    return (x >=0 && x < row && y >=0 && y < col && maze[x][y] == 1 && vis[x][y] == 0);
}

// Function to find the path in a maze using Backtracking
int maze_route_finder(int maze[][COL], int row, int col, int vis[][COL], struct Point path[], struct Point start, struct Point end, int index) {
    
    // If current point is the end point, then return true
    if (start.x == end.x && start.y == end.y) {
        path[index] = start;
        printPath(path, index+1);
        return 1;
    }
    
    // If current point is not valid then return false
    if (!is_valid_point(maze, row, col, vis, start.x, start.y)) {
        return 0;
    }
    
    // Mark the current point as visited
    vis[start.x][start.y] = 1;
    path[index] = start;
    
    // Check in all 4 directions
    if (maze_route_finder(maze, row, col, vis, path, (struct Point){start.x+1, start.y}, end, index+1)
        || maze_route_finder(maze, row, col, vis, path, (struct Point){start.x-1, start.y}, end, index+1)
        || maze_route_finder(maze, row, col, vis, path, (struct Point){start.x, start.y+1}, end, index+1)
        || maze_route_finder(maze, row, col, vis, path, (struct Point){start.x, start.y-1}, end, index+1)) {
        return 1;
    }
    
    // Mark the current point as unvisited
    vis[start.x][start.y] = 0;
    
    return 0;
}

int main()
{
    int maze[ROW][COL] = {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    
    int visited[ROW][COL] = {0};
    
    struct Point path[ROW*COL];
    
    struct Point start = {0,0};
    struct Point end = {7,8};
    
    if (!maze_route_finder(maze, ROW, COL, visited, path, start, end, 0)) {
        printf("No path found in the maze.");
    }
    
    return 0;
}