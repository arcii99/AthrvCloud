//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 20

// Maze cell structure
typedef struct {
    int row;
    int col;
    int top_wall;
    int bottom_wall;
    int left_wall;
    int right_wall;
    int visited;
} Cell;

// Function declarations
void init_maze(Cell maze[][COLS]);
void print_maze(Cell maze[][COLS]);
void generate_maze(Cell maze[][COLS], int row, int col);

int main() {
    Cell maze[ROWS][COLS];
    srand(time(NULL));

    init_maze(maze);
    generate_maze(maze, 0, 0);
    print_maze(maze);

    return 0;
}

// Initialize the maze with walls and cells
void init_maze(Cell maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j].row = i;
            maze[i][j].col = j;
            maze[i][j].top_wall = 1;
            maze[i][j].bottom_wall = 1;
            maze[i][j].left_wall = 1;
            maze[i][j].right_wall = 1;
            maze[i][j].visited = 0;
        }
    }
}

// Print the maze
void print_maze(Cell maze[][COLS]) {
    // Print top wall
    printf("+");
    for (int i = 0; i < COLS; i++) {
        printf("---+");
    }
    printf("\n");

    // Print cells and walls
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j].visited == 1) {
                printf("   ");
            } else {
                printf("XXX");
            }
            if (maze[i][j].right_wall == 1) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");

        // Print bottom wall
        printf("+");
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j].bottom_wall == 1) {
                printf("---+");
            } else {
                printf("   +");
            }
        }
        printf("\n");
    }
}

// Generate the maze using depth-first search
void generate_maze(Cell maze[][COLS], int row, int col) {
    maze[row][col].visited = 1;

    // Create a random order for neighbors to visit
    int neighbors[4] = { 0, 1, 2, 3 };
    for (int i = 0; i < 4; i++) {
        int temp = neighbors[i];
        int randomIndex = rand() % 4;
        neighbors[i] = neighbors[randomIndex];
        neighbors[randomIndex] = temp;
    }

    // Visit neighboring cells
    for (int i = 0; i < 4; i++) {
        switch (neighbors[i]) {
            case 0: // Top neighbor
                if (row > 0 && maze[row-1][col].visited == 0) {
                    maze[row][col].top_wall = 0;
                    maze[row-1][col].bottom_wall = 0;
                    generate_maze(maze, row-1, col);
                }
                break;
            case 1: // Bottom neighbor
                if (row < ROWS-1 && maze[row+1][col].visited == 0) {
                    maze[row][col].bottom_wall = 0;
                    maze[row+1][col].top_wall = 0;
                    generate_maze(maze, row+1, col);
                }
                break;
            case 2: // Left neighbor
                if (col > 0 && maze[row][col-1].visited == 0) {
                    maze[row][col].left_wall = 0;
                    maze[row][col-1].right_wall = 0;
                    generate_maze(maze, row, col-1);
                }
                break;
            case 3: // Right neighbor
                if (col < COLS-1 && maze[row][col+1].visited == 0) {
                    maze[row][col].right_wall = 0;
                    maze[row][col+1].left_wall = 0;
                    generate_maze(maze, row, col+1);
                }
                break;
        }
    }
}