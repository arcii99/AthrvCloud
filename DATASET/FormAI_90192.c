//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

// Structure for the coordinates of a single cell
struct cell {
    int x, y;
};

// A grid to represent the maze
int grid[ROWS][COLS];

// Add or remove walls between two cells
void make_path(struct cell current, struct cell next) {
    int x = next.x - current.x;
    int y = next.y - current.y;

    // Add/remove vertical walls
    if (x == 1) {
        grid[current.x+1][current.y] = 0;
    } else if (x == -1) {
        grid[current.x-1][current.y] = 0;
    }

    // Add/remove horizontal walls
    if (y == 1) {
        grid[current.x][current.y+1] = 0;
    } else if (y == -1) {
        grid[current.x][current.y-1] = 0;
    }
}

// A recursive function to generate the maze using DFS
void generate_maze(struct cell current) {
    // Set the current cell as visited
    grid[current.x][current.y] = 1;

    // Get the neighbors of the current cell
    struct cell neighbors[4] = {
        {current.x+1, current.y},
        {current.x-1, current.y},
        {current.x, current.y+1},
        {current.x, current.y-1}
    };

    // Shuffle the neighbors randomly
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        struct cell temp = neighbors[i];
        neighbors[i] = neighbors[j];
        neighbors[j] = temp;
    }

    // Visit each neighbor recursively
    for (int i = 0; i < 4; i++) {
        struct cell next = neighbors[i];

        // Check if the neighbor is a valid cell
        if (next.x >= 0 && next.x < ROWS && next.y >= 0 && next.y < COLS && grid[next.x][next.y] == 0) {
            // Add/remove walls between the current cell and the next cell
            make_path(current, next);

            // Recursive call to visit the next cell
            generate_maze(next);
        }
    }
}

// Print the maze to the console
void print_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("█"); // Wall
            } else {
                printf(" "); // Path
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Set all cells as walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 1;
        }
    }

    // Generate the maze starting from the top-left corner
    struct cell start = {0, 0};
    generate_maze(start);

    // Print the maze
    print_maze();

    return 0;
}