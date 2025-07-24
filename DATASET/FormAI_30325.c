//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int row;
    int col;
} Point;

bool isValid(int row, int col) {
    return (row >= 0) && (row < ROWS) &&
           (col >= 0) && (col < COLS);
}

bool isBlocked(int grid[ROWS][COLS], int row, int col) {
    return (grid[row][col] == 1);
}

bool isGoal(Point current, Point goal) {
    return (current.row == goal.row) && (current.col == goal.col);
}

void printGrid(int grid[ROWS][COLS]) {
    printf("-----------------------------\n");
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("| %d ", grid[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------------------\n");
}

void printPath(int path[ROWS][COLS]) {
    printf("-----------------------------\n");
    printf("Found a path!\n");
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (path[i][j] == -1) {
                printf("| %-2c ", 'S');
            } else if (path[i][j] == -2) {
                printf("| %-2c ", 'G');
            } else {
                printf("| %-2d ", path[i][j]);
            }
        }
        printf("|\n");
    }
    printf("-----------------------------\n");
}

void bfs(int grid[ROWS][COLS], Point start, Point goal) {
    int path[ROWS][COLS];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            path[i][j] = -1;
        }
    }

    int row[] = {-1, 0, 0, 1};
    int col[] = {0, -1, 1, 0};

    bool visited[ROWS][COLS];
    memset(visited, false, sizeof(visited));

    visited[start.row][start.col] = true;

    path[start.row][start.col] = 0;

    bool found = false;

    Point queue[ROWS * COLS];
    int front = 0, rear = 0;
    queue[rear] = start;
    rear++;

    while (front != rear) {
        Point current = queue[front];
        front++;

        if (isGoal(current, goal)) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int newRow = current.row + row[i];
            int newCol = current.col + col[i];

            if (isValid(newRow, newCol) && !isBlocked(grid, newRow, newCol) && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                path[newRow][newCol] = path[current.row][current.col] + 1;

                Point next = {newRow, newCol};
                queue[rear] = next;
                rear++;
            }
        }
    }

    if (!found) {
        printf("Could not find a path.\n");
    }
    else {
        printPath(path);
    }
}

int main() {
    int grid[ROWS][COLS] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
                            {0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
                            {0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
                            {0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
                            {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                            {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    Point start = {3, 8};
    Point goal = {8, 9};

    printf("Starting grid:\n");
    printGrid(grid);

    bfs(grid, start, goal);

    return 0;
}