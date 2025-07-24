//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ROWS 30
#define MAX_COLS 30
#define WALL '+'
#define PATH '-'
#define START 'S'
#define END 'E'

typedef struct Maze maze_t;

struct Maze {
    char cell[MAX_ROWS][MAX_COLS];
    int rows;
    int cols;
    int start_x;
    int start_y;
    int end_x;
    int end_y;
};

/* Function prototypes */
maze_t generate_maze(int rows, int cols);
void print_maze(maze_t maze);

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    maze_t maze = generate_maze(15, 15); // Generate a 15x15 maze

    print_maze(maze); // Print the maze

    return 0;
}

/**
 * Function to generate a maze.
 *
 * @param rows Number of rows in the maze.
 * @param cols Number of columns in the maze.
 * @return A maze_t struct representing the generated maze.
 */
maze_t generate_maze(int rows, int cols) {
    maze_t maze;

    // Initialize the cells of the maze to WALL
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze.cell[i][j] = WALL;
        }
    }

    // Choose a random starting point on the left or top edge of the maze
    if (rand() % 2 == 0) {
        maze.start_x = rand() % rows;
        maze.start_y = 0;
    } else {
        maze.start_x = 0;
        maze.start_y = rand() % cols;
    }

    // Choose a random ending point on the right or bottom edge of the maze
    if (rand() % 2 == 0) {
        maze.end_x = rand() % rows;
        maze.end_y = cols - 1;
    } else {
        maze.end_x = rows - 1;
        maze.end_y = rand() % cols;
    }

    // Fill the path from the start to the end of the maze
    int current_x = maze.start_x;
    int current_y = maze.start_y;
    maze.cell[current_x][current_y] = START;

    while (current_x != maze.end_x || current_y != maze.end_y) {
        // Choose a random direction to move in
        int direction = rand() % 4;

        switch (direction) {
            case 0: // Move up
                if (current_x > 0 && maze.cell[current_x - 1][current_y] == WALL) {
                    current_x--;
                    maze.cell[current_x][current_y] = PATH;
                }
                break;
            case 1: // Move down
                if (current_x < rows - 1 && maze.cell[current_x + 1][current_y] == WALL) {
                    current_x++;
                    maze.cell[current_x][current_y] = PATH;
                }
                break;
            case 2: // Move left
                if (current_y > 0 && maze.cell[current_x][current_y - 1] == WALL) {
                    current_y--;
                    maze.cell[current_x][current_y] = PATH;
                }
                break;
            case 3: // Move right
                if (current_y < cols - 1 && maze.cell[current_x][current_y + 1] == WALL) {
                    current_y++;
                    maze.cell[current_x][current_y] = PATH;
                }
                break;
        }
    }

    maze.cell[maze.end_x][maze.end_y] = END;

    maze.rows = rows;
    maze.cols = cols;

    return maze;
}

/**
 * Function to print a maze.
 *
 * @param maze The maze to print.
 */
void print_maze(maze_t maze) {
    for (int i = 0; i < maze.rows; i++) {
        for (int j = 0; j < maze.cols; j++) {
            putchar(maze.cell[i][j]);
            putchar(' ');
        }
        putchar('\n');
    }
}