//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maze dimensions
#define ROWS 10
#define COLS 10

// Maze cells
#define EMPTY 0
#define WALL 1
#define PATH 2

// Directions
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

// Stack size
#define STACK_SIZE 100

// Maze
int maze[ROWS][COLS];

// Stack for backtracking
int stack[STACK_SIZE];
int top = -1;

void push(int value) {
    if (top < STACK_SIZE - 1) {
        stack[++top] = value;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

int get_random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_maze() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize maze to all walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }

    // Starting cell
    int row = get_random(0, ROWS-1);
    int col = get_random(0, COLS-1);
    maze[row][col] = PATH;

    // Create path through maze
    while (1) {
        // Check for neighboring cells that are walls
        int neighbors[4] = {-1, -1, -1, -1};
        int count = 0;

        if (row > 0 && maze[row-1][col] == WALL) {
            neighbors[count++] = UP;
        }
        if (row < ROWS-1 && maze[row+1][col] == WALL) {
            neighbors[count++] = DOWN;
        }
        if (col > 0 && maze[row][col-1] == WALL) {
            neighbors[count++] = LEFT;
        }
        if (col < COLS-1 && maze[row][col+1] == WALL) {
            neighbors[count++] = RIGHT;
        }

        if (count == 0) {
            // No neighboring walls, backtrack
            int direction = pop();
            if (direction == -1) {
                // All done, path through maze created
                break;
            }

            switch (direction) {
                case UP:
                    row--;
                    break;
                case DOWN:
                    row++;
                    break;
                case LEFT:
                    col--;
                    break;
                case RIGHT:
                    col++;
                    break;
            }
        } else {
            // Randomly choose a neighboring wall to break down
            int direction = neighbors[get_random(0, count-1)];

            switch (direction) {
                case UP:
                    maze[--row][col] = PATH;
                    maze[row+1][col] = PATH;
                    break;
                case DOWN:
                    maze[++row][col] = PATH;
                    maze[row-1][col] = PATH;
                    break;
                case LEFT:
                    maze[row][--col] = PATH;
                    maze[row][col+1] = PATH;
                    break;
                case RIGHT:
                    maze[row][++col] = PATH;
                    maze[row][col-1] = PATH;
                    break;
            }

            // Push current cell onto stack for backtracking
            push(direction);
        }
    }
}

void print_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == WALL) {
                printf("#");
            } else if (maze[i][j] == PATH) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    generate_maze();
    print_maze();

    return 0;
}