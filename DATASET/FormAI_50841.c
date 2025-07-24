//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int random_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Function to generate the pixel art
void generate_pixel_art(int width, int height)
{
    char pixel_array[height][width]; // Array to store the pixel art

    // Generate random pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // 50% chance of being black or white
            int pixel_color = random_int(0, 1);

            // Set the pixel color
            if (pixel_color == 0)
            {
                pixel_array[i][j] = '.'; // Black pixel
            }
            else
            {
                pixel_array[i][j] = ' '; // White pixel
            }
        }
    }

    // Print the pixel art
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c", pixel_array[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL)); // Seed the random number generator

    int width = random_int(5, 20); // Width of the pixel art
    int height = random_int(5, 20); // Height of the pixel art

    generate_pixel_art(width, height);

    return 0;
}