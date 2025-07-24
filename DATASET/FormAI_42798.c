//FormAI DATASET v1.0 Category: Fractal Generation ; Style: brave
#include <stdio.h>

#define WIDTH    80
#define HEIGHT   30

int mandelbrot( double x, double y )
{
    double cx = x;
    double cy = y;
    double newx, newy;
    int i;

    for ( i = 0; i < 1000; i++ )
    {
        if ( x*x + y*y >= 4.0 )
        {
            return 0;
        }

        newx = x*x - y*y + cx;
        newy = 2*x*y + cy;

        x = newx;
        y = newy;
    }

    return 1;
}

int main()
{
    int x, y;
    char image[HEIGHT][WIDTH];

    for ( y = 0; y < HEIGHT; y++ )
    {
        for ( x = 0; x < WIDTH; x++ )
        {
            if ( mandelbrot( (double) x / WIDTH * 4 - 2, (double) y / HEIGHT * 4 - 2 ) )
            {
                image[y][x] = '*';
            }
            else
            {
                image[y][x] = ' ';
            }
        }
    }

    for ( y = 0; y < HEIGHT; y++ )
    {
        for ( x = 0; x < WIDTH; x++ )
        {
            printf( "%c", image[y][x] );
        }
        printf( "\n" );
    }

    return 0;
}