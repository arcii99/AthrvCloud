//FormAI DATASET v1.0 Category: Fractal Generation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800

int colormap[] = {0xff0055, 0x53dbf5, 0xf2e535, 0xea0037, 0xb2ef61};

int get_color(float mag) {
    int idx = log(mag) / log(2);
    int c1 = colormap[idx % 5];
    int c2 = colormap[(idx + 1) % 5];
    float frac = log(mag) / log(2) - idx;
    int r = ((c1 >> 16) & 0xff) * (1 - frac) + ((c2 >> 16) & 0xff) * frac;
    int g = ((c1 >> 8) & 0xff) * (1 - frac) + ((c2 >> 8) & 0xff) * frac;
    int b = (c1 & 0xff) * (1 - frac) + (c2 & 0xff) * frac;
    return (r << 16) | (g << 8) | b;
}

void mandelbrot(float cx, float cy, float scale, int max_itr) {
    float zx, zy, zx0, zy0, mag, tmp;
    int x, y, itr, color;
    unsigned char img[WIDTH * HEIGHT * 3];
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6 %d %d 255 ", WIDTH, HEIGHT);
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            zx0 = (x - WIDTH / 2.0) * (scale / WIDTH) + cx;
            zy0 = (y - HEIGHT / 2.0) * (scale / WIDTH) + cy;
            zx = zy = mag = 0;
            itr = 0;
            while (mag < 4 && itr < max_itr) {
                tmp = zx * zx - zy * zy + zx0;
                zy = 2 * zx * zy + zy0;
                zx = tmp;
                mag = sqrt(zx * zx + zy * zy);
                itr++;
            }
            color = get_color(mag);
            img[(y * WIDTH + x) * 3] = (color >> 16) & 0xff;
            img[(y * WIDTH + x) * 3 + 1] = (color >> 8) & 0xff;
            img[(y * WIDTH + x) * 3 + 2] = color & 0xff;
        }
    }
    fwrite(img, WIDTH * HEIGHT * 3, 1, fp);
    fclose(fp);
}

int main() {
    mandelbrot(-0.7, 0, 3.0, 1000);
    return 0;
}