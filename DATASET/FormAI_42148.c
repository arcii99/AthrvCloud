//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Claude Shannon
#include <stdio.h>

#define ROWS 10
#define COLUMNS 14

char maze[ROWS][COLUMNS] = {
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#'},
    {'#','#','#',' ','#','#','#',' ','#','#','#',' ','#','#'},
    {'#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ','#'},
    {'#','#',' ','#','#','#','#','#','#',' ','#','#',' ','#'},
    {'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ','#'},
    {'#','#',' ','#',' ','#','#',' ','#','#','#','#','#','#'},
    {'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#'}   
};

int visited[ROWS][COLUMNS]; 

int start_row = 3;
int start_col = 1;

int end_row = 6;
int end_col = 12;

int dfs(int r, int c) {
    if (r < 0 || r >= ROWS || c < 0 || c >= COLUMNS || maze[r][c] == '#' || visited[r][c] == 1) {
        return 0;
    }

    if (r == end_row && c == end_col) {
        return 1;
    }

    visited[r][c] = 1;

    if (dfs(r+1, c) == 1) {
        printf("(%d, %d)\n", r+1, c);
        return 1;
    }
    if (dfs(r-1, c) == 1) {
        printf("(%d, %d)\n", r-1, c);
        return 1;
    }
    if (dfs(r, c+1) == 1) {
        printf("(%d, %d)\n", r, c+1);
        return 1;
    }
    if (dfs(r, c-1) == 1) {
        printf("(%d, %d)\n", r, c-1);
        return 1;
    }

    return 0;
}

int main() {
    printf("Maze:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    printf("\nStarting position: (%d, %d)\n", start_row, start_col);
    printf("Ending position: (%d, %d)\n", end_row, end_col);

    printf("\nPath:\n");
    dfs(start_row, start_col);

    return 0;
}