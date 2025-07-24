//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 256
#define HEIGHT 256

/* Function to flip an image horizontally */
void flip_image(unsigned char input_image[][WIDTH], unsigned char output_image[][WIDTH])
{
    int row, col;
    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            output_image[row][col] = input_image[row][WIDTH - col - 1];
        }
    }
}

/* Function to adjust brightness of an image */
void adjust_brightness(unsigned char input_image[][WIDTH], unsigned char output_image[][WIDTH], int brightness)
{
    int row, col;
    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            int pixel_value = input_image[row][col] + brightness;
            if (pixel_value > 255) {
                pixel_value = 255;
            }
            if (pixel_value < 0) {
                pixel_value = 0;
            }
            output_image[row][col] =(unsigned char)pixel_value;
        }
    }
}

/* Function to adjust contrast of an image */
void adjust_contrast(unsigned char input_image[][WIDTH], unsigned char output_image[][WIDTH], double contrast)
{
    int row, col;
    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            int pixel_value = (int)((input_image[row][col] - 127) * contrast + 127);
            if (pixel_value > 255) {
                pixel_value = 255;
            }
            if (pixel_value < 0) {
                pixel_value = 0;
            }
            output_image[row][col] =(unsigned char)pixel_value;
        }
    }
}

int main()
{
    unsigned char input_image[HEIGHT][WIDTH];
    unsigned char output_image[HEIGHT][WIDTH];

    FILE* input_file = fopen("input_image.raw", "rb");
    if (input_file == NULL) {
        printf("Could not open input file\n");
        exit(1);
    }

    fread(input_image, sizeof(unsigned char), WIDTH*HEIGHT, input_file);
    fclose(input_file);

    /* Flip the image horizontally */
    flip_image(input_image, output_image);

    /* Adjust the brightness of the image */
    adjust_brightness(output_image, output_image, 50);

    /* Adjust the contrast of the image */
    adjust_contrast(output_image, output_image, 1.5);

    FILE* output_file = fopen("output_image.raw", "wb");
    if (output_file == NULL) {
        printf("Could not open output file\n");
        exit(1);
    }

    fwrite(output_image, sizeof(unsigned char), WIDTH*HEIGHT, output_file);
    fclose(output_file);

    printf("Image processing completed successfully!\n");

    return 0;
}