//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

bool isSafe(int r, int c, int grid[ROW][COL]) {
    return r>=0 && r<ROW && c>=0 && c<COL && grid[r][c]!=-1;
}

bool DFS(int grid[ROW][COL], int r, int c, int dest_r, int dest_c, bool visited[ROW][COL]) {
    if (r==dest_r && c==dest_c) {
        return true;
    }

    if (isSafe(r, c, grid) && !visited[r][c]) {
        visited[r][c] = true;

        if (DFS(grid, r-1, c, dest_r, dest_c, visited) || DFS(grid, r+1, c, dest_r, dest_c, visited) || DFS(grid, r, c-1, dest_r, dest_c, visited) || DFS(grid, r, c+1, dest_r, dest_c, visited)) {
            return true;
        }
    }

    return false;
}

void findPath(int grid[ROW][COL], int start_r, int start_c, int dest_r, int dest_c) {
    bool visited[ROW][COL];
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            visited[i][j] = false;
        }
    }

    if (DFS(grid, start_r, start_c, dest_r, dest_c, visited)) {
        printf("Path Found!\n");
    } else {
        printf("Path not found.\n");
    }
}

int main() {
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, -1, -1, -1, -1, 0, -1, -1, -1, 0},
        {0, -1, 0, 0, -1, 0, -1, 0, 0, 0},
        {0, -1, -1, 0, -1, 0, 0, 0, -1, 0},
        {0, -1, 0, 0, -1, -1, -1, -1, -1, 0},
        {0, -1, -1, -1, 0, 0, 0, 0, -1, 0},
        {0, 0, 0, -1, -1, -1, -1, 0, 0, 0},
        {0, -1, 0, 0, 0, 0, 0, 0, -1, 0},
        {0, -1, -1, -1, -1, -1, -1, -1, -1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int start_r = 1, start_c = 1;
    int dest_r = 8, dest_c = 8;

    findPath(grid, start_r, start_c, dest_r, dest_c);

    return 0;
}