//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int width, height;
    printf("Enter the desired width of the pixel art: ");
    scanf("%d", &width);
    printf("Enter the desired height of the pixel art: ");
    scanf("%d", &height);

    char image[height][width];
    srand(time(0));

    //Generate random pixel art
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            image[i][j] = rand() % 2 == 0 ? '#' : '.';
        }
    }

    //Print out the generated pixel art
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            printf("%c ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}