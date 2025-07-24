//FormAI DATASET v1.0 Category: Fractal Generation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_ITERATIONS 100

void initialize_palette(int palette[][3], int num_colors)
{
    int i, j, step;
    for (i = 0; i < num_colors; i++) {
        step = 256 / (num_colors / 2);
        if (i < num_colors / 2) {
            palette[i][0] = 0;
            palette[i][1] = i * step;
            palette[i][2] = 255 - i * step;
        } else {
            palette[i][0] = (i - num_colors / 2) * step;
            palette[i][1] = 255 - (i - num_colors / 2) * step;
            palette[i][2] = 0;
        }
    }
}

int main(void)
{
    int palette[MAX_ITERATIONS][3];
    initialize_palette(palette, MAX_ITERATIONS);
    srand(time(NULL));
    int x, y, i, j;
    double cx, cy, zx, zy, zx_surround, zy_surround, temp;
    double zx_min = -2.0, zx_max = 2.0, zy_min = -1.5, zy_max = 1.5;
    double zoom = 1.0;
    int zoom_in = 0, zoom_out = 0;
    int num_iterations;
    char filename[25];
    FILE *fp;
    sprintf(filename, "fractal_%dx%d.ppm", WIDTH, HEIGHT);
    
    fp = fopen(filename, "w");
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            cx = (double)x / WIDTH * (zx_max - zx_min) + zx_min;
            cy = (double)y / HEIGHT * (zy_max - zy_min) + zy_min;
            
            zx = cx;
            zy = cy;
            num_iterations = 0;
            
            while (num_iterations < MAX_ITERATIONS && zx * zx + zy * zy < 4.0) {
                zx_surround = zx * zx - zy * zy + cx;
                zy_surround = 2.0 * zx * zy + cy;
                zx = zx_surround;
                zy = zy_surround;
                num_iterations++;
            }
            
            if (num_iterations == MAX_ITERATIONS) {
                fprintf(fp, "0 0 0\n");
            } else {
                fprintf(fp, "%d %d %d\n", palette[num_iterations][0], palette[num_iterations][1], palette[num_iterations][2]);
            }
        }
    }
    
    fclose(fp);
    
    return 0;
}