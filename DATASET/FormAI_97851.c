//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 15

typedef struct Point {
    int x;
    int y;
} Point;

bool isValid(int row, int col, int visited[][COL], int grid[][COL]) {
    if (row < 0 || col < 0 || row >= ROW || col >= COL || visited[row][col] ||
        !grid[row][col]) {
        return false;
    }
    return true;
}

void dfs(int row, int col, int visited[][COL], int grid[][COL], Point parent[][COL],
         Point src, Point dst) {
    if (!isValid(row, col, visited, grid)) {
        return;
    }

    visited[row][col] = 1;
    Point cur = {row, col};
    parent[row][col] = src;

    if (row == dst.x && col == dst.y) {
        return;
    }

    dfs(row-1, col, visited, grid, parent, cur, dst); // go up
    dfs(row, col+1, visited, grid, parent, cur, dst); // go right
    dfs(row+1, col, visited, grid, parent, cur, dst); // go down
    dfs(row, col-1, visited, grid, parent, cur, dst); // go left
}

void printPath(Point cur, Point parent[][COL]) {
    if (cur.x == -1 && cur.y == -1) {
        return;
    }

    printPath(parent[cur.x][cur.y], parent);
    printf("(%d,%d) ", cur.x, cur.y);
}

void findPath(int grid[][COL], Point src, Point dst) {
    int visited[ROW][COL] = {0};
    Point parent[ROW][COL] = {{-1, -1}};

    dfs(src.x, src.y, visited, grid, parent, src, dst);

    if (visited[dst.x][dst.y]) {
        printf("The path from (%d, %d) to (%d, %d) follows: ", src.x, src.y, dst.x, dst.y);
        printPath(dst, parent);
        printf("\n");
    } else {
        printf("There is no path from (%d, %d) to (%d, %d).\n", src.x, src.y, dst.x, dst.y);
    }
}

int main() {
    int grid[ROW][COL] = {
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1}
    };

    Point src = {0, 0};
    Point dst = {9, 14};

    findPath(grid, src, dst);

    return 0;
}