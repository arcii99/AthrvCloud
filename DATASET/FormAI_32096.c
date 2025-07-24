//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: systematic
#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Point points[MAX_ROWS * MAX_COLS];
    int count;
} Route;

int is_valid_move(char maze[MAX_ROWS][MAX_COLS], int row, int col) {
    if (row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS) {
        return 0; // out of bounds
    }
    
    if (maze[row][col] == '#') {
        return 0; // wall
    }
    
    return 1; // valid move
}

void find_exit(char maze[MAX_ROWS][MAX_COLS], Point current, Route *route) {
    if (current.row == 0 || current.row == MAX_ROWS - 1 || current.col == 0 || current.col == MAX_COLS - 1) {
        // reached exit
        route->points[route->count++] = current;
        return;
    }
    
    // mark current position as visited
    maze[current.row][current.col] = 'V';
    
    // try moving up, down, left, and right
    Point next_move;
    next_move.row = current.row - 1;
    next_move.col = current.col;
    if (is_valid_move(maze, next_move.row, next_move.col)) {
        route->points[route->count++] = current;
        find_exit(maze, next_move, route);
    }
    
    next_move.row = current.row + 1;
    next_move.col = current.col;
    if (is_valid_move(maze, next_move.row, next_move.col)) {
        route->points[route->count++] = current;
        find_exit(maze, next_move, route);
    }
    
    next_move.row = current.row;
    next_move.col = current.col - 1;
    if (is_valid_move(maze, next_move.row, next_move.col)) {
        route->points[route->count++] = current;
        find_exit(maze, next_move, route);
    }
    
    next_move.row = current.row;
    next_move.col = current.col + 1;
    if (is_valid_move(maze, next_move.row, next_move.col)) {
        route->points[route->count++] = current;
        find_exit(maze, next_move, route);
    }
}

void print_maze(char maze[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void print_route(Route *route) {
    printf("Route to exit:\n");
    for (int i = route->count - 1; i >= 0; i--) {
        printf("(%d,%d) ", route->points[i].row, route->points[i].col);
    }
    printf("\n");
}

int main() {
    char maze[MAX_ROWS][MAX_COLS] = {
        { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
        { '#', '.', '.', '.', '#', '.', '.', '.', '.', '#' },
        { '#', '.', '#', '.', '#', '.', '#', '#', '.', '#' },
        { '#', '.', '#', '.', '.', '.', '.', '.', '.', '#' },
        { '#', '.', '.', '#', '#', '#', '#', '#', '.', '#' },
        { '#', '#', '.', '.', '.', '.', '.', '.', '.', '#' },
        { '#', '#', '#', '#', '#', '#', '.', '#', '#', '#' },
        { '#', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
        { '#', '.', '#', '#', '#', '.', '#', '#', '.', '#' },
        { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
    };
    
    printf("Maze:\n");
    print_maze(maze);
    
    Point start = { 1, 1 };
    Route route = { 0 };
    find_exit(maze, start, &route);
    
    print_route(&route);
    
    return 0;
}