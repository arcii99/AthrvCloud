//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'.', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#'},
    {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

typedef struct Coordinates {
    int x;
    int y;
} Coordinates;

Coordinates start = {1, 1}; // Starting position
Coordinates end = {ROWS - 2, COLS - 2}; // Ending position

int shortest_path[ROWS][COLS] = {0}; // Array to store the shortest path

bool is_valid_move(int x, int y) {
    // Check that coordinates are within the maze bounds and not a wall
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] != '#');
}

bool find_shortest_path(int x, int y, int distance) {
    shortest_path[x][y] = distance; // Mark position as visited

    if (x == end.x && y == end.y) { // Check if position is the end
        return true;
    }

    // Check adjacent positions
    if (is_valid_move(x + 1, y) && shortest_path[x + 1][y] == 0) {
        if (find_shortest_path(x + 1, y, distance + 1)) {
            return true; // Successfully found end
        }
    }

    if (is_valid_move(x, y + 1) && shortest_path[x][y + 1] == 0) {
        if (find_shortest_path(x, y + 1, distance + 1)) {
            return true;
        }
    }

    if (is_valid_move(x - 1, y) && shortest_path[x - 1][y] == 0) {
        if (find_shortest_path(x - 1, y, distance + 1)) {
            return true;
        }
    }

    if (is_valid_move(x, y - 1) && shortest_path[x][y - 1] == 0) {
        if (find_shortest_path(x, y - 1, distance + 1)) {
            return true;
        }
    }

    shortest_path[x][y] = 0; // Mark position as unvisited
    return false; // End not found
}

void display_solution() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == '#') {
                printf("%c ", maze[i][j]); // Wall
            }
            else if (shortest_path[i][j] != 0) {
                printf("* "); // Shortest path
            }
            else {
                printf("  "); // Empty space
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Maze Route Finder program!\n\n");
    printf("The maze:\n");
    display_solution();

    printf("\nFinding the shortest path...\n");
    if (find_shortest_path(start.x, start.y, 1)) {
        printf("Successfully found the end!\n\n");
        printf("The shortest path:\n");
        display_solution();
    }
    else {
        printf("Unable to find the end.\n");
    }

    return 0;
}