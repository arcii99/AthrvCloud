//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 51

typedef struct {
    int row;
    int col;
} Point;

int maze[ROWS][COLS];

int main() {
    srand(time(NULL));

    // initialize maze with walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1 || (i % 2 == 0 && j % 2 == 0)) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = 0;
            }
        }
    }

    // randomly generate maze
    Point stack[100];
    int top = 0;
    Point current = {1, 1};
    maze[current.row][current.col] = 2;

    do {
        Point neighbors[4] = {
            {current.row - 2, current.col},
            {current.row, current.col - 2},
            {current.row + 2, current.col},
            {current.row, current.col + 2}
        };
        int unvisited_count = 0;
        for (int i = 0; i < 4; i++) {
            if (maze[neighbors[i].row][neighbors[i].col] == 0) {
                unvisited_count++;
            }
        }
        if (unvisited_count > 0) {
            int r = rand() % unvisited_count;
            int count = 0;
            for (int i = 0; i < 4; i++) {
                if (maze[neighbors[i].row][neighbors[i].col] == 0) {
                    if (count == r) {
                        // remove wall and mark cell as visited
                        if (current.row < neighbors[i].row) {
                            maze[current.row + 1][current.col] = 2;
                        } else if (current.row > neighbors[i].row) {
                            maze[current.row - 1][current.col] = 2;
                        } else if (current.col < neighbors[i].col) {
                            maze[current.row][current.col + 1] = 2;
                        } else {
                            maze[current.row][current.col - 1] = 2;
                        }
                        current = neighbors[i];
                        maze[current.row][current.col] = 2;
                        stack[top++] = current;
                        break;
                    }
                    count++;
                }
            }
        } else {
            // backtrack
            top--;
            if (top < 0) {
                break;
            }
            current = stack[top];
        }
    } while (top > 0);

    // print maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else if (maze[i][j] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}