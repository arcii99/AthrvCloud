//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: complete
/* This is a maze route finder program. The maze is represented as a 2D array of 1s and 0s, where 1 represents a wall and 0 represents a path. The program finds a route through the maze using the depth first search (DFS) algorithm. */

#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

bool visited[ROWS][COLS];

struct Location {
    int row;
    int col;
};

bool isValid(struct Location loc) {
    if (loc.row < 0 || loc.row >= ROWS || loc.col < 0 || loc.col >= COLS) {
        return false;
    }
    if (maze[loc.row][loc.col] == 1 || visited[loc.row][loc.col]) {
        return false;
    }
    return true;
}

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void printVisited() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (visited[i][j]) {
                printf("+");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void findPath(struct Location curr) {
    visited[curr.row][curr.col] = true;

    if (curr.row == ROWS - 1 && curr.col == COLS - 1) {
        printVisited();
        return;
    }

    struct Location left = { curr.row, curr.col - 1 };
    struct Location right = { curr.row, curr.col + 1 };
    struct Location up = { curr.row - 1, curr.col };
    struct Location down = { curr.row + 1, curr.col };

    if (isValid(left)) {
        findPath(left);
        visited[curr.row][curr.col] = false;
    }
    if (isValid(right)) {
        findPath(right);
        visited[curr.row][curr.col] = false;
    }
    if (isValid(up)) {
        findPath(up);
        visited[curr.row][curr.col] = false;
    }
    if (isValid(down)) {
        findPath(down);
        visited[curr.row][curr.col] = false;
    }
}

int main() {
    printMaze();
    struct Location start = { 0, 0 };
    findPath(start);
    return 0;
}