//FormAI DATASET v1.0 Category: Fractal Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DEPTH 10
#define WINDOW_SIZE 50

typedef struct {
    int x, y;
} Vector2;

void set_window_size(Vector2* position, int depth) {
    position->x = WINDOW_SIZE / (1 << depth);
    position->y = position->x;
}

void draw_fractal(Vector2* position, int depth) {
    if (depth == MAX_DEPTH) {
        return;
    }

    // Move position to top left
    position->y -= position->x / 2;
    position->x /= 2;

    draw_fractal(position, depth + 1);

    // Move position to top middle
    position->x += position->y;
    position->y += position->x / 2;

    draw_fractal(position, depth + 1);

    // Move position to top right
    position->x -= position->y;
    position->y += position->x / 2;

    draw_fractal(position, depth + 1);

    // Move position to bottom right
    position->y -= position->x / 2;
    position->x /= 2;
    position->x += position->y;

    draw_fractal(position, depth + 1);

    // Move position to bottom left
    position->x -= position->y;
    position->y -= position->x / 2;

    draw_fractal(position, depth + 1);

    // Move position back to current position
    position->y += position->x / 2;
    position->x *= 2;
}

int main() {
    srand(time(NULL));

    int depth = rand() % MAX_DEPTH;
    Vector2 position = {WINDOW_SIZE / 2, WINDOW_SIZE / 2};

    set_window_size(&position, depth);
    draw_fractal(&position, 0);

    return 0;
}