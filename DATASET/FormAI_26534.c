//FormAI DATASET v1.0 Category: Fractal Generation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define MAX_DEPTH 25

float frand()
{
    return (float)rand() / RAND_MAX;
}

bool check(float x, float y, float z, float w)
{
    float v = pow(x, 4) + pow(y, 4) + pow(z, 4) + pow(w, 4) - 1;
    return v * v * v - pow(x * y * z * w, 2) < 0.1;
}

void plot(float x, float y, char data[SCREEN_HEIGHT][SCREEN_WIDTH])
{
    int ix = (int)((x + 1) * 0.5 * (SCREEN_WIDTH - 1));
    int iy = (int)((y + 1) * 0.5 * (SCREEN_HEIGHT - 1));

    if (ix < 0 || ix >= SCREEN_WIDTH)
        return;
    if (iy < 0 || iy >= SCREEN_HEIGHT)
        return;

    data[iy][ix] = '*';
}

void draw(char data[SCREEN_HEIGHT][SCREEN_WIDTH])
{
    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            putchar(data[y][x]);
        }
        putchar('\n');
    }
}

void fractal(float x1, float y1, float z1, float w1, float x2, float y2, float z2, float w2, int depth, char data[SCREEN_HEIGHT][SCREEN_WIDTH])
{
    if (depth == 0)
    {
        plot(x1 / w1, y1 / w1, data);
        return;
    }

    if (check(x1, y1, z1, w1) && check(x2, y2, z2, w2))
    {
        return;
    }

    float xm = (x1 + x2) / 2;
    float ym = (y1 + y2) / 2;
    float zm = (z1 + z2) / 2;
    float wm = (w1 + w2) / 2;

    fractal(x1, y1, z1, w1, xm, ym, zm, wm, depth - 1, data);
    fractal(xm, y1, z1, wm, x2, ym, zm, w2, depth - 1, data);
    fractal(x1, y1, zm, wm, xm, ym, z2, w2, depth - 1, data);
    fractal(xm, y1, zm, w1, x2, ym, z2, wm, depth - 1, data);
    fractal(x1, ym, z1, wm, xm, y2, zm, w2, depth - 1, data);
    fractal(xm, ym, z1, w1, x2, y2, zm, wm, depth - 1, data);
    fractal(x1, ym, zm, wm, xm, y2, z2, w2, depth - 1, data);
    fractal(xm, ym, zm, w1, x2, y2, z2, wm, depth - 1, data);
}

int main()
{
    srand((unsigned)time(NULL));

    char data[SCREEN_HEIGHT][SCREEN_WIDTH];

    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            data[y][x] = ' ';
        }
    }

    fractal(-1, -1, -1, -1, 1, 1, 1, 1, MAX_DEPTH, data);

    draw(data);
}