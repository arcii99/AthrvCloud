//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: single-threaded
#include <stdio.h>

#define N 5 // the size of the maze, assuming that it is a square

int maze[N][N] = { // a sample maze
    {1, 0, 1, 1, 0},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 1},
    {1, 1, 1, 0, 1}
};

int visited[N][N] = {0}; // initialize all elements to 0

int start_x = 0; // starting position
int start_y = 0;

int end_x = N-1; // ending position
int end_y = N-1;

int path[N*N][2]; // store the path

int path_len = 0; // path length

int solve(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) { // out of bounds
        return 0;
    }

    if (!maze[x][y] || visited[x][y]) { // obstacle or already visited
        return 0;
    }

    visited[x][y] = 1; // mark as visited

    path[path_len][0] = x;
    path[path_len][1] = y;
    path_len++;

    if (x == end_x && y == end_y) { // found the end
        return 1;
    }

    if (solve(x+1, y) || solve(x-1, y) || solve(x, y+1) || solve(x, y-1)) { 
        return 1;
    }

    path_len--; // backtrack
    return 0;
}

int main() {
    if (solve(start_x, start_y)) { // solution found
        printf("Path:\n");
        for (int i = 0; i < path_len; i++) {
            printf("(%d,%d)\n", path[i][0], path[i][1]);
        }
    } else { // no solution found
        printf("No path found\n");
    }
    return 0;
}