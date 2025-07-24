//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int grid[20][20]; // 2D array representing the grid
int start_x, start_y, end_x, end_y; // start and end points
int visited[20][20]; // keep track of visited cells

// define the possible moves
int move_x[4] = {0, 0, -1, 1};
int move_y[4] = {-1, 1, 0, 0};

// function to print the grid
void print_grid() {
    printf("\nGrid:\n");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (grid[i][j] == 1) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// function to generate the random obstacles in the grid
void generate_obstacles() {
    int num_obstacles = 80;
    while (num_obstacles > 0) {
        int x = rand() % 20;
        int y = rand() % 20;
        if (x != start_x && y != start_y && x != end_x && y != end_y && grid[x][y] != 1) {
            grid[x][y] = 1;
            num_obstacles--;
        }
    }
}

// function to initialize the grid and the start and end points
void initialize() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            grid[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    start_x = 0;
    start_y = 0;
    end_x = 19;
    end_y = 19;
    grid[start_x][start_y] = 2;
    grid[end_x][end_y] = 3;
}

// recursive depth-first search algorithm to find the path
void dfs(int x, int y) {
    visited[x][y] = 1;
    if (x == end_x && y == end_y) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        int new_x = x + move_x[i];
        int new_y = y + move_y[i];
        if (new_x >= 0 && new_x < 20 && new_y >= 0 && new_y < 20 && grid[new_x][new_y] != 1 && visited[new_x][new_y] != 1) {
            dfs(new_x, new_y);
        }
    }
}

int main() {
    srand(time(0));
    initialize();
    generate_obstacles();
    print_grid();
    dfs(start_x, start_y);
    printf("\nPath:\n");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (visited[i][j] == 1) {
                printf("- ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}