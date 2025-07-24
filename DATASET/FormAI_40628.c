//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: innovative
#include <stdio.h>
#define ROW 5
#define COL 5

int arr[ROW][COL] = {{0, 1, 1, 0, 1},
                     {0, 0, 1, 0, 0},
                     {0, 0, 1, 0, 0},
                     {0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0}};

int visited[ROW][COL] = {{0}};

void printPath(int row, int col, char direction) {
    static int startPointRow, startPointCol;
    if (direction == 'S') {
        startPointRow = row;
        startPointCol = col;
        printf("Start location: (%d,%d)\n", startPointRow, startPointCol);
    } else {
        printf("(%d,%d) to ", row, col);
    }
}

int isSafe(int row, int col) {
    return ((row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && arr[row][col] && !visited[row][col]);
}

void findPath(int row, int col, char direction) {
    if ((row == 0) && (col == 4)) {
        printPath(row, col, direction);
        printf("End location: (%d,%d)\n", row, col);
        return;
    }

    visited[row][col] = 1;

    if (isSafe(row + 1, col)) {
        printPath(row, col, direction);
        findPath(row + 1, col, 'D');
    }

    if (isSafe(row, col - 1)) {
        printPath(row, col, direction);
        findPath(row, col - 1, 'L');
    }

    if (isSafe(row, col + 1)) {
        printPath(row, col, direction);
        findPath(row, col + 1, 'R');
    }

    if (isSafe(row - 1, col)) {
        printPath(row, col, direction);
        findPath(row - 1, col, 'U');
    }

    visited[row][col] = 0;
}

int main() {
    printf("Maze: \n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    findPath(4, 0, 'S');
    return 0;
}