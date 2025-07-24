//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int width, height;
    printf("Enter the width and height of the pixel art: ");
    scanf("%d %d", &width, &height);

    char pixels[height][width];

    srand(time(NULL));

    printf("\nPixel Art:\n");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rand_num = rand() % 10;
            if (rand_num == 0)
                pixels[i][j] = '.';
            else if (rand_num == 1)
                pixels[i][j] = ',';
            else if (rand_num == 2)
                pixels[i][j] = '-';
            else if (rand_num == 3)
                pixels[i][j] = '_';
            else if (rand_num == 4)
                pixels[i][j] = '|';
            else if (rand_num == 5)
                pixels[i][j] = '/';
            else if (rand_num == 6)
                pixels[i][j] = '\\';
            else if (rand_num == 7)
                pixels[i][j] = '^';
            else if (rand_num == 8)
                pixels[i][j] = '*';
            else if (rand_num == 9)
                pixels[i][j] = '+';

            printf("%c ", pixels[i][j]);
        }
        printf("\n");
    }

    return 0;
}