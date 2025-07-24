//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define ROWS 256
#define COLS 256

// Function to flip the image horizontally
void flipImageHorizontally(unsigned char *image_arr)
{
    int row, col;

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS / 2; col++)
        {
            unsigned char temp = image_arr[row * COLS + col];
            image_arr[row * COLS + col] = image_arr[row * COLS + (COLS - col - 1)];
            image_arr[row * COLS + (COLS - col - 1)] = temp;
        }
    }
}

// Function to change brightness and contrast of the image
void changeBrightnessContrast(unsigned char *image_arr, float alpha, int beta)
{
    int row, col;

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            image_arr[row * COLS + col] = (unsigned char)(alpha * (float)image_arr[row * COLS + col] + beta);
        }
    }
}

int main()
{
    FILE *input_file, *output_file;
    unsigned char image_arr[ROWS][COLS];
    char input_filename[] = "input_image.raw";
    char output_filename[] = "output_image.raw";
    float alpha = 1.5; // brightness factor
    int beta = 50; // contrast factor

    // Read input image
    input_file = fopen(input_filename, "rb");
    if (input_file == NULL)
    {
        printf("Could not open file %s\n", input_filename);
        return 0;
    }
    fread(image_arr, sizeof(unsigned char), ROWS * COLS, input_file);
    fclose(input_file);

    // Flip image horizontally
    flipImageHorizontally((unsigned char *)image_arr);

    // Change brightness and contrast
    changeBrightnessContrast((unsigned char *)image_arr, alpha, beta);

    // Write output image
    output_file = fopen(output_filename, "wb");
    if (output_file == NULL)
    {
        printf("Could not open file %s\n", output_filename);
        return 0;
    }
    fwrite(image_arr, sizeof(unsigned char), ROWS * COLS, output_file);
    fclose(output_file);

    printf("Image processing complete.\n");

    return 0;
}