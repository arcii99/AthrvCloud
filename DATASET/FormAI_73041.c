//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int width, height, scale;

    printf("Enter width of the image: ");
    scanf("%d", &width);

    printf("Enter height of the image: ");
    scanf("%d", &height);

    printf("Enter scale: ");
    scanf("%d", &scale);

    srand(time(NULL)); // initialize random seed

    // loop through each pixel
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // generate random color
            int r = rand() % scale; // red
            int g = rand() % scale; // green
            int b = rand() % scale; // blue

            // output pixel
            printf("\x1b[48;2;%d;%d;%dm  \x1b[0m", r, g, b);
        }
        printf("\n"); // new row
    }

    return 0;
}