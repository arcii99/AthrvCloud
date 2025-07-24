//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Maze structure
typedef struct maze {
    char grid[ROWS][COLS];  // maze grid
    int start_x;  // x position of start point
    int start_y;  // y position of start point
    int end_x;  // x position of end point
    int end_y;  // y position of end point
} Maze;

// Function to read maze file and initialize maze struct
void read_maze_file(char* filename, Maze* maze) {
    FILE* fp = fopen(filename, "r");
    char c;
    int row = 0;
    int col = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            row++;
            col = 0;
        } else {
            if (c == 'S') {
                maze->start_x = col;
                maze->start_y = row;
            } else if (c == 'E') {
                maze->end_x = col;
                maze->end_y = row;
            }
            maze->grid[row][col] = c;
            col++;
        }
    }

    fclose(fp);
}

// Function to print maze
void print_maze(Maze maze) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze.grid[i][j]);
        }
        printf("\n");
    }
}

// Function to find route through maze using recursive DFS algorithm
int find_route(Maze maze, int x, int y, int visited[][COLS]) {
    // return 1 if end point is reached
    if (x == maze.end_x && y == maze.end_y) {
        return 1;
    }

    // mark cell as visited
    visited[y][x] = 1;

    // check adjacent cells
    if (x > 0 && maze.grid[y][x - 1] != '#' && !visited[y][x - 1]) {
        if (find_route(maze, x - 1, y, visited)) {
            maze.grid[y][x] = '*';
            return 1;
        }
    }
    if (x < COLS - 1 && maze.grid[y][x + 1] != '#' && !visited[y][x + 1]) {
        if (find_route(maze, x + 1, y, visited)) {
            maze.grid[y][x] = '*';
            return 1;
        }
    }
    if (y > 0 && maze.grid[y - 1][x] != '#' && !visited[y - 1][x]) {
        if (find_route(maze, x, y - 1, visited)) {
            maze.grid[y][x] = '*';
            return 1;
        }
    }
    if (y < ROWS - 1 && maze.grid[y + 1][x] != '#' && !visited[y + 1][x]) {
        if (find_route(maze, x, y + 1, visited)) {
            maze.grid[y][x] = '*';
            return 1;
        }
    }

    // if end point is not reached, unmark cell and return 0
    maze.grid[y][x] = ' ';
    visited[y][x] = 0;
    return 0;
}

int main() {
    Maze maze;
    int visited[ROWS][COLS] = {0};

    read_maze_file("maze.txt", &maze);
    printf("Maze:\n");
    print_maze(maze);

    printf("\nFinding route...\n");
    if (find_route(maze, maze.start_x, maze.start_y, visited)) {
        printf("Route found!\n");
        print_maze(maze);
    } else {
        printf("Route not found!\n");
    }

    return 0;
}