//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time

    int width, height; // Dimensions of the pixel art
    printf("Enter the width of the pixel art: ");
    scanf("%d", &width);
    printf("Enter the height of the pixel art: ");
    scanf("%d", &height);

    char pixels[height][width]; // Array of pixels

    // Generate the pixel art
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int r = rand() % 256; // Red value (0-255)
            int g = rand() % 256; // Green value (0-255)
            int b = rand() % 256; // Blue value (0-255)

            if ((r + g + b) / 3 > 128)
            {
                pixels[y][x] = '#'; // Dark pixel
            }
            else
            {
                pixels[y][x] = '.'; // Light pixel
            }
        }
    }

    // Print the pixel art
    printf("\n");
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            printf("%c ", pixels[y][x]);
        }
        printf("\n");
    }

    return 0;
}