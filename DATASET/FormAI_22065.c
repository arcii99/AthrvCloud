//FormAI DATASET v1.0 Category: Fractal Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct {
    double x;
    double y;
} point_t;

double square_size;
int depth;

void draw_square(point_t center) {
    printf("draw_square(%d, %d, %d)\n",
                (int)(center.x - square_size),
                (int)(center.y - square_size),
                (int)(2 * square_size)
              );
}

void generate_fractal(point_t center) {
    if (depth == 0) {
        return;
    }
    depth--;
    square_size /= 2;
    point_t top_left = {center.x - square_size, center.y - square_size};
    point_t top_right = {center.x + square_size, center.y - square_size};
    point_t bot_left = {center.x - square_size, center.y + square_size};
    point_t bot_right = {center.x + square_size, center.y + square_size};
    generate_fractal(top_left);
    generate_fractal(top_right);
    generate_fractal(bot_left);
    generate_fractal(bot_right);
    draw_square(center);
}

int main() {
    srand(time(NULL));
    // randomly choose center point
    point_t center = {rand() % WIDTH, rand() % HEIGHT};
    // set initial size and depth
    square_size = fmin(WIDTH, HEIGHT) / 2.0;
    depth = 5;
    generate_fractal(center);

    return 0;
}