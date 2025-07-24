//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));  // Seed the random generator with current time

    int width, height, colors;
    printf("Enter the width of the pixel art: ");
    scanf("%d", &width);
    printf("Enter the height of the pixel art: ");
    scanf("%d", &height);
    printf("Enter the number of colors (up to 8): ");
    scanf("%d", &colors);

    if (colors > 8)
    {
        printf("Error: Number of colors cannot exceed 8.\n");
        return 1;
    }

    char color_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '@'};
    // Add more characters to increase the number of available colors

    printf("Your pixel art:\n");

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int color = rand() % colors;
            printf("%c ", color_chars[color]);
        }
        printf("\n");
    }

    return 0;
}