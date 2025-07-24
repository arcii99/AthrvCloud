//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: romantic
#include <stdio.h>

int main() {
    // Define the ASCII characters to represent the different shades of gray
    char grayscale[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

    // Load the input image file
    FILE* input_file = fopen("image.pgm", "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    // Read the image header and extract the width and height
    char header[128];
    fgets(header, sizeof(header), input_file);
    fgets(header, sizeof(header), input_file);
    int width, height;
    sscanf(header, "%d %d", &width, &height);
    fgets(header, sizeof(header), input_file);

    // Create the output file and write the ASCII art to it
    FILE* output_file = fopen("ascii.txt", "w");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Read the pixel value from the input file
            unsigned char pixel;
            fread(&pixel, sizeof(pixel), 1, input_file);

            // Convert the pixel value to grayscale and write the corresponding ASCII character to the output file
            int index = pixel / 25;
            fputc(grayscale[index], output_file);
        }
        fprintf(output_file, "\n");
    }

    // Close the files and exit
    fclose(input_file);
    fclose(output_file);
    return 0;
}