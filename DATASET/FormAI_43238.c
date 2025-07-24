//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 6
#define COL 7

typedef struct coordinate {
    int row;
    int col;
} coordinate;

char maze[ROW][COL] = {
    {'#','#','#','#','#','#','#'},
    {'#',' ',' ','#',' ',' ','#'},
    {'#',' ',' ','#',' ','#','#'},
    {'#',' ','#',' ',' ',' ','#'},
    {'#',' ','#','#','#',' ','#'},
    {'#','#','#','#','#','#','#'}
};

coordinate start = {1, 1};
coordinate end = {ROW - 2, COL - 2};

bool visited[ROW][COL];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void printMaze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

bool isWall(int row, int col) {
    if (maze[row][col] == '#') {
        return true;
    }

    return false;
}

bool isTarget(int row, int col) {
    if (row == end.row && col == end.col) {
        return true;
    }

    return false;
}

bool isValid(int row, int col) {
    if (row < 0 || row >= ROW || col < 0 || col >= COL) {
        return false;
    }

    if (isWall(row, col) || visited[row][col]) {
        return false;
    }

    return true;
}

void dfs(coordinate pos) {
    visited[pos.row][pos.col] = true;

    if (isTarget(pos.row, pos.col)) {
        printMaze();
        exit(0);
    }

    for (int i = 0; i < 4; i++) {
        int newrow = pos.row + dr[i];
        int newcol = pos.col + dc[i];

        if (isValid(newrow, newcol)) {
            dfs((coordinate){newrow, newcol});
        }
    }

    visited[pos.row][pos.col] = false;
}

int main() {
    printf("Original Maze:\n");
    printMaze();

    printf("\nSolving the Maze...\n");

    dfs(start);

    printf("No solution found!");

    return 0;
}