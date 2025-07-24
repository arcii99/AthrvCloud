//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: enthusiastic
#include <stdio.h>

#define ROW_SIZE 10
#define COLUMN_SIZE 10
#define VISITED 2

int maze[ROW_SIZE][COLUMN_SIZE] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 1, 1, 0, 0, 1, 1, 0},
    {0, 1, 0, 0, 0, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0}
};

int path[ROW_SIZE * COLUMN_SIZE][2];
int path_index = -1;

void printPath() {
    printf("The path is:\n");
    for (int i = 0; i <= path_index; i++) {
        printf("(%d, %d) ", path[i][0], path[i][1]);
    }
    printf("\n");
}

int solve(int row, int column) {
    if (maze[row][column] == 0) return 0;
    if (maze[row][column] == VISITED) return 0;
    if (row == ROW_SIZE - 1 && column == COLUMN_SIZE - 1) {
        path[++path_index][0] = row;
        path[path_index][1] = column;
        return 1;
    }

    maze[row][column] = VISITED;
    if (row < ROW_SIZE - 1 && solve(row + 1, column)) {
        path[++path_index][0] = row;
        path[path_index][1] = column;
        return 1;
    }
    if (row > 0 && solve(row - 1, column)) {
        path[++path_index][0] = row;
        path[path_index][1] = column;
        return 1;
    }
    if (column < COLUMN_SIZE - 1 && solve(row, column + 1)) {
        path[++path_index][0] = row;
        path[path_index][1] = column;
        return 1;
    }
    if (column > 0 && solve(row, column - 1)) {
        path[++path_index][0] = row;
        path[path_index][1] = column;
        return 1;
    }

    return 0;
}

void clearPath() {
    for (int i = 0; i <= path_index; i++) {
        path[i][0] = 0;
        path[i][1] = 0;
    }
    path_index = -1;
}

int main() {
    printf("Welcome to the C Maze Route Finder\n\n");
    printf("Finding a path in this maze:\n\n");

    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {
            if (maze[i][j] == 0) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }

    if (solve(0, 0)) {
        printPath();
    } else {
        printf("No path found\n");
    }

    clearPath();

    printf("\nFinding a path in this maze:\n\n");
    maze[9][0] = 1;
    maze[8][0] = 1;
    maze[7][0] = 1;
    maze[6][0] = 1;

    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {
            if (maze[i][j] == 0) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }

    if (solve(0, 0)) {
        printPath();
    } else {
        printf("No path found\n");
    }
    
    return 0;
}