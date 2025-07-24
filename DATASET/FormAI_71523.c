//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COL 6

int maze[ROW][COL] = {
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 0},
    {1, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0}
};

int visited[ROW][COL];

// Function to check if a given cell is valid to move
int is_valid(int x, int y) {
    if (x >= 0 && y >= 0 && x < ROW && y < COL && !visited[x][y] && !maze[x][y]) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the path from source to destination
void print_path(int path[ROW][COL], int x, int y) {
    if (x == 0 && y == 0) {
        printf("(%d, %d)\n", x, y);
        return;
    }
    print_path(path, path[x][y]/COL, path[x][y]%COL);
    printf("(%d, %d)\n", x, y);
}

// Function to find the shortest path between source and destination
void find_shortest_path(int sx, int sy, int dx, int dy) {
    int queue[ROW*COL], front = 0, rear = 0;
    int path[ROW][COL], i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            visited[i][j] = 0;
            path[i][j] = -1;
        }
    }
    visited[sx][sy] = 1;
    queue[rear++] = sx*COL + sy;
    while (front != rear) {
        int curr = queue[front++];
        int x = curr/COL, y = curr%COL;
        if (x == dx && y == dy) {
            print_path(path, dx, dy);
            return;
        }
        if (is_valid(x-1, y)) {
            visited[x-1][y] = 1;
            path[x-1][y] = curr;
            queue[rear++] = (x-1)*COL + y;
        }
        if (is_valid(x+1, y)) {
            visited[x+1][y] = 1;
            path[x+1][y] = curr;
            queue[rear++] = (x+1)*COL + y;
        }
        if (is_valid(x, y-1)) {
            visited[x][y-1] = 1;
            path[x][y-1] = curr;
            queue[rear++] = x*COL + y-1;
        }
        if (is_valid(x, y+1)) {
            visited[x][y+1] = 1;
            path[x][y+1] = curr;
            queue[rear++] = x*COL + y+1;
        }
    }
    printf("No path found.\n");
}

int main() {
    find_shortest_path(0, 0, 5, 5);
    return 0;
}