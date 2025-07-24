//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 20

int maze[HEIGHT][WIDTH]; // stores the maze map
int visited[HEIGHT][WIDTH]; // stores information about visited nodes

void init_maze() {
    // initialize the maze with all walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;
        }
    }
}

void print_maze() {
    // print the maze
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 1) {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int is_wall(int x, int y) {
    // check if the given cell is a wall
    if (x < 0 || y < 0 || x >= HEIGHT || y >= WIDTH) {
        return 1; // out of bounds
    }
    return maze[x][y];
}

int is_visited(int x, int y) {
    // check if the given cell has been visited
    if (x < 0 || y < 0 || x >= HEIGHT || y >= WIDTH) {
        return 0; // out of bounds
    }
    return visited[x][y];
}

int count_neighbors(int x, int y) {
    // count the number of visited neighbors of the given cell
    int count = 0;
    if (is_visited(x - 1, y)) count++;
    if (is_visited(x + 1, y)) count++;
    if (is_visited(x, y - 1)) count++;
    if (is_visited(x, y + 1)) count++;
    return count;
}

void generate_maze(int x, int y) {
    // generate the maze recursively
    visited[x][y] = 1;
    
    // choose a random direction
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++) {
        int random_index = rand() % 4;
        int dx = directions[random_index][0];
        int dy = directions[random_index][1];
        
        // check if the neighbor is visited
        if (!is_visited(x + dx, y + dy)) {
            // check if it has less than 2 visited neighbors
            if (count_neighbors(x + dx, y + dy) < 2) {
                // break the wall between the current cell and the neighbor
                maze[x + dx][y + dy] = 0;
                generate_maze(x + dx, y + dy);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    init_maze();
    generate_maze(0, 0);
    print_maze();
    return 0;
}