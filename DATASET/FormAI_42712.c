//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10  // Define number of rows in the maze
#define COL 10  // Define number of columns in the maze

bool isValidCoordinates(int x, int y);
bool isRouteEmpty(char maze[][COL], int x, int y);
void printPath(int path[][COL], int end_x, int end_y);
bool findRoute(char maze[][COL], int x, int y, int end_x, int end_y, int path[][COL]);
void printMaze(char maze[][COL]);
void paranoid(char maze[][COL], int start_x, int start_y, int end_x, int end_y);

void paranoid(char maze[][COL], int start_x, int start_y, int end_x, int end_y) {

    int path[ROW][COL];  // Matrix to store the path taken in the maze
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            path[i][j] = 0;
        }
    }

    // Check if starting coordinates are valid and not blocked
    if (!isValidCoordinates(start_x, start_y) || maze[start_x][start_y] == '#') {
        printf("Invalid starting position or blocked route!\n");
        return;
    }

    // Check if ending coordinates are valid and not blocked
    if (!isValidCoordinates(end_x, end_y) || maze[end_x][end_y] == '#') {
        printf("Invalid ending position or blocked route!\n");
        return;
    }

    // Find the route through the maze if any
    bool routeFound = findRoute(maze, start_x, start_y, end_x, end_y, path);

    if (routeFound) {
        printf("Solution found!\n");
        printf("The path taken in the maze is: \n");
        printPath(path, end_x, end_y);
    }
    else {
        printf("No solution found!\n");
    }
}

bool isValidCoordinates(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

bool isRouteEmpty(char maze[][COL], int x, int y) {
    return (maze[x][y] == ' ' || maze[x][y] == 'E');
}

void printPath(int path[][COL], int end_x, int end_y) {
    int x = end_x;
    int y = end_y;
    printf("(%d,%d) ", end_x, end_y);

    while (path[x][y] != 0) {
        int temp_x = x;
        x = path[x][y] / 10;
        y = path[temp_x][y] % 10;
        printf("(%d,%d) ", x, y);
    }
    printf("\n");
}

bool findRoute(char maze[][COL], int x, int y, int end_x, int end_y, int path[][COL]) {

    if (!isValidCoordinates(x, y) || !isRouteEmpty(maze, x, y)) {
        return false; // The current position is invalid!
    }

    if (x == end_x && y == end_y) {
        return true;  // The end position has been reached!
    }

    maze[x][y] = '*'; // Mark the current position as visited in the maze
    int i, j;

    // Check all four directions and recursively call the findRoute function
    if (findRoute(maze, x-1, y, end_x, end_y, path)) {
        path[x][y] = (x-1)*10 + y;
        maze[x][y] = '.'; // Mark the current position as part of the path in the maze
        return true;
    }

    if (findRoute(maze, x+1, y, end_x, end_y, path)) {
        path[x][y] = (x+1)*10 + y;
        maze[x][y] = '.';
        return true;
    }

    if (findRoute(maze, x, y-1, end_x, end_y, path)) {
        path[x][y] = x*10 + (y-1);
        maze[x][y] = '.';
        return true;
    }

    if (findRoute(maze, x, y+1, end_x, end_y, path)) {
        path[x][y] = x*10 + (y+1);
        maze[x][y] = '.';
        return true;
    }

    maze[x][y] = ' '; // Unmark the current position as visited in the maze
    return false;
}

void printMaze(char maze[][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main() {
    char maze[ROW][COL] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', 'E', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    printf("The maze is: \n");
    printMaze(maze);

    printf("Finding a path through the maze...\n");

    paranoid(maze, 1, 1, 3, 3);

    return 0;
}