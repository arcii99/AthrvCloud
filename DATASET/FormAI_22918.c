//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 25

void clear_screen()
{
    printf("\033[2J\033[H");
}

void initialize_pixels(int pixels[HEIGHT][WIDTH])
{
    for (int i=0; i<HEIGHT; i++)
    {
        for (int j=0; j<WIDTH; j++)
        {
            pixels[i][j] = 0;
        }
    }
}

void draw_pixels(int pixels[HEIGHT][WIDTH])
{
    for (int i=0; i<HEIGHT; i++)
    {
        for (int j=0; j<WIDTH; j++)
        {
            printf("%c", pixels[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
}

void draw_pixel(int pixels[HEIGHT][WIDTH], int x, int y)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        pixels[y][x] = 1;
    }
}

void draw_line(int pixels[HEIGHT][WIDTH], int x1, int y1, int x2, int y2)
{
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx-dy;

    while (1)
    {
        draw_pixel(pixels, x1, y1);

        if (x1 == x2 && y1 == y2)
        {
            break;
        }

        int e2 = 2*err;

        if (e2 > -dy)
        {
            err = err - dy;
            x1 = x1 + sx;
        }

        if (e2 < dx)
        {
            err = err + dx;
            y1 = y1 + sy;
        }
    }
}

void draw_random_lines(int pixels[HEIGHT][WIDTH])
{
    srand(time(NULL));

    for (int i=0; i<10; i++)
    {
        int x1 = rand() % WIDTH;
        int y1 = rand() % HEIGHT;
        int x2 = rand() % WIDTH;
        int y2 = rand() % HEIGHT;
        draw_line(pixels, x1, y1, x2, y2);
    }
}

int main()
{
    int pixels[HEIGHT][WIDTH];

    initialize_pixels(pixels);
    draw_random_lines(pixels);
    draw_pixels(pixels);

    return 0;
}