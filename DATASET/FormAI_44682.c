//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int maze[HEIGHT][WIDTH] = {0};

int visited[HEIGHT][WIDTH] = {0};

int is_valid(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && maze[y][x] == 0;
}

int has_unvisited_neighbours(int x, int y) {
    return (is_valid(x - 1, y) && !visited[y][x - 1]) || 
           (is_valid(x + 1, y) && !visited[y][x + 1]) ||
           (is_valid(x, y - 1) && !visited[y - 1][x]) ||
           (is_valid(x, y + 1) && !visited[y + 1][x]);
}

void carve_maze(int x, int y) {
    visited[y][x] = 1;

    int neighbours[4] = {-1, -1, -1, -1};
    int num_neighbours = 0;

    if (is_valid(x - 1, y) && !visited[y][x - 1]) neighbours[num_neighbours++] = 0;
    if (is_valid(x + 1, y) && !visited[y][x + 1]) neighbours[num_neighbours++] = 1;
    if (is_valid(x, y - 1) && !visited[y - 1][x]) neighbours[num_neighbours++] = 2;
    if (is_valid(x, y + 1) && !visited[y + 1][x]) neighbours[num_neighbours++] = 3;

    while (num_neighbours > 0) {
        int r = rand() % num_neighbours;
        int dir = neighbours[r];
        neighbours[r] = neighbours[--num_neighbours];

        int dx = 0, dy = 0;
        if (dir == 0) { dx = -1; }
        else if (dir == 1) { dx = 1; }
        else if (dir == 2) { dy = -1; }
        else if (dir == 3) { dy = 1; }

        maze[y + dy][x + dx] = 1;
        carve_maze(x + dx, y + dy);
    }
}

int main() {
    srand(time(NULL));

    // carve maze starting from center point
    int cx = WIDTH/2, cy = HEIGHT/2;
    carve_maze(cx, cy);

    // print out the maze
    printf(" ");
    for (int x = 0; x < WIDTH*2 - 1; x++) {
        printf("_");
    }
    printf("\n");

    for (int y = 0; y < HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < WIDTH; x++) {
            if (maze[y][x] == 0) {
                printf("_|");
            } else {
                printf(" |");
            }
        }
        printf("\n");
    }

    return 0;
}