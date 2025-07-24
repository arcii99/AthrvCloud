//FormAI DATASET v1.0 Category: Fractal Generation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24

void setPixel(char* buffer, int x, int y);
void mandelbrot(char* buffer, double cx, double cy, double zoom);

int main()
{
    char buffer[WIDTH * HEIGHT] = {' '};
    double cx = 0, cy = 0, zoom = 1; // default zoom level

    while (1)
    {
        system("clear");
        mandelbrot(buffer, cx, cy, zoom);

        // print the buffer
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                putchar(buffer[y*WIDTH + x]);
            }
            putchar('\n');
        }

        // read user input
        char ch = getchar();

        switch (ch)
        {
            case 'w':
                cy += 0.1 / zoom;
                break;

            case 'a':
                cx -= 0.1 / zoom;
                break;

            case 's':
                cy -= 0.1 / zoom;
                break;

            case 'd':
                cx += 0.1 / zoom;
                break;

            case 'q':
                zoom *= 2;
                break;

            case 'e':
                zoom /= 2;
                break;

            default:
                break;
        }
    }

    return 0;
}

void setPixel(char* buffer, int x, int y)
{
    buffer[y * WIDTH + x] = '#';
}

void mandelbrot(char* buffer, double cx, double cy, double zoom)
{
    double startX = cx - 2.0 / zoom;
    double startY = cy - 1.0 / zoom;
    double endX = cx + 2.0 / zoom;
    double endY = cy + 1.0 / zoom;

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            double zx = 0, zy = 0;
            double ix = startX + (endX - startX) * x / WIDTH;
            double iy = startY + (endY - startY) * y / HEIGHT;

            int i = 0;
            while (i < 50 && zx*zx + zy*zy < 4.0)
            {
                double tmp = zx*zx - zy*zy + ix;
                zy = 2 * zx*zy + iy;
                zx = tmp;
                i++;
            }

            if (i == 50)
            {
                setPixel(buffer, x, y);
            }
        }
    }
}