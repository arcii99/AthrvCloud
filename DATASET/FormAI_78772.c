//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

bool visited[ROW][COL];
int grid[ROW][COL];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool is_valid_move(int x, int y) {
    if (x >= 0 && x < ROW && y >= 0 && y < COL) {
        if (!visited[x][y] && grid[x][y] != -1) {
            return true;
        }
    }
    return false;
}

bool dfs(int x, int y, int fx, int fy) {
    if (x == fx && y == fy) return true;
    
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_valid_move(nx, ny)) {
            if (dfs(nx, ny, fx, fy)) {
                return true;
            }
        }
    }
    //no path was found, roll back
    visited[x][y] = false;
    return false;
}

int main() {
    // create a grid and set some obstacles (-1)
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == 3 && j < 5) {
                grid[i][j] = -1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    
    // mark start and finish cells
    int sx = 0, sy = 0, fx = ROW-1, fy = COL-1;
    
    // compute the path using depth-first search
    bool path_found = dfs(sx, sy, fx, fy);
    
    if (path_found) {
        printf("Path found!\n");
    } else {
        printf("Could not find a path\n");
    }
    
    return 0;
}