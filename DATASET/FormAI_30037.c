//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 25

typedef struct {
    int x, y;
} Point;

int maze[ROWS][COLS];

void print_maze() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j] ? ' ' : '#');
        }
        printf("\n");
    }
}

void init_maze() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            // Set outer walls as "visited"
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = 0;
            }
        }
    }
}

int count_visited_neighbors(int x, int y) {
    int count = 0;

    if (x > 0 && maze[x - 1][y]) count++;
    if (y > 0 && maze[x][y - 1]) count++;
    if (x < ROWS - 1 && maze[x + 1][y]) count++;
    if (y < COLS - 1 && maze[x][y + 1]) count++;

    return count;
}

void dfs(Point *stack, int *stack_size) {
    Point curr, next[4];
    int num_neighbors, i, j;

    while (*stack_size > 0) {
        curr = stack[--(*stack_size)];

        num_neighbors = 0;
        if (curr.x > 1 && !maze[curr.x - 2][curr.y]) {
            next[num_neighbors].x = curr.x - 2;
            next[num_neighbors].y = curr.y;
            num_neighbors++;
        }
        if (curr.y > 1 && !maze[curr.x][curr.y - 2]) {
            next[num_neighbors].x = curr.x;
            next[num_neighbors].y = curr.y - 2;
            num_neighbors++;
        }
        if (curr.x < ROWS - 2 && !maze[curr.x + 2][curr.y]) {
            next[num_neighbors].x = curr.x + 2;
            next[num_neighbors].y = curr.y;
            num_neighbors++;
        }
        if (curr.y < COLS - 2 && !maze[curr.x][curr.y + 2]) {
            next[num_neighbors].x = curr.x;
            next[num_neighbors].y = curr.y + 2;
            num_neighbors++;
        }

        if (num_neighbors > 0) {
            stack[(*stack_size)++] = curr;

            // Randomize order of neighbors
            for (i = 0; i < num_neighbors; i++) {
                j = i + rand() / (RAND_MAX / (num_neighbors - i) + 1);
                Point temp = next[i];
                next[i] = next[j];
                next[j] = temp;
            }

            // Carve path to unvisited neighbor
            for (i = 0; i < num_neighbors; i++) {
                if (!maze[next[i].x][next[i].y]) {
                    maze[(curr.x + next[i].x) / 2][(curr.y + next[i].y) / 2] = 1;
                    maze[next[i].x][next[i].y] = 1;
                    stack[(*stack_size)++] = next[i];
                    break;
                }
            }
        }
    }
}

int main() {
    Point stack[ROWS * COLS / 4];
    int stack_size = 0;

    srand(time(NULL));

    init_maze();

    // Start generating maze at center
    stack[stack_size++] = (Point){ROWS / 2, COLS / 2};
    maze[ROWS / 2][COLS / 2] = 1;

    dfs(stack, &stack_size);

    print_maze();

    return 0;
}