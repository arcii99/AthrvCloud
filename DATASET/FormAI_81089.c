//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for image dimensions
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// Constants for ASCII art characters
#define CHAR_DENSITY 10
const char chars[11] = "@#S%?*+=-:. ";
const int num_chars = 11;

// Function to convert RGB values to grayscale
int rgb_to_gray(int red, int green, int blue)
{
    return (red + green + blue) / 3;
}

int main(int argc, char *argv[])
{
    // Check if image file is provided as argument
    if (argc < 2)
    {
        printf("Usage: ./ascii_converter [image_file]\n");
        return 1;
    }

    // Open image file and check if it opened successfully
    char *filename = argv[1];
    FILE *img_file = fopen(filename, "r");
    if (!img_file)
    {
        printf("Could not open image file.\n");
        return 1;
    }

    // Initialize 2D array to store image pixel grayscale values
    int pixel_values[MAX_HEIGHT][MAX_WIDTH] = {0};

    // Read image file header
    char format[3];
    int width, height, max_val;
    fscanf(img_file, "%s\n%d %d\n%d\n", format, &width, &height, &max_val);

    // Loop through each pixel in the image and convert RGB to grayscale
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red, green, blue;
            fscanf(img_file, "%d %d %d", &red, &green, &blue);

            // Convert RGB to grayscale
            int gray_val = rgb_to_gray(red, green, blue);

            // Store grayscale value in pixel_values array
            pixel_values[i][j] = gray_val;
        }
    }

    // Close image file
    fclose(img_file);

    // Print ASCII art representation of image
    for (int i = 0; i < height; i += CHAR_DENSITY)
    {
        for (int j = 0; j < width; j += CHAR_DENSITY)
        {
            // Calculate average grayscale value for each CHAR_DENSITY x CHAR_DENSITY block of pixels
            int sum = 0;
            int num_pixels = CHAR_DENSITY * CHAR_DENSITY;
            for (int k = i; k < i + CHAR_DENSITY; k++)
            {
                for (int l = j; l < j + CHAR_DENSITY; l++)
                {
                    sum += pixel_values[k][l];
                }
            }
            int avg_val = sum / num_pixels;

            // Print corresponding ASCII character based on grayscale value
            int char_index = (avg_val * num_chars) / max_val;
            if (char_index >= num_chars)
            {
                char_index = num_chars - 1;
            }
            printf("%c", chars[char_index]);
        }
        printf("\n");
    }

    return 0;
}