//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define ROW 5
#define COL 5
#define DIR 4
#define WALL 255

typedef struct {
    int x, y;
} Point;

typedef struct {
    int g, h, f;
    Point parent;
} Node;

void printPath(Point path[], int count) {
    for (int i = count - 1; i >= 0; i--) {
        printf("(%d, %d)", path[i].x, path[i].y);
        if (i > 0) printf(" -> ");
    }
}

bool isValid(Point cell, unsigned char grid[][COL]) {
    return (cell.x >= 0) && (cell.x < ROW) &&
           (cell.y >= 0) && (cell.y < COL) &&
           (grid[cell.x][cell.y] != WALL);
}

bool isDestination(Point cell, Point dest) {
    return (cell.x == dest.x) && (cell.y == dest.y);
}

int heuristic(Point cell, Point dest) {
    return abs(cell.x - dest.x) + abs(cell.y - dest.y);
}

void aStarSearch(unsigned char grid[][COL], Point src, Point dest) {
    Point directions[DIR] = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    bool closed[ROW][COL];
    Node nodes[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            nodes[i][j].g = INT_MAX;
            nodes[i][j].h = INT_MAX;
            nodes[i][j].f = INT_MAX;
            nodes[i][j].parent = (Point) {-1,-1};
            closed[i][j] = false;
        }
    }

    int x = src.x, y = src.y;
    nodes[x][y].g = 0;
    nodes[x][y].h = heuristic(src, dest);
    nodes[x][y].f = nodes[x][y].h;

    while (!isDestination((Point) {x, y}, dest)) {
        int minF = INT_MAX;
        Point current;

        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (!closed[i][j] && nodes[i][j].f < minF) {
                    minF = nodes[i][j].f;
                    current = (Point) {i, j};
                }
            }
        }

        closed[current.x][current.y] = true;

        for (int i = 0; i < DIR; i++) {
            Point neighbor = {current.x + directions[i].x, current.y + directions[i].y};
            if (isValid(neighbor, grid)) {
                int tentativeGScore = nodes[current.x][current.y].g + 1;
                if (tentativeGScore < nodes[neighbor.x][neighbor.y].g) {
                    nodes[neighbor.x][neighbor.y].parent = current;
                    nodes[neighbor.x][neighbor.y].g = tentativeGScore;
                    nodes[neighbor.x][neighbor.y].h = heuristic(neighbor, dest);
                    nodes[neighbor.x][neighbor.y].f = nodes[neighbor.x][neighbor.y].g + nodes[neighbor.x][neighbor.y].h;
                }
            }
        }
    }

    Point path[ROW * COL];
    int count = 0;
    while (!(x == src.x && y == src.y)) {
        path[count] = (Point) {x, y};
        Point temp = nodes[x][y].parent;
        x = temp.x;
        y = temp.y;
        count++;
    }
    path[count] = (Point) {x, y};

    printf("Path found: ");
    printPath(path, count+1);
}

int main() {
    Point src = {2, 2}, dest = {4, 4};

    // set up grid
    unsigned char grid[ROW][COL] = {
        {0, 0, WALL, 0, 0},
        {0, WALL, WALL, 0, 0},
        {0, 0, WALL, 0, 0},
        {0, 0, WALL, 0, 0},
        {0, 0, 0, 0, 0}
    };

    aStarSearch(grid, src, dest);

    return 0;
}