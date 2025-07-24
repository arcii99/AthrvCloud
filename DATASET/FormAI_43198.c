//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

void print_maze(char maze[][COLS], int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

bool maze_route_finder(char maze[][COLS], int start_x, int start_y, int end_x, int end_y) {
    if (maze[start_x][start_y] == 'X') { // invalid starting point
        return false;
    }
    if (maze[end_x][end_y] == 'X') { // invalid ending point
        return false;
    }
    if (start_x == end_x && start_y == end_y) { // reached the goal, return true
        return true;
    }
    maze[start_x][start_y] = 'X'; // mark as visited
    if (start_x > 0 && maze_route_finder(maze, start_x - 1, start_y, end_x, end_y)) { // check up
        maze[start_x][start_y] = '0'; // mark as not visited
        return true;
    }
    if (start_x < ROWS - 1 && maze_route_finder(maze, start_x + 1, start_y, end_x, end_y)) { // check down
        maze[start_x][start_y] = '0'; // mark as not visited
        return true;
    }
    if (start_y > 0 && maze_route_finder(maze, start_x, start_y - 1, end_x, end_y)) { // check left
        maze[start_x][start_y] = '0'; // mark as not visited
        return true;
    }
    if (start_y < COLS - 1 && maze_route_finder(maze, start_x, start_y + 1, end_x, end_y)) { // check right
        maze[start_x][start_y] = '0'; // mark as not visited
        return true;
    }
    maze[start_x][start_y] = '0'; // mark as not visited
    return false; // no path found
}

int main() {
    char maze[ROWS][COLS] = {
        {'0', '0', '0', '0', '0', 'X', '0', '0', 'X', '0'},
        {'0', '0', '0', '0', '0', 'X', '0', '0', '0', '0'},
        {'X', 'X', 'X', 'X', '0', 'X', 'X', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', 'X', '0', 'X', '0'},
        {'0', 'X', '0', 'X', '0', '0', '0', '0', 'X', '0'},
        {'0', 'X', '0', 'X', 'X', 'X', 'X', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', 'X', '0'},
        {'0', 'X', 'X', 'X', 'X', 'X', 'X', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', 'X', '0'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '0'}
    };

    printf("Maze:\n");
    print_maze(maze, ROWS, COLS);

    int start_x = 0;
    int start_y = 0;
    int end_x = 9;
    int end_y = 9;

    if (maze_route_finder(maze, start_x, start_y, end_x, end_y)) {
        printf("Path found!\n");
    } else {
        printf("Path not found...\n");
    }

    printf("Maze after path finding:\n");
    print_maze(maze, ROWS, COLS);

    return 0;
}