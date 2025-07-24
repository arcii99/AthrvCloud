//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int WIDTH = 30;
    const int HEIGHT = 20;

    srand(time(NULL)); // seed the random number generator

    // create an empty canvas
    char canvas[WIDTH][HEIGHT];
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            canvas[x][y] = ' ';
        }
    }

    // draw some random pixels
    for (int i = 0; i < 100; i++)
    {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        canvas[x][y] = '#';
    }

    // print the canvas to the console
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%c ", canvas[x][y]);
        }
        printf("\n");
    }

    return 0;
}