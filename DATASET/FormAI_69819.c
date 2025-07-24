//FormAI DATASET v1.0 Category: Image Editor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables for image parameters
    int width, height, max_val;

    // Open input image file
    FILE *input_file = fopen("input.ppm", "rb");

    // Read image header information
    char magic_num[128];
    fscanf(input_file, "%s\n", magic_num);
    fscanf(input_file, "%d %d\n", &width, &height);
    fscanf(input_file, "%d\n", &max_val);

    // Allocate memory for image buffer
    unsigned char *image_data = (unsigned char*) malloc(sizeof(unsigned char) * width * height * 3);

    // Read image pixel data
    fread(image_data, sizeof(unsigned char), width * height * 3, input_file);

    // Close input image file
    fclose(input_file);

    // Perform image processing tasks here

    // Open output image file
    FILE *output_file = fopen("output.ppm", "wb");

    // Write image header information
    fprintf(output_file, "%s\n", magic_num);
    fprintf(output_file, "%d %d\n", width, height);
    fprintf(output_file, "%d\n", max_val);

    // Write image pixel data
    fwrite(image_data, sizeof(unsigned char), width * height * 3, output_file);

    // Close output image file
    fclose(output_file);

    // Free memory allocated for image buffer
    free(image_data);

    return 0;
}