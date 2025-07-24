//FormAI DATASET v1.0 Category: Fractal Generation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 640
#define HEIGHT 480

#define MAX_DEPTH 10

#define COLOR_MIN 0
#define COLOR_MAX 255

typedef struct {
    int r;
    int g;
    int b;
} Color;

int img[WIDTH][HEIGHT];

Color generate_color(int depth)
{
    Color color;
    color.r = COLOR_MIN + (int)((double)(depth)/(double)(MAX_DEPTH) * (double)(COLOR_MAX - COLOR_MIN));
    color.g = COLOR_MAX - (int)((double)(depth)/(double)(MAX_DEPTH) * (double)(COLOR_MAX - COLOR_MIN));
    color.b = COLOR_MAX - (int)((double)(depth)/(double)(MAX_DEPTH) * (double)(COLOR_MAX - COLOR_MIN));
    return color;
}

void set_pixel(int x, int y, Color color)
{
    int r = color.r;
    int g = color.g;
    int b = color.b;

    if(r > COLOR_MAX) r = COLOR_MAX;
    if(g > COLOR_MAX) g = COLOR_MAX;
    if(b > COLOR_MAX) b = COLOR_MAX;

    if(r < COLOR_MIN) r = COLOR_MIN;
    if(g < COLOR_MIN) g = COLOR_MIN;
    if(b < COLOR_MIN) b = COLOR_MIN;

    img[x][y] = (r << 16) | (g << 8) | b;
}

void draw_fractal(int x, int y, int size, int depth)
{
    if (depth == MAX_DEPTH) {
        Color color = generate_color(depth);
        set_pixel(x, y, color);
        return;
    }

    draw_fractal(x, y, size/2, depth+1);
    draw_fractal(x + size/2, y, size/2, depth+1);
    draw_fractal(x, y + size/2, size/2, depth+1);
    draw_fractal(x + size/2, y + size/2, size/2, depth+1);
}

int main()
{
    int x, y;
    int size = HEIGHT;
    srand(time(NULL));

    for(x = 0; x < WIDTH; x++) {
        for(y = 0; y < HEIGHT; y++) {
            img[x][y] = 0;
        }
    }

    draw_fractal(0, 0, size, 0);

    FILE *fp = fopen("fractal.ppm", "wb");

    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", WIDTH, HEIGHT);
    fprintf(fp, "%d\n", COLOR_MAX);

    for(y = HEIGHT-1; y >= 0; y--) {
        for(x = 0; x < WIDTH; x++) {
            fputc((img[x][y] >> 16) & 0xff, fp);
            fputc((img[x][y] >> 8) & 0xff, fp);
            fputc((img[x][y] >> 0) & 0xff, fp);
        }
    }

    fclose(fp);

    return 0;
}