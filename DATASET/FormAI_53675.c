//FormAI DATASET v1.0 Category: Fractal Generation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

void set_pixel(int x, int y, unsigned char* image, int color) {
    int index = 3*(WIDTH*y + x);
    image[index] = color/256/256%256;
    image[index+1] = color/256%256;
    image[index+2] = color%256;
}

void draw_fractal(unsigned char *image, int color, int fractal_depth, int start_x, int start_y, int end_x, int end_y) {
    if (fractal_depth == 0) {
        return;
    }
    int x_diff = end_x-start_x;
    int y_diff = end_y-start_y;

    int dist = sqrt(x_diff*x_diff+y_diff*y_diff);

    if (dist < 30) {
        return;
    }
    int mid_x = start_x + x_diff/2;
    int mid_y = start_y + y_diff/2;

    set_pixel(mid_x, mid_y, image, color);
    draw_fractal(image, color+4000, fractal_depth-1, start_x, start_y, mid_x, mid_y);
    draw_fractal(image, color-1500, fractal_depth-1, mid_x, mid_y, end_x, end_y);
}

int main() {
    unsigned char image[WIDTH*HEIGHT*3];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            set_pixel(x, y, image, 0);
        }
    }

    draw_fractal(image, 256*256*255, 10, 100, 100, 700, 500);

    FILE* fp;
    fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, 1, WIDTH*HEIGHT*3, fp);
    fclose(fp);

    return 0;
}