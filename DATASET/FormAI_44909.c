//FormAI DATASET v1.0 Category: Fractal Generation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_ITERATIONS 500

void generate_fractal(int *map, double x_min, double x_max, double y_min, double y_max)
{
    double dx = (x_max - x_min) / WIDTH;
    double dy = (y_max - y_min) / HEIGHT;
    int iteration_count[MAX_ITERATIONS] = {0};

    for (int py = 0; py < HEIGHT; py++) {
        for (int px = 0; px < WIDTH; px++) {
            double x0 = x_min + px * dx;
            double y0 = y_min + py * dy;
            double x = x0, y = y0;
            int i;
            for (i = 0; i < MAX_ITERATIONS && x*x + y*y <= 4; i++) {
                double x_temp = x*x - y*y + x0;
                y = 2*x*y + y0;
                x = x_temp;
            }
            if (i < MAX_ITERATIONS) {
                iteration_count[i]++;
            }
        }
    }

    int max_iteration_count = 0;
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        if (iteration_count[i] > max_iteration_count) {
            max_iteration_count = iteration_count[i];
        }
    }

    for (int py = 0; py < HEIGHT; py++) {
        for (int px = 0; px < WIDTH; px++) {
            double x0 = x_min + px * dx;
            double y0 = y_min + py * dy;
            double x = x0, y = y0;
            int i;
            for (i = 0; i < MAX_ITERATIONS && x*x + y*y <= 4; i++) {
                double x_temp = x*x - y*y + x0;
                y = 2*x*y + y0;
                x = x_temp;
            }
            int iteration_index = i - 1;
            int iteration_count = max_iteration_count - iteration_index;
            double color = (double) iteration_count / max_iteration_count;
            map[py * WIDTH + px] = (int) (color * 255);
        }
    }
}

int main()
{
    int *map = (int *) malloc(WIDTH * HEIGHT * sizeof(int));
    generate_fractal(map, -2, 2, -2, 2);

    FILE *file = fopen("fractal.ppm", "wb");
    fprintf(file, "P6 %d %d 255\n", WIDTH, HEIGHT);
    for (int py = 0; py < HEIGHT; py++) {
        for (int px = 0; px < WIDTH; px++) {
            fputc(map[py * WIDTH + px], file);
            fputc(map[py * WIDTH + px], file);
            fputc(map[py * WIDTH + px], file);
        }
    }
    fclose(file);

    free(map);
    return 0;
}