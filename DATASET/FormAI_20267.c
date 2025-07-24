//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROWS 15
#define COLS 15

// function to print out the maze
void print_maze(int maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// recursive function to generate the maze
void generate_maze(int maze[][COLS], int x, int y) {
    // set the current cell as visited
    maze[x][y] = 1;

    // create an array of neighboring cells and shuffle it
    int neighbors[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    for (int i = 0; i < 4; i++) {
        int j = rand() % (4 - i);
        int neighbor_x = x + neighbors[j][0];
        int neighbor_y = y + neighbors[j][1];
        neighbors[j][0] = neighbors[3 - i][0];
        neighbors[j][1] = neighbors[3 - i][1];

        // if the neighbor is inside the maze and unvisited
        if (neighbor_x >= 0 && neighbor_x < ROWS && neighbor_y >= 0 && neighbor_y < COLS &&
            maze[neighbor_x][neighbor_y] == 0) {
            // remove the wall between the current cell and the neighbor
            maze[x + neighbors[j][0] / 2][y + neighbors[j][1] / 2] = 0;
            // move to the neighbor cell and continue recursively
            generate_maze(maze, neighbor_x, neighbor_y);
        }
    }
}

int main() {
    int maze[ROWS][COLS] = {0};
    srand(time(NULL));
    generate_maze(maze, 0, 0);
    print_maze(maze);
    return 0;
}