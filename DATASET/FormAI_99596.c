//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 128
#define HEIGHT 64
#define MAX_ITER 5000
#define ESCAPE_RADIUS 4

void render(unsigned char *buffer, float zoom, float offsetX, float offsetY, int mode);
int getIteration(float x, float y);
void setColor(unsigned char *buffer, int x, int y, int iteration, int mode);

int main()
{
    srand(time(NULL));

    unsigned char *buffer = malloc(WIDTH * HEIGHT * 3);
    float zoom = 2;
    float offsetX = -0.7, offsetY = 0;
    int mode = rand() % 4;

    render(buffer, zoom, offsetX, offsetY, mode);
    FILE *fp;
    fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(buffer, 1, WIDTH * HEIGHT * 3, fp);
    fclose(fp);
    free(buffer);

    return 0;
}

void render(unsigned char *buffer, float zoom, float offsetX, float offsetY, int mode)
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            float zx = ((float)x / WIDTH - 0.5) * zoom * 2 + offsetX;
            float zy = ((float)y / HEIGHT - 0.5) * zoom * 2 + offsetY;

            int iteration = getIteration(zx, zy);
            setColor(buffer, x, y, iteration, mode);
        }
    }
}

int getIteration(float x, float y)
{
    float zx = 0, zy = 0;

    for (int i = 0; i < MAX_ITER; i++)
    {
        float nextZX = zx * zx - zy * zy + x;
        float nextZY = 2 * zx * zy + y;
        zx = nextZX;
        zy = nextZY;

        if (zx * zx + zy * zy > ESCAPE_RADIUS * ESCAPE_RADIUS)
        {
            return i;
        }
    }

    return MAX_ITER;
}

void setColor(unsigned char *buffer, int x, int y, int iteration, int mode)
{
    int offset = (y * WIDTH + x) * 3;

    if (iteration == MAX_ITER)
    {
        buffer[offset] = 0;
        buffer[offset + 1] = 0;
        buffer[offset + 2] = 0;
        return;
    }

    float hue = (float)iteration / MAX_ITER;

    switch (mode)
    {
        case 0:
            buffer[offset] = hue * 255;
            buffer[offset + 1] = hue * 255;
            buffer[offset + 2] = hue * 255;
            break;

        case 1:
            buffer[offset] = sinf(hue * 3.141592) * 255;
            buffer[offset + 1] = sinf(hue * 3.141592 + 2.094395) * 255;
            buffer[offset + 2] = sinf(hue * 3.141592 + 4.18879) * 255;
            break;

        case 2:
            buffer[offset] = cosf(hue * 3.141592 + 3.141592) * 255;
            buffer[offset + 1] = cosf(hue * 3.141592) * 255;
            buffer[offset + 2] = cosf(hue * 3.141592 + 1.570796) * 255;
            break;

        case 3:
            buffer[offset] = sinf(hue * 3.141592 + 1.570796) * 255;
            buffer[offset + 1] = sinf(hue * 3.141592) * 255;
            buffer[offset + 2] = sinf(hue * 3.141592 + 3.141592) * 255;
            break;
    }
}