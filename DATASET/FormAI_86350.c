//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: immersive
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAZE_WIDTH 30
#define MAZE_HEIGHT 20

/* Function to generate a random number within a range */
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/* Struct to hold the maze cell information */
typedef struct cell {
    bool visited;
    bool top_wall;
    bool right_wall;
    bool bottom_wall;
    bool left_wall;
} Cell;

/* Function to initialize the maze */
void init_maze(Cell maze[][MAZE_WIDTH]) {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze[i][j].visited = false;
            maze[i][j].top_wall = true;
            maze[i][j].right_wall = true;
            maze[i][j].bottom_wall = true;
            maze[i][j].left_wall = true;
        }
    }
}

/* Function to print the maze */
void print_maze(Cell maze[][MAZE_WIDTH]) {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            if (maze[i][j].top_wall) {
                printf("+--");
            } else {
                printf("+  ");
            }
        }
        printf("+\n");
        for (int j = 0; j < MAZE_WIDTH; j++) {
            if (maze[i][j].left_wall) {
                printf("|  ");
            } else {
                printf("   ");
            }
        }
        printf("|\n");
    }
    for (int j = 0; j < MAZE_WIDTH; j++) {
        printf("+--");
    }
    printf("+\n");
}

/* Function to generate the maze using depth first search algorithm */
void generate_maze(Cell maze[][MAZE_WIDTH], int row, int col) {
    maze[row][col].visited = true;
    while (true) {
        /* Check unvisited cells */
        bool unvisited_top = row > 0 && !maze[row-1][col].visited;
        bool unvisited_right = col < MAZE_WIDTH - 1 && !maze[row][col+1].visited;
        bool unvisited_bottom = row < MAZE_HEIGHT - 1 && !maze[row+1][col].visited;
        bool unvisited_left = col > 0 && !maze[row][col-1].visited;
        if (!unvisited_top && !unvisited_right && !unvisited_bottom && !unvisited_left) {
            /* Return if all surrounding cells have been visited */
            return;
        }
        /* Choose a random unvisited cell to move to */
        int random_direction = rand_range(0, 3);
        if (random_direction == 0 && unvisited_top) {
            maze[row][col].top_wall = false;
            maze[row-1][col].bottom_wall = false;
            generate_maze(maze, row-1, col);
        } else if (random_direction == 1 && unvisited_right) {
            maze[row][col].right_wall = false;
            maze[row][col+1].left_wall = false;
            generate_maze(maze, row, col+1);
        } else if (random_direction == 2 && unvisited_bottom) {
            maze[row][col].bottom_wall = false;
            maze[row+1][col].top_wall = false;
            generate_maze(maze, row+1, col);
        } else if (random_direction == 3 && unvisited_left) {
            maze[row][col].left_wall = false;
            maze[row][col-1].right_wall = false;
            generate_maze(maze, row, col-1);
        }
    }
}

/* Main function */
int main() {
    /* Initialize random number generator */
    srand(time(NULL));
    /* Initialize maze */
    Cell maze[MAZE_HEIGHT][MAZE_WIDTH];
    init_maze(maze);
    /* Generate maze */
    generate_maze(maze, 0, 0);
    /* Print maze */
    print_maze(maze);
    return 0;
}