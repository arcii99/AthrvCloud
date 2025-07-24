//FormAI DATASET v1.0 Category: Fractal Generation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 40
#define ITERATIONS 100

void render(char buffer[][WIDTH+1])
{
    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            putchar(buffer[y][x]);
        }

        putchar('\n');
    }
}

void generate_fractal(char buffer[][WIDTH+1])
{
    srand(time(NULL));

    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            int value = rand() % 100;

            if (value < 5)
            {
                buffer[y][x] = '#';
            }
            else if (value < 10)
            {
                buffer[y][x] = '|';
            }
            else if (value < 15)
            {
                buffer[y][x] = '=';
            }
            else if (value < 20)
            {
                buffer[y][x] = '+';
            }
            else
            {
                buffer[y][x] = '.';
            }
        }
    }

    for (int i = 0; i < ITERATIONS; ++i)
    {
        for (int y = 2; y < HEIGHT-2; ++y)
        {
            for (int x = 2; x < WIDTH-2; ++x)
            {
                int value = rand() % 100;

                if (buffer[y][x] == '+' && value < 40)
                {
                    buffer[y+1][x] = '+';
                    buffer[y-1][x] = '+';
                    buffer[y][x+1] = '+';
                    buffer[y][x-1] = '+';
                }
            }
        }
    }
}

int main()
{
    char buffer[HEIGHT][WIDTH+1];

    generate_fractal(buffer);
    render(buffer);

    return 0;
}