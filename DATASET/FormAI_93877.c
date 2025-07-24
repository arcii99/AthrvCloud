//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int maze[MAX_ROWS][MAX_COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

struct point {
    int x;
    int y;
};

typedef struct point Point;

Point stack[MAX_ROWS * MAX_COLS];
int top = -1;

void push(Point p) {
    stack[++top] = p;
}

Point pop() {
    return stack[top--];
}

int is_empty() {
    return top == -1;
}

int solve_maze(int start_x, int start_y, int end_x, int end_y) {
    Point curr = {start_x, start_y};

    push(curr);

    while(!is_empty()) {
        curr = pop();

        if(curr.x == end_x && curr.y == end_y) {
            return 1;
        }

        if(maze[curr.x][curr.y] == 0) {
            continue;
        }

        maze[curr.x][curr.y] = 0;

        if(curr.x > 0) {
            Point next = {curr.x-1, curr.y};
            push(next);
        }

        if(curr.y > 0) {
            Point next = {curr.x, curr.y-1};
            push(next);
        }

        if(curr.x < MAX_ROWS-1) {
            Point next = {curr.x+1, curr.y};
            push(next);
        }

        if(curr.y < MAX_COLS-1) {
            Point next = {curr.x, curr.y+1};
            push(next);
        }
    }

    return 0;
}

int main() {
    int start_x = 1;
    int start_y = 1;

    int end_x = 8;
    int end_y = 8;

    if(solve_maze(start_x, start_y, end_x, end_y)) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    return 0;
}