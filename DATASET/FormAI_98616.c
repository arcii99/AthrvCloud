//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ASCII_DIMENSION 255 // Maximum ASCII value
#define MAX_IMAGE_SIZE 100000 // Maximum image size

// Define the ASCII characters to use for the conversion
char ascii_characters[] = "@#MJHGXKHdmhx-/+_:. ";

// Function for scaling the image down to the desired size
int scale_down(int value, int old_max, int new_max)
{
    return ((value * new_max) / old_max);
}

int main(int argc, char* argv[])
{
    // Make sure the user provides the input path and output path
    if (argc != 3)
    {
        printf("Please provide the input image path and output ASCII art path.\n");
        exit(1);
    }

    // Open the input file
    FILE* image_file = fopen(argv[1], "rb");

    // Make sure the input file exists and can be opened
    if (!image_file)
    {
        printf("Input file cannot be opened.\n");
        exit(1);
    }

    // Get the size of the input file
    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    rewind(image_file);

    // If the file size is too large, exit the program
    if (image_size > MAX_IMAGE_SIZE)
    {
        printf("Input file size is too large.\n");
        exit(1);
    }

    // Read the contents of the image file into memory
    unsigned char* image_data = (unsigned char*) malloc(image_size);
    fread(image_data, 1, image_size, image_file);

    // Close the input file
    fclose(image_file);

    // Get the dimensions of the image (width, height, and number of channels)
    int width, height, channels;
    sscanf(argv[2], "%d %d %d", &width, &height, &channels);

    // Create a buffer to store the ASCII art
    char* ascii_art = (char*) malloc((width * height) + height);

    // Convert the image to grayscale and generate the ASCII art
    int ascii_char_count = sizeof(ascii_characters) - 1;
    int pixel_value, index;
    int ascii_index = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get the pixel value
            index = (i * width * channels) + (j * channels);
            pixel_value = (int) image_data[index];

            if (channels == 3)
            {
                // For colored images, calculate the average of the RGB values
                pixel_value = (int) ((image_data[index] + image_data[index+1] + image_data[index+2]) / 3);
            }

            // Scale down the pixel value to fit within the ASCII range
            pixel_value = scale_down(pixel_value, ASCII_DIMENSION, ascii_char_count);

            // Store the corresponding ASCII character in the buffer
            ascii_index += sprintf(&ascii_art[ascii_index], "%c", ascii_characters[pixel_value]);
        }

        // Add a newline character at the end of each row
        ascii_art[ascii_index++] = '\n';
    }

    // Open the output file
    FILE* ascii_file = fopen(argv[3], "wb");

    // Make sure the output file can be opened
    if (!ascii_file)
    {
        printf("Output file cannot be opened.\n");
        exit(1);
    }

    // Write the ASCII art to the output file
    fwrite(ascii_art, 1, strlen(ascii_art), ascii_file);

    // Close the output file
    fclose(ascii_file);

    // Free memory used by the image data and ASCII art buffer
    free(image_data);
    free(ascii_art);

    return 0;
}