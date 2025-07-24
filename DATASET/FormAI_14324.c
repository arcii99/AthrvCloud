//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80 // Width of the ASCII art image
#define HEIGHT 80 // Height of the ASCII art image
#define MAX_PIXEL_VALUE 255 // Maximum pixel value in the input image

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        exit(1);
    }

    // Allocate memory for the pixel values
    int **pixels = (int **) malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        pixels[i] = (int *) malloc(WIDTH * sizeof(int));
    }

    // Read the pixel values from the input file
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int pixel_value;
            fscanf(input_file, "%d", &pixel_value);
            pixels[i][j] = pixel_value;
        }
    }

    // Close the input file
    fclose(input_file);

    // Compute the ASCII art
    char ascii_art[HEIGHT][WIDTH + 1];
    memset(ascii_art, ' ', sizeof(ascii_art));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int pixel_value = pixels[i][j];
            int ascii_value = ((MAX_PIXEL_VALUE - pixel_value) * 95) / MAX_PIXEL_VALUE; // Scale to the ASCII range
            char ascii_char = (char) (32 + ascii_value); // Convert the ASCII value to a character
            ascii_art[i][j] = ascii_char;
        }
        ascii_art[i][WIDTH] = '\0'; // Terminate the string with a null character
    }

    // Print the ASCII art to the console
    for (int i = 0; i < HEIGHT; i++) {
        printf("%s\n", ascii_art[i]);
    }

    // Free the memory allocated for the pixel values
    for (int i = 0; i < HEIGHT; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}