//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60
#define GRAYSCALE 255

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    int image[HEIGHT][WIDTH], i, j, k;
    char ascii_art[HEIGHT][WIDTH+1];
    char grayscale_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

    // check if input file is provided as command line argument
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    // open input image file
    input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Error: Unable to open input image file\n");
        exit(1);
    }

    // read image data into array
    for (i=0; i < HEIGHT; i++) {
        for (j=0; j < WIDTH; j++) {
            image[i][j] = fgetc(input_file);
        }
    }

    // close input image file
    fclose(input_file);

    // convert image data to ascii art
    for (i=0; i < HEIGHT; i++) {
        for (j=0; j < WIDTH; j++) {
            // convert pixel value to grayscale value
            int pixel_value = image[i][j];
            int grayscale_value = (pixel_value * GRAYSCALE) / 255;

            // map grayscale value to character
            char ascii_char = grayscale_chars[grayscale_value / 25];

            // assign ascii character to position in ascii art array
            ascii_art[i][j] = ascii_char;
        }
        // add null terminator to end of each row in ascii art array
        ascii_art[i][WIDTH] = '\0';
    }

    // open output file for writing
    output_file = fopen("ascii_art.txt", "w");
    if (!output_file) {
        printf("Error: Unable to open output file for writing\n");
        exit(1);
    }

    // write ascii art to output file
    for (i=0; i < HEIGHT; i++) {
        printf("%s\n", ascii_art[i]);
        fprintf(output_file, "%s\n", ascii_art[i]);
    }

    // close output file
    fclose(output_file);

    return 0;
}