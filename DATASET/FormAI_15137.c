//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random numbers
int get_random(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    // setting up the canvas
    int height = 50, width = 50;
    int canvas[height][width];

    // setting up the random seed
    srand(time(0));

    // generating the pixels
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int r = get_random(0, 255);
            int g = get_random(0, 255);
            int b = get_random(0, 255);

            int pixel = (r << 16) + (g << 8) + b;
            canvas[i][j] = pixel;
        }
    }

    // printing the canvas
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int pixel = canvas[i][j];
            printf("\033[38;2;%d;%d;%dm ", (pixel >> 16) & 0xFF, (pixel >> 8) & 0xFF, pixel & 0xFF);
        }
        printf("\n");
    }

    return 0;
}