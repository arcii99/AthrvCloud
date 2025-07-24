//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

int valid(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

int bfs(int maze[ROW][COL], int visited[ROW][COL], int sx, int sy) {
    // mark source as visited
    visited[sx][sy] = 1;

    // queue for BFS
    int queue[50][2], front = -1, rear = -1;
    queue[++rear][0] = sx;
    queue[rear][1] = sy;

    while(front < rear) {
        int x = queue[++front][0];
        int y = queue[front][1];

        // if we reach the destination
        if(maze[x][y] == 1) {
            return 1;
        }

        // try all possible moves from current cell
        int dx[] = { -1, 0, 1, 0 };
        int dy[] = { 0, 1, 0, -1 };
        for(int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if(valid(x1, y1) && visited[x1][y1] == 0 && maze[x1][y1] != -1) {
                visited[x1][y1] = 1;
                queue[++rear][0] = x1;
                queue[rear][1] = y1;
            }
        }
    }

    // destination not possible
    return 0;
}

void findPath(int maze[ROW][COL], int sx, int sy, int dx, int dy) {
    // create visited array and mark all cells as unvisited
    int visited[ROW][COL] = { 0 };

    // perform BFS on maze to reach destination if possible
    if(bfs(maze, visited, sx, sy) == 0) {
        printf("Destination not possible\n");
        return;
    }

    // trace the path from destination to source
    int curx = dx, cury = dy;
    while(curx != sx || cury != sy) {
        maze[curx][cury] = -1;

        int dx[] = { -1, 0, 1, 0 };
        int dy[] = { 0, 1, 0, -1 };

        for(int i = 0; i < 4; i++) {
            int x1 = curx + dx[i];
            int y1 = cury + dy[i];

            if(valid(x1, y1) && maze[x1][y1] == -1 && !visited[x1][y1]) {
                curx = x1;
                cury = y1;
                break;
            }
        }
    }
    maze[sx][sy] = -1;

    // print final maze with path
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            if(maze[i][j] == -1) {
                printf("-> ");
            } else if(maze[i][j] == 1) {
                printf("D  ");
            } else {
                printf("%d  ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[ROW][COL] = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    printf("Maze:\n");
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%d  ", maze[i][j]);
        }
        printf("\n");
    }

    // find the path from (0,0) to (3,3)
    printf("\nPath:\n");
    findPath(maze, 0, 0, 3, 3);

    return 0;
}