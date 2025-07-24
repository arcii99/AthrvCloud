//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,1,0,1,0,1},
    {1,0,1,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,1,0,1},
    {1,1,1,1,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

struct Point {
    int x, y, dir;
};

struct Stack {
    struct Point data[100];
    int top;
};

void push(struct Stack *s, struct Point val) {
    s->top++;
    s->data[s->top] = val;
}

struct Point pop(struct Stack *s) {
    struct Point val = s->data[s->top];
    s->top--;

    return val;
}

void printPath(struct Stack *s) {
    int i = 0;

    while (i <= s->top) {
        printf("(%d, %d) ", s->data[i].x, s->data[i].y);

        i++;
    }

    printf("\n");
}

int isValid(struct Point p) {
    if ((p.x >= 0 && p.x < ROWS) && (p.y >= 0 && p.y < COLS)) {
        if (maze[p.x][p.y] == 0) {
            return 1;
        }
    }

    return 0;
}

void solveMaze(struct Point start, struct Point end) {
    struct Stack s;
    s.top = -1;

    push(&s, start);

    while (s.top != -1) {
        struct Point current = pop(&s);

        if (current.x == end.x && current.y == end.y) {
            printPath(&s);
            return;
        }
        else {
            struct Point next;

            // north
            next = current;
            next.x--;

            if (isValid(next)) {
                next.dir = 0;
                push(&s, next);
            }

            // east
            next = current;
            next.y++;

            if (isValid(next)) {
                next.dir = 1;
                push(&s, next);
            }

            // south
            next = current;
            next.x++;

            if (isValid(next)) {
                next.dir = 2;
                push(&s, next);
            }

            // west
            next = current;
            next.y--;

            if (isValid(next)) {
                next.dir = 3;
                push(&s, next);
            }
        }
    }

    printf("Path not found!\n");
}

int main() {
    struct Point start = {1, 1};
    struct Point end = {8, 8};

    solveMaze(start, end);

    return 0;
}