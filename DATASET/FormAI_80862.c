//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 21
#define COLS 37

typedef struct point {
    int x;
    int y;
} Point;

Point stack[ROWS * COLS];
int stack_index = 0;

int maze[ROWS][COLS] = {0}; // 0 for walls, 1 for empty space
int visited[ROWS][COLS] = {0};

void push(Point p) {
    stack[stack_index++] = p;
}

Point pop() {
    return stack[--stack_index];
}

bool is_empty() {
    return stack_index == 0;
}

void generate_maze(int x, int y) {
    visited[x][y] = 1;
    maze[x][y] = 1;
    push((Point){x, y});

    while (!is_empty()) {
        Point current = pop();

        int neighbors[4][2] = {{current.x - 2, current.y},
                               {current.x + 2, current.y},
                               {current.x, current.y - 2},
                               {current.x, current.y + 2}};

        int random_order[4] = {0, 1, 2, 3};

        for (int i = 0; i < 4; i++) {
            int r = rand() % 4;
            int temp = random_order[i];
            random_order[i] = random_order[r];
            random_order[r] = temp;
        }

        for (int i = 0; i < 4; i++) {
            int x = neighbors[random_order[i]][0];
            int y = neighbors[random_order[i]][1];

            if ((x >= 0 && x < ROWS) && (y >= 0 && y < COLS) && !visited[x][y]) {
                visited[x][y] = 1;

                int wall_x = (current.x + x) / 2;
                int wall_y = (current.y + y) / 2;
                maze[wall_x][wall_y] = 1;
                maze[x][y] = 1;

                push((Point){x, y});

                break;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    generate_maze(1, 1);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}