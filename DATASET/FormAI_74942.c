//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

typedef struct {
    int x, y;
} Path;

/* Check if tile is valid (within matrix bounds and not an obstacle) */
int isValid(int row, int col, int** grid) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL && grid[row][col] != -1);
}

/* Print the path found by the algorithm */
void printPath(Path* path, int len) {
    printf("Path: ");
    for (int i = 0; i < len; i++) {
        printf("(%d,%d) ", path[i].x, path[i].y);
    }
    printf("\n");
}

/* Pathfinding algorithm using Breadth-First Search */
int BFS(int** grid, Path start, Path end, Path* path) {
    int visited[ROW][COL] = {0};
    Path queue[ROW*COL];
    int head = 0, tail = 0;
    queue[tail++] = start;
    visited[start.x][start.y] = 1;
    while (head < tail) {
        Path current = queue[head++];
        if (current.x == end.x && current.y == end.y) {
            /* Path found */
            int len = visited[current.x][current.y] - 1;
            path[len] = current;
            for (int i = len-1; i >= 0; i--) {
                for (int r = -1; r <= 1; r++) {
                    for (int c = -1; c <= 1; c++) {
                        if ((r == 0 && c == 0) || (r != 0 && c != 0)) {
                            /* Skip diagonals and current tile */
                            continue;
                        }
                        int row = path[i+1].x + r;
                        int col = path[i+1].y + c;
                        if (isValid(row, col, grid) && visited[row][col] == i+1) {
                            path[i] = (Path){row, col};
                            break;
                        }
                    }
                }
            }
            return len+1;
        }
        /* Visit neighbors */
        for (int r = -1; r <= 1; r++) {
            for (int c = -1; c <= 1; c++) {
                if ((r == 0 && c == 0) || (r != 0 && c != 0)) {
                    /* Skip diagonals and current tile */
                    continue;
                }
                int row = current.x + r;
                int col = current.y + c;
                if (isValid(row, col, grid) && !visited[row][col]) {
                    visited[row][col] = visited[current.x][current.y] + 1;
                    queue[tail++] = (Path){row, col};
                }
            }
        }
    }
    /* Path not found */
    return -1;
}

int main() {
    int grid[ROW][COL] = {
        {0, 0, 0, -1, 0},
        {0, -1, 0, 0, 0},
        {0, 0, 0, -1, 0},
        {0, -1, 0, -1, 0},
        {0, 0, 0, 0, 0}
    };
    Path start = {0, 0};
    Path end = {ROW-1, COL-1};
    Path path[ROW*COL];
    int len = BFS((int**)grid, start, end, path);
    if (len > 0) {
        printPath(path, len);
    } else {
        printf("Path not found\n");
    }
    return 0;
}