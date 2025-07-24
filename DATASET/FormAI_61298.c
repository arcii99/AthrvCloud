//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int row;
    int col;
} Coordinate;

int grid[ROWS][COLS];
bool visited[ROWS][COLS];
Coordinate path[ROWS*COLS];
int path_length = 0;

void initialize_grid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2; // Randomly generate obstacles
            visited[i][j] = false;
        }
    }
    grid[0][0] = 0; // Make sure the starting point is accessible
    grid[ROWS-1][COLS-1] = 0; // Make sure the end point is accessible
}

bool isValidCoordinate(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
        return false;
    return true;
}

bool isAccessible(int row, int col) {
    if (grid[row][col] == 0)
        return true;
    return false;
}

bool isVisited(int row, int col) {
    if (visited[row][col])
        return true;
    return false;
}

bool pathfinder(int row, int col) {
    if (!isValidCoordinate(row, col))
        return false;
    if (!isAccessible(row, col))
        return false;
    if (isVisited(row, col))
        return false;
    visited[row][col] = true;
    Coordinate current_coordinate;
    current_coordinate.row = row;
    current_coordinate.col = col;
    path[path_length] = current_coordinate;
    path_length++;
    if (row == ROWS-1 && col == COLS-1)
        return true;
    if (pathfinder(row+1, col))
        return true;
    if (pathfinder(row, col+1))
        return true;
    if (pathfinder(row-1, col))
        return true;
    if (pathfinder(row, col-1))
        return true;
    path_length--;
    visited[row][col] = false;
    return false;
}

void print_path() {
    for (int i = 0; i < path_length; i++) {
        printf("(%d, %d) ", path[i].row, path[i].col);
    }
    printf("\n");
}

int main() {
    initialize_grid();
    printf("Generated grid with random obstacles:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Finding path from (0, 0) to (%d, %d)...\n", ROWS-1, COLS-1);
    if (pathfinder(0, 0)) {
        printf("Path found!\n");
        printf("Path: ");
        print_path();
    } else {
        printf("Path not found!\n");
    }
    return 0;
}