//FormAI DATASET v1.0 Category: Fractal Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <time.h>

#define WIDTH 1000
#define HEIGHT 800
#define MAX_ITER 100

void generate_fractal(uint32_t* pixels);

int main()
{
    uint32_t pixels[WIDTH * HEIGHT];
    srand(time(NULL));
    generate_fractal(pixels);

    FILE* fp;
    fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6 %d %d 255\n", WIDTH, HEIGHT);
    fwrite(pixels, sizeof(pixels), 1, fp);
    fclose(fp);

    printf("Fractal generated and saved as fractal.ppm\n");

    return 0;
}

void generate_fractal(uint32_t* pixels)
{
    double x0, y0, x, y, xtemp;
    uint32_t color;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            x0 = (double)i / WIDTH * 3.5 - 2.5;
            y0 = (double)j / HEIGHT * 2.0 - 1.0;

            x = 0;
            y = 0;

            int iter = 0;

            while (x * x + y * y <= 4 && iter < MAX_ITER)
            {
                xtemp = x * x - y * y + x0;
                y = 2 * x * y + y0;
                x = xtemp;
                iter++;
            }
            if (iter == MAX_ITER)
            {
                color = 0;
            }
            else
            {
                color = ((iter + rand() % 99) * 255 / MAX_ITER) << 16 | ((iter + rand() % 99) * 255 / MAX_ITER) << 8 | ((iter + rand() % 99) * 255 / MAX_ITER);
            }

            pixels[j * WIDTH + i] = color;
        }
    }
}