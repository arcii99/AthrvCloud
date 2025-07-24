//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 10

void createPixelArt(char pixelArt[HEIGHT][WIDTH])
{
    srand(time(NULL));
    char pixel = ' ';
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            int random = rand() % 4;
            switch(random)
            {
                case 0:
                    pixel = '0';
                    break;
                case 1:
                    pixel = '@';
                    break;
                case 2:
                    pixel = '#';
                    break;
                case 3:
                    pixel = '%';
                    break;
            }
            pixelArt[i][j] = pixel;
        }
    }
}

void displayPixelArt(char pixelArt[HEIGHT][WIDTH])
{
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            printf("%c", pixelArt[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char pixelArt[HEIGHT][WIDTH];
    createPixelArt(pixelArt);
    displayPixelArt(pixelArt);
    return 0;
}