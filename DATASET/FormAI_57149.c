//FormAI DATASET v1.0 Category: Fractal Generation ; Style: careful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DEPTH  6
#define WIDTH      1000
#define HEIGHT     1000
#define VALUE_MIN -1.0
#define VALUE_MAX  1.0

double value[HEIGHT][WIDTH];

double rand_double(double min, double max) {
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

void diamond_step(int x, int y, int w, int h, int d) {
    if (w < 2 || h < 2) {
        return;
    }

    int half_w = w / 2;
    int half_h = h / 2;

    double tl = value[y][x];
    double tr = value[y][x + w];
    double bl = value[y + h][x];
    double br = value[y + h][x + w];

    double avg = (tl + tr + bl + br) / 4.0;
    double offset = rand_double(-1.0, 1.0) * d;

    value[y + half_h][x + half_w] = avg + offset;

    square_step(x, y, w, h, d / 2);
    square_step(x + half_w, y, w, h, d / 2);
    square_step(x, y + half_h, w, h, d / 2);
    square_step(x + half_w, y + half_h, w, h, d / 2);
}

void square_step(int x, int y, int w, int h, int d) {
    if (w < 2 || h < 2) {
        return;
    }

    int half_w = w / 2;
    int half_h = h / 2;

    double avg;

    if (x == 0 && y == 0) {
        avg = (value[y][x] + value[y][x + w] + value[y + h][x]) / 3.0;
    }
    else if (x + w == WIDTH && y == 0) {
        avg = (value[y][x] + value[y][x + w] + value[y + h][x + w]) / 3.0;
    }
    else if (x == 0 && y + h == HEIGHT) {
        avg = (value[y][x] + value[y + h][x] + value[y + h][x + w]) / 3.0;
    }
    else if (x + w == WIDTH && y + h == HEIGHT) {
        avg = (value[y][x + w] + value[y + h][x] + value[y + h][x + w]) / 3.0;
    }
    else if (x == 0) {
        avg = (value[y][x] + value[y + half_h][x] + value[y + h][x] + value[y + half_h][x + w]) / 4.0;
    }
    else if (x + w == WIDTH) {
        avg = (value[y][x + w] + value[y + half_h][x] + value[y + h][x + w] + value[y + half_h][x + w]) / 4.0;
    }
    else if (y == 0) {
        avg = (value[y][x] + value[y][x + half_w] + value[y][x + w] + value[y + h][x + half_w]) / 4.0;
    }
    else if (y + h == HEIGHT) {
        avg = (value[y][x] + value[y + h][x + half_w] + value[y][x + w] + value[y + h][x + half_w]) / 4.0;
    }
    else {
        avg = (value[y][x] + value[y][x + w] + value[y + h][x] + value[y + h][x + w]) / 4.0;
    }

    double offset = rand_double(-1.0, 1.0) * d;

    value[y + half_h][x + half_w] = avg + offset;

    diamond_step(x, y, w, h, d / 2);
    diamond_step(x + half_w, y, w, h, d / 2);
    diamond_step(x, y + half_h, w, h, d / 2);
    diamond_step(x + half_w, y + half_h, w, h, d / 2);
}

void generate_fractal() {
    srand(time(NULL));

    value[0][0] = rand_double(VALUE_MIN, VALUE_MAX);
    value[0][WIDTH] = rand_double(VALUE_MIN, VALUE_MAX);
    value[HEIGHT][0] = rand_double(VALUE_MIN, VALUE_MAX);
    value[HEIGHT][WIDTH] = rand_double(VALUE_MIN, VALUE_MAX);

    diamond_step(0, 0, WIDTH, HEIGHT, VALUE_MAX / 2);
}

unsigned char rgb(double v) {
    return (unsigned char)((v - VALUE_MIN) / (VALUE_MAX - VALUE_MIN) * 255.0);
}

int main(int argc, char **argv) {
    generate_fractal();

    FILE *fp = fopen("fractal.ppm", "w");
    fprintf(fp, "P6 %d %d %d\n", WIDTH, HEIGHT, 255);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            unsigned char r = rgb(value[y][x]);
            unsigned char g = 0;
            unsigned char b = 0;

            fwrite(&r, 1, 1, fp);
            fwrite(&g, 1, 1, fp);
            fwrite(&b, 1, 1, fp);
        }
    }

    fclose(fp);

    return 0;
}