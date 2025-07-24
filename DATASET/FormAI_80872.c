//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

struct cell {
    int row;
    int col;
    int visited;
    int walls[4];
};

enum Walls {TOP, RIGHT, BOTTOM, LEFT};

void init_maze(struct cell maze[ROWS][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j].row = i;
            maze[i][j].col = j;
            maze[i][j].visited = 0;

            maze[i][j].walls[TOP] = 1;
            maze[i][j].walls[RIGHT] = 1;
            maze[i][j].walls[BOTTOM] = 1;
            maze[i][j].walls[LEFT] = 1;
        }
    }
}

void print_maze(struct cell maze[ROWS][COLS]) {
    int i, j;

    // Print top border
    for (i = 0; i < COLS; i++) {
        printf("+-");
    }
    printf("+\n");

    // Print rows
    for (i = 0; i < ROWS; i++) {
        printf("| ");
        for (j = 0; j < COLS; j++) {
            if (maze[i][j].walls[TOP]) {
                printf("- ");
            } else {
                printf("  ");
            }
            if (maze[i][j].walls[RIGHT]) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
        // Print bottom border
        for (j = 0; j < COLS; j++) {
            if (maze[i][j].walls[BOTTOM]) {
                printf("+-");
            } else {
                printf("+ ");
            }
        }
        printf("+\n");
    }
}

int neighbor_cells(struct cell maze[ROWS][COLS], struct cell *current, struct cell *neighbors[]) {
    int count = 0;

    int row = current->row;
    int col = current->col;

    // Check top neighbor
    if (row > 0) {
        if (!maze[row-1][col].visited) {
            neighbors[count++] = &maze[row-1][col];
        }
    }

    // Check right neighbor
    if (col < COLS-1) {
        if (!maze[row][col+1].visited) {
            neighbors[count++] = &maze[row][col+1];
        }
    }

    // Check bottom neighbor
    if (row < ROWS-1) {
        if (!maze[row+1][col].visited) {
            neighbors[count++] = &maze[row+1][col];
        }
    }

    // Check left neighbor
    if (col > 0) {
        if (!maze[row][col-1].visited) {
            neighbors[count++] = &maze[row][col-1];
        }
    }

    return count;
}

void remove_wall(struct cell *current, struct cell *next) {
    int row_diff = next->row - current->row;
    int col_diff = next->col - current->col;

    if (row_diff == 1) { // Next cell is below current
        current->walls[BOTTOM] = 0;
        next->walls[TOP] = 0;
    } else if (row_diff == -1) { // Next cell is above current
        current->walls[TOP] = 0;
        next->walls[BOTTOM] = 0;
    } else if (col_diff == 1) { // Next cell is right of current
        current->walls[RIGHT] = 0;
        next->walls[LEFT] = 0;
    } else if (col_diff == -1) { // Next cell is left of current
        current->walls[LEFT] = 0;
        next->walls[RIGHT] = 0;
    }
}

void generate_maze(struct cell maze[ROWS][COLS]) {
    struct cell *stack[ROWS*COLS];
    int top = 0;

    struct cell *current = &maze[0][0];
    current->visited = 1;

    do {
        struct cell *neighbors[4];
        int num_neighbors = neighbor_cells(maze, current, neighbors);

        if (num_neighbors > 0) {
            // Choose random neighbor
            int rand_index = rand() % num_neighbors;
            struct cell *next = neighbors[rand_index];

            // Remove wall between current and next cell
            remove_wall(current, next);

            // Push current cell onto stack
            stack[top++] = current;

            // Update current and mark as visited
            current = next;
            current->visited = 1;
        } else {
            // Pop previous cell from stack
            current = stack[--top];
        }
    } while (top > 0);
}

int main() {
    struct cell maze[ROWS][COLS];
    init_maze(maze);

    srand(time(NULL));
    generate_maze(maze);

    print_maze(maze);

    return 0;
}