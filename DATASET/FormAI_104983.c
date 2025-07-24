//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //initialize maze dimensions
    int n = 10; 
    int m = 15;

    //initialize maze with randomly generated walls
    srand(time(NULL));
    int maze[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = rand() % 2;
            }
        }
    }
    maze[1][0] = 0;
    maze[n-2][m-1] = 0;

    //print initial maze
    printf("Initial Maze:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 1) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    //initialize variables for starting and ending points
    int startX = 1;
    int startY = 0;
    int endX = n-2;
    int endY = m-1;

    //initialize path array
    int path[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            path[i][j] = 0;
        }
    }

    //run recursive function to find path from start to end
    int foundPath = 0;
    if (findPath(maze, path, startX, startY, endX, endY, n, m)) {
        foundPath = 1;
    }

    //print final maze with path marked
    printf("\nFinal Maze with Path:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (path[i][j] == 1) {
                printf(". ");
            } else if (maze[i][j] == 1) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    //print result of path search
    if (foundPath) {
        printf("\nPath found from (%d,%d) to (%d,%d)\n", startX, startY, endX, endY);
    } else {
        printf("\nNo path found from (%d,%d) to (%d,%d)\n", startX, startY, endX, endY);
    }

    return 0;
}

//recursive function to find path from start to end
int findPath(int maze[][15], int path[][15], int x, int y, int endX, int endY, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] == 1 || path[x][y] == 1) {
        return 0;
    } else if (x == endX && y == endY) {
        path[x][y] = 1;
        return 1;
    } else {
        path[x][y] = 1;
        if (findPath(maze, path, x+1, y, endX, endY, n, m)) {
            return 1;
        }
        if (findPath(maze, path, x-1, y, endX, endY, n, m)) {
            return 1;
        }
        if (findPath(maze, path, x, y+1, endX, endY, n, m)) {
            return 1;
        }
        if (findPath(maze, path, x, y-1, endX, endY, n, m)) {
            return 1;
        }
        path[x][y] = 0;
        return 0;
    }
}