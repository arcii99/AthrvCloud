//FormAI DATASET v1.0 Category: Data structures visualization ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 30
#define MAX_STACK_SIZE 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point points[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack* stack, Point point) {
    stack->points[++stack->top] = point;
}

Point pop(Stack* stack) {
    return stack->points[stack->top--];
}

Point get_random_point() {
    Point point;
    point.x = rand() % WIDTH;
    point.y = rand() % HEIGHT;
    return point;
}

void draw_point(Point point) {
    printf("\033[%d;%dH.", point.y, point.x);
}

void draw_line(Point a, Point b, int color) {
    int x1 = a.x;
    int y1 = a.y;
    int x2 = b.x;
    int y2 = b.y;
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        printf("\033[%d;%dH", y1, x1);
        printf("\033[38;5;%dm.", color);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

void draw_spiral() {
    Stack stack;
    stack.top = -1;

    Point center;
    center.x = WIDTH / 2;
    center.y = HEIGHT / 2;

    int color_step = 256 / MAX_STACK_SIZE;

    push(&stack, center);

    Point point = get_random_point();
    draw_line(center, point, color_step * stack.top);

    while (stack.top != -1) {
        Point current = pop(&stack);
        if (current.x < 0 || current.x >= WIDTH ||
            current.y < 0 || current.y >= HEIGHT) continue;
        draw_point(current);
        draw_line(current, point, color_step * stack.top);
        point = current;

        int direction = rand() % 4;
        if (direction == 0) { // up
            Point next = { current.x, current.y - 1 };
            push(&stack, next);
        } else if (direction == 1) { // down
            Point next = { current.x, current.y + 1 };
            push(&stack, next);
        } else if (direction == 2) { // left
            Point next = { current.x - 1, current.y };
            push(&stack, next);
        } else { // right
            Point next = { current.x + 1, current.y };
            push(&stack, next);
        }
    }
}

int main() {
    srand(time(NULL));
    printf("\033[2J");
    draw_spiral();
    return 0;
}