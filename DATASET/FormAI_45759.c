//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
};

int distance[ROWS][COLS];
bool visited[ROWS][COLS];

void initialize() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            distance[i][j] = -1;
            visited[i][j] = false;
        }
    }
    distance[1][1] = 0;
}

void update_distance(int x, int y, int dx, int dy) {
    if (dx < 0 || dx >= ROWS || dy < 0 || dy >= COLS) {
        return;
    }
    if (visited[dx][dy] || maze[dx][dy] == 1) {
        return;
    }
    if (distance[dx][dy] == -1 || distance[x][y] + 1 < distance[dx][dy]) {
        distance[dx][dy] = distance[x][y] + 1;
    }
}

void update_neighbors(int x, int y) {
    update_distance(x, y, x, y+1);
    update_distance(x, y, x, y-1);
    update_distance(x, y, x+1, y);
    update_distance(x, y, x-1, y);
}

void find_shortest_path() {
    for (int i = 0; i < ROWS*COLS; i++) {
        int x = -1, y = -1, min_distance = -1;
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                if (!visited[j][k] && distance[j][k] != -1) {
                    if (min_distance == -1 || distance[j][k] < min_distance) {
                        min_distance = distance[j][k];
                        x = j;
                        y = k;
                    }
                }
            }
        }
        if (x == -1 || y == -1) {
            break;
        }
        visited[x][y] = true;
        update_neighbors(x, y);
    }
}

void print_shortest_path() {
    int x = ROWS-2, y = COLS-2;
    while (x != 1 || y != 1) {
        printf("(%d,%d)\n", x, y);
        int min_distance = distance[x][y];
        if (distance[x+1][y] != -1 && distance[x+1][y] < min_distance) {
            x++;
        } else if (distance[x][y+1] != -1 && distance[x][y+1] < min_distance) {
            y++;
        } else if (distance[x-1][y] != -1 && distance[x-1][y] < min_distance) {
            x--;
        } else if (distance[x][y-1] != -1 && distance[x][y-1] < min_distance) {
            y--;
        } else {
            break;
        }
    }
    printf("(1,1)\n");
}

int main() {
    initialize();
    find_shortest_path();
    print_shortest_path();
    return 0;
}