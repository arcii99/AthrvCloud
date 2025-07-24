//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generate_maze(int maze[ROWS][COLS]);
void print_maze(int maze[ROWS][COLS]);

int main() {
    int maze[ROWS][COLS];
    generate_maze(maze);
    print_maze(maze);
    return 0;
}

void generate_maze(int maze[ROWS][COLS]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2;
        }
    }
    // Set entrance and exit points
    maze[0][0] = 0;
    maze[ROWS-1][COLS-1] = 0;
}

void print_maze(int maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}