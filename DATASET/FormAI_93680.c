//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASPECT_RATIO 0.5 // Width/Height Aspect ratio of characters used in ASCII art.
#define MAX_WIDTH 256 // Maximum number of pixels in image width.
#define MAX_HEIGHT 192 // Maximum number of pixels in image height.
#define MAX_CHARS 70 // Maximum number of characters in ASCII set.

// ASCII characters to use for conversion. Ordered by increasing brightness.
const char ASCII_CHARS[MAX_CHARS + 1] = " .,:;i1tfLCG08@";
const int CHAR_COUNT = strlen(ASCII_CHARS);

// Convert RGB color to grayscale intensity.
int rgb_to_gray(int r, int g, int b)
{
    return (r * 0.2126 + g * 0.7152 + b * 0.0722);
}

// Scale image to specified width and height while preserving aspect ratio.
void scale_image(int *image, int width, int height, int new_width, int new_height)
{
    float src_aspect = (float)width / height;
    float dst_aspect = (float)new_width / new_height;

    if (src_aspect > dst_aspect)
    {
        // Scale width to new_width, then calculate new height maintaining aspect ratio.
        int scaled_width = new_width;
        int scaled_height = (int)(new_width / src_aspect);

        // Create a new array to store the scaled image.
        int *scaled_image = malloc(scaled_width * scaled_height * sizeof(int));

        // Scale image using a simple nearest neighbor algorithm.
        for (int y = 0; y < scaled_height; y++)
        {
            for (int x = 0; x < scaled_width; x++)
            {
                int src_x = (int)(x * width / (float)scaled_width);
                int src_y = (int)(y * height / (float)scaled_height);
                scaled_image[y * scaled_width + x] = image[src_y * width + src_x];
            }
        }

        // Replace original image with scaled image.
        free(image);
        image = scaled_image;
        width = scaled_width;
        height = scaled_height;
    }
    else
    {
        // Scale height to new_height, then calculate new width maintaining aspect ratio.
        int scaled_width = (int)(new_height * src_aspect);
        int scaled_height = new_height;

        // Create a new array to store the scaled image.
        int *scaled_image = malloc(scaled_width * scaled_height * sizeof(int));

        // Scale image using a simple nearest neighbor algorithm.
        for (int y = 0; y < scaled_height; y++)
        {
            for (int x = 0; x < scaled_width; x++)
            {
                int src_x = (int)(x * width / (float)scaled_width);
                int src_y = (int)(y * height / (float)scaled_height);
                scaled_image[y * scaled_width + x] = image[src_y * width + src_x];
            }
        }

        // Replace original image with scaled image.
        free(image);
        image = scaled_image;
        width = scaled_width;
        height = scaled_height;
    }
}

// Convert image to ASCII art.
void convert_to_ascii(int *image, int width, int height, char *ascii_chars, int char_count)
{
    // Determine the width and height of each character in the ASCII set.
    int char_width = (int)(ASPECT_RATIO * height);
    int char_height = height;

    // Determine the number of characters in the x and y dimensions of the ASCII art.
    int ascii_width = (int)(width / char_width);
    int ascii_height = (int)(height / char_height);

    // Allocate memory for the ASCII art.
    char *ascii_art = malloc((ascii_width * ascii_height + 1) * sizeof(char));

    // Convert each character in the ASCII art.
    for (int y = 0; y < ascii_height; y++)
    {
        for (int x = 0; x < ascii_width; x++)
        {
            // Calculate the average intensity of the pixels in the character region.
            int char_x = x * char_width;
            int char_y = y * char_height;
            int intensity_sum = 0;
            int pixel_count = 0;
            for (int j = 0; j < char_height; j++)
            {
                for (int i = 0; i < char_width; i++)
                {
                    int index = (char_y + j) * width + (char_x + i);
                    if (index < width * height)
                    {
                        int intensity = image[index];
                        intensity_sum += intensity;
                        pixel_count++;
                    }
                }
            }
            int intensity = (intensity_sum / pixel_count);

            // Choose the appropriate ASCII character to represent the intensity.
            int char_index = (int)((intensity / 255.0) * (char_count - 1));
            ascii_art[y * ascii_width + x] = ascii_chars[char_index];
        }
    }

    // Print the ASCII art to the console.
    ascii_art[ascii_width * ascii_height] = '\0';
    printf("%s", ascii_art);

    // Deallocate memory.
    free(ascii_art);
}

int main(int argc, char *argv[])
{
    // Load image from file.
    char *filename = argv[1];
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error: could not open file");
        return 0;
    }

    unsigned char header[54];
    if (fread(header, sizeof(unsigned char), 54, file) != 54)
    {
        printf("Error: invalid image file format");
        fclose(file);
        return 0;
    }

    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int bpp = *(int *)&header[28];

    if (bpp != 24)
    {
        printf("Error: unsupported image format");
        fclose(file);
        return 0;
    }

    int padding = (4 - (width * 3) % 4) % 4;

    int *image = malloc(width * height * sizeof(int));
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            unsigned char buf[3];
            fread(buf, sizeof(unsigned char), 3, file);
            int b = buf[0];
            int g = buf[1];
            int r = buf[2];
            int intensity = rgb_to_gray(r, g, b);
            image[(height - y - 1) * width + x] = intensity;
        }
        fseek(file, padding, SEEK_CUR);
    }

    fclose(file);

    // Scale image to appropriate size.
    int new_width = MAX_WIDTH;
    int new_height = (int)(MAX_WIDTH / ASPECT_RATIO);
    if (height > new_height || width > new_width)
    {
        scale_image(image, width, height, new_width, new_height);
        width = new_width;
        height = new_height;
    }

    // Convert image to ASCII art.
    convert_to_ascii(image, width, height, ASCII_CHARS, CHAR_COUNT);

    // Deallocate memory.
    free(image);

    return 0;
}