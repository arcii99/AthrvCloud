//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: medieval
#include <stdio.h>

#define ROW 10
#define COL 10

typedef struct {
    int x, y;
} Point;

char grid[ROW][COL] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
};

Point start = {1, 1}, end = {8, 8};

Point path[ROW*COL];
int pathlen = 0;

void print_grid(char g[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c", g[i][j]);
        }
        printf("\n");
    }
}

int is_valid(Point p) {
    if (p.x < 0 || p.x >= ROW) return 0;
    if (p.y < 0 || p.y >= COL) return 0;
    if (grid[p.x][p.y] == '#') return 0;
    return 1;
}

int visited[ROW][COL] = {0};

int dfs(Point current) {
    if (!is_valid(current) || visited[current.x][current.y]) return 0;
    if (current.x == end.x && current.y == end.y) {
        path[pathlen++] = current;
        return 1;
    }
    visited[current.x][current.y] = 1;
    if (dfs((Point){current.x-1, current.y})) {
        path[pathlen++] = current;
        return 1;
    }
    if (dfs((Point){current.x+1, current.y})) {
        path[pathlen++] = current;
        return 1;
    }
    if (dfs((Point){current.x, current.y-1})) {
        path[pathlen++] = current;
        return 1;
    }
    if (dfs((Point){current.x, current.y+1})) {
        path[pathlen++] = current;
        return 1;
    }
    return 0;
}

void mark_path(char g[ROW][COL], Point p) {
    g[p.x][p.y] = '*';
}

void print_path() {
    printf("Path Found: \n");
    for (int i = pathlen-1; i >= 0; i--) {
        mark_path(grid, path[i]);
    }
    print_grid(grid);
}

int main() {
    printf("Medieval Pathfinding Algorithm!\n");
    printf("Starting point: (%d, %d)\n", start.x, start.y);
    printf("Ending point: (%d, %d)\n\n", end.x, end.y);
    printf("Maze Representation:\n");
    print_grid(grid);
    dfs(start);
    if (pathlen > 0) {
        print_path();
    } else {
        printf("No path found.\n");
    }
    return 0;
}