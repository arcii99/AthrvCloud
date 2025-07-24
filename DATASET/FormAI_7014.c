//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
#include <stdio.h>
#include <stdbool.h>

#define ROWS 8
#define COLS 8

char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'S', ' ', ' ', '#', ' ', '#', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', '#'},
    {'#', ' ', '#', '#', ' ', '#', '#', '#'},
    {'#', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', ' ', '#', ' ', 'F', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#'}
};

bool solve_maze(int r, int c) {
    if (maze[r][c] == 'F') {
        return true;
    }
    if (maze[r][c] == '#' || maze[r][c] == 'X') {
        return false;
    }
    maze[r][c] = 'X';
    if (solve_maze(r-1, c) == true) {
        printf("U");
        return true;
    }
    if (solve_maze(r+1, c) == true) {
        printf("D");
        return true;
    }
    if (solve_maze(r, c-1) == true) {
        printf("L");
        return true;
    }
    if (solve_maze(r, c+1) == true) {
        printf("R");
        return true;
    }
    return false;
}

int main() {
    int start_r = 1;
    int start_c = 1;
    
    printf("Starting location: (%d, %d)\n", start_r, start_c);
    printf("Maze:\n");
    
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%c ", maze[r][c]);
        }
        printf("\n");
    }
    
    printf("Route: ");
    bool success = solve_maze(start_r, start_c);
    printf("\n");
    
    if (success) {
        printf("Found path to treasure!\n");
    } else {
        printf("Failed to find treasure.\n");
    }
    
    return 0;
}