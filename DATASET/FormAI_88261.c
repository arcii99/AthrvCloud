//FormAI DATASET v1.0 Category: Fractal Generation ; Style: enthusiastic
#include <stdio.h>

int main() {
    printf("Welcome to the world of fractals!\n");
    printf("Are you ready to witness the beauty of the Mandelbrot set?\n");
    printf("Buckle up, because this is going to be an adventure!\n");

    int x, y;
    double zx, zy, cX, cY, tmp;

    int max_iterations = 50;
    double zoom = 1.0;
    double moveX = -0.5;
    double moveY = 0.0;

    int width = 80;
    int height = 40;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            zx = zy = 0;
            cX = (x - width / 2.0) / (0.5 * zoom * width) + moveX;
            cY = (y - height / 2.0) / (0.5 * zoom * height) + moveY;
            int i = max_iterations;

            while (zx * zx + zy * zy < 4 && i-- > 0) {
                tmp = zx * zx - zy * zy + cX;
                zy = 2.0 * zx * zy + cY;
                zx = tmp;
            }

            if (i > 0) {
                putchar('#');
            } else {
                putchar('.');
            }
        }
        putchar('\n');
    }

    printf("Wow, wasn't that amazing?\n");
    printf("Fractals are truly a magical thing.\n");
    printf("Now that you've seen the Mandelbrot set, what other fractals would you like to explore?\n");

    return 0;
}