//FormAI DATASET v1.0 Category: Graph representation ; Style: puzzling
#include <stdio.h>
#define ROWS 7
#define COLS 7

int main() {
    int maze[ROWS][COLS] = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1},
    };
    int i, j;
    printf("\nThe Maze:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("+");
            }
        }
        printf("\n");
    }
    printf("\n\nThe Graph:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf("(%d,%d) -> ", i, j);
                if (i > 0 && maze[i - 1][j] == 0) {
                    printf("(%d,%d) ", i - 1, j);
                }
                if (j < COLS - 1 && maze[i][j + 1] == 0) {
                    printf("(%d,%d) ", i, j + 1);
                }
                if (i < ROWS - 1 && maze[i + 1][j] == 0) {
                    printf("(%d,%d) ", i + 1, j);
                }
                if (j > 0 && maze[i][j - 1] == 0) {
                    printf("(%d,%d) ", i, j - 1);
                }
                printf("\n");
            }
        }
    }
    return 0;
}