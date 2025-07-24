//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

// Function to check if the current point is valid
bool valid_point(int maze[ROW][COL], int row, int col, bool visited[ROW][COL])
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (maze[row][col] && !visited[row][col]);
}

// Function to print the final maze route
void print_route(int route[ROW][COL])
{
    printf("The final maze route is:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", route[i][j]);
        }
        printf("\n");
    }
}

// Recursive function to find the route through the maze
bool maze_route(int maze[ROW][COL], int row, int col, int route[ROW][COL], bool visited[ROW][COL])
{
    // if the ending point is reached, the route is found
    if (row == ROW - 1 && col == COL - 1) {
        route[row][col] = 1;
        return true;
    }

    // if current point is valid, mark it as visited and add to route
    if (valid_point(maze, row, col, visited)) {
        visited[row][col] = true;
        route[row][col] = 1;

        // finding the route through the adjacent points
        if (maze_route(maze, row - 1, col, route, visited)) {
            return true;
        }
        if (maze_route(maze, row, col - 1, route, visited)) {
            return true;
        }
        if (maze_route(maze, row + 1, col, route, visited)) {
            return true;
        }
        if (maze_route(maze, row, col + 1, route, visited)) {
            return true;
        }

        // if none of adjacent points lead to the route, backtrack and mark the current point as unvisited
        route[row][col] = 0;
    }

    return false;
}

int main()
{
    int maze[ROW][COL] = {
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 1}
    };

    int route[ROW][COL];
    memset(route, 0, sizeof(route));  // setting the route to all zeros

    bool visited[ROW][COL];
    memset(visited, false, sizeof(visited));  // setting all points to unvisited

    if (maze_route(maze, 0, 0, route, visited)) {
        print_route(route);
    }
    else {
        printf("Could not find the route.");
    }

    return 0;
}