//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the size of the maze
#define ROW_SIZE 6
#define COL_SIZE 6

// Define constants for maze cells
#define WALL 0
#define PATH 1
#define VISITED 2

// Define the maze
int maze[ROW_SIZE][COL_SIZE] = {
    {WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, PATH, PATH, WALL, PATH, WALL},
    {WALL, PATH, WALL, WALL, PATH, WALL},
    {WALL, PATH, PATH, PATH, PATH, WALL},
    {WALL, WALL, WALL, WALL, PATH, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL}
};

// Define a coordinate data structure
typedef struct {
    int row;
    int col;
} Coord;

// Define a stack data structure for saving the path
typedef struct {
    Coord data[ROW_SIZE*COL_SIZE];
    int top;
} Stack;

// Initialize an empty stack
void init_stack(Stack* s) {
    s->top = -1;
}

// Check if the stack is empty
bool is_empty(Stack* s) {
    return s->top == -1;
}

// Push a coordinate onto the stack
void push(Stack* s, Coord c) {
    s->data[++s->top] = c;
}

// Pop a coordinate off the stack
Coord pop(Stack* s) {
    return s->data[s->top--];
}

// Helper function to check if a coordinate is valid
bool is_valid(int row, int col) {
    return row >= 0 && row < ROW_SIZE && col >= 0 && col < COL_SIZE && maze[row][col] != WALL;
}

// Find a path through the maze using a depth-first search
bool find_path(int row, int col, Stack* path) {
    Coord start = {row, col};
    push(path, start);
    maze[row][col] = VISITED;

    while (!is_empty(path)) {
        Coord current = pop(path);

        int r = current.row;
        int c = current.col;

        if (r == ROW_SIZE-1 && c == COL_SIZE-1) {
            return true; // Found the exit!
        }

        // Check all possible moves from the current position
        if (is_valid(r+1, c)) { // Down
            Coord next = {r+1, c};
            push(path, next);
            maze[r+1][c] = VISITED;
        }
        if (is_valid(r, c+1)) { // Right
            Coord next = {r, c+1};
            push(path, next);
            maze[r][c+1] = VISITED;
        }
        if (is_valid(r-1, c)) { // Up
            Coord next = {r-1, c};
            push(path, next);
            maze[r-1][c] = VISITED;
        }
        if (is_valid(r, c-1)) { // Left
            Coord next = {r, c-1};
            push(path, next);
            maze[r][c-1] = VISITED;
        }
    }

    return false; // No path found
}

// Print the maze with the given path
void print_maze(Stack* path) {
    for (int row = 0; row < ROW_SIZE; row++) {
        for (int col = 0; col < COL_SIZE; col++) {
            if (maze[row][col] == WALL) {
                printf("X ");
            } else if (maze[row][col] == VISITED) {
                printf(". ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("Path:\n");
    for (int i = 0; i <= path->top; i++) {
        printf("(%d,%d) ", path->data[i].row, path->data[i].col);
    }
    printf("\n");
}

int main() {
    Stack path;
    init_stack(&path);

    // Find a path through the maze starting at (1,1)
    if (find_path(1, 1, &path)) {
        printf("Path found!\n");
        print_maze(&path);
    } else {
        printf("No path found :(\n");
        print_maze(&path);
    }

    return 0;
}