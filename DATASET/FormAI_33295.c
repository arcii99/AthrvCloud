//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROW 6
#define COL 7

int top = -1;
int stack[ROW*COL];

void push (int val){
    top++;
    stack[top] = val;
}

int pop() {
    int val = stack[top];
    top--;
    return val;
}

bool is_empty() {
    if (top == -1)
        return true;
    else
        return false;
}

bool is_in_bounds (int x, int y) {
    if (x >= 0 && x < ROW && y >= 0 && y < COL)
        return true;
    else
        return false;
}

bool is_valid(int grid[ROW][COL], int visited[ROW][COL], int x, int y) {
    if (grid[x][y] == 1 && !visited[x][y])
        return true;
    else
        return false;
}

void print_path(int x, int y, int parent[ROW][COL]) {
    int i;
    int curr = ROW * x + y;
    while (curr != -1) {
        int r = curr / ROW;
        int c = curr % ROW;
        printf("(%d,%d)\n", r, c);
        curr = parent[r][c];
    }
}

void astar(int grid[ROW][COL], int sx, int sy, int dx, int dy) {
    int x, y, i, cost;
    int visited[ROW][COL];
    int dist[ROW][COL];
    int parent[ROW][COL];
    for (x = 0; x < ROW; x++) {
        for (y = 0; y < COL; y++) {
            visited[x][y] = false;
            dist[x][y] = ROW*COL;
            parent[x][y] = -1;
        }
    }
    visited[sx][sy] = true;
    dist[sx][sy] = 0;

    push(sx*ROW + sy);
    while (!is_empty()) {
        int curr = pop();
        int r = curr / ROW;
        int c = curr % ROW;
        if (r == dx && c == dy) {
            printf("Path found!\n");
            print_path(dx, dy, parent);
            return;
        }
        for (i = 0; i < 4; i++) {
            int rx = r + (i==0) - (i==1);
            int cy = c + (i==2) - (i==3);
            if (is_in_bounds(rx, cy) && is_valid(grid, visited, rx, cy)) {
                cost = dist[r][c] + abs(rx-r) + abs(cy-c);
                if (cost < dist[rx][cy]) {
                    visited[rx][cy] = true;
                    parent[rx][cy] = r*ROW+c;
                    dist[rx][cy] = cost;
                    push(rx*ROW + cy);
                }
            }
        }
    }
    printf("Path not found.\n");
}

int main() {
    int grid[ROW][COL] = {
        {1,1,0,0,1,0,0},
        {1,1,1,0,1,1,0},
        {0,1,1,1,0,1,0},
        {0,0,1,1,0,1,1},
        {0,0,1,0,1,1,1},
        {1,1,1,1,1,0,1}
    };
    astar(grid, 0, 0, 3, 5);
    return 0;
}