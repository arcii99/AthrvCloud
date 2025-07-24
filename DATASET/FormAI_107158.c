//FormAI DATASET v1.0 Category: Fractal Generation ; Style: artistic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.1415926535
#define WIDTH 1000
#define HEIGHT 1000

void draw_pixel(int x, int y, int r, int g, int b, int *img)
{
    img[3 * (x + y * WIDTH) + 0] = r;
    img[3 * (x + y * WIDTH) + 1] = g;
    img[3 * (x + y * WIDTH) + 2] = b;
}

void draw_fractal(int x, int y, int size, float angle, int *img)
{
    if (size <= 1)
        return;

    // Draw a line from the starting point to the endpoint
    int x2 = x + size * cos(angle * PI / 180.0);
    int y2 = y - size * sin(angle * PI / 180.0);
    for (int i = 0; i <= size; i++) {
        float t = (float)i / (float)size;
        int r = (int)(255.0 * t);
        int g = (int)(255.0 * (1.0 - t));
        int b = (int)(255.0 * (1.0 - t * t));
        draw_pixel(x + t * (x2 - x), y + t * (y2 - y), r, g, b, img);
    }

    // Draw the next two lines from the endpoint of the current line
    int size2 = rand() % size;
    int angle2 = rand() % 180;
    draw_fractal(x2, y2, size2, angle + angle2, img);
    draw_fractal(x2, y2, size - size2, angle - angle2, img);
}

int main()
{
    // Allocate memory for the image
    int *img = (int*)malloc(WIDTH * HEIGHT * 3 * sizeof(int));
    if (img == NULL) {
        fprintf(stderr, "Failed to allocate memory for the image!\n");
        return 1;
    }

    // Generate the fractal image
    srand(time(NULL));
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            draw_pixel(x, y, 0, 0, 0, img);
        }
    }
    draw_fractal(WIDTH / 2, HEIGHT / 2, 400, 0, img);

    // Write the image to a file
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(img, sizeof(int), WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    // Free the memory
    free(img);

    return 0;
}