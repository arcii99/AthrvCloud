//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ASCII characters you want to use to create the art
// Tip: Start with simpler characters first, then build up to more complex ones
const char *ascii_chars[] = {
    " ", ".", "-", "~", "*", ":", "=", "+", "O", "o", "0", "X", "#", "%", "@"
};

const int num_chars = sizeof(ascii_chars)/sizeof(char*);

// Define the dimensions of the canvas
const int canvas_width = 80;
const int canvas_height = 30;

// Define a function to convert a grayscale value to an ASCII character
char grayscale_to_ascii(int val) {
    int stepped_val = (num_chars-1) * val / 255;
    return ascii_chars[stepped_val][0];
}

// Define a function to generate ASCII art given a grayscale matrix
char* generate_ascii_art(int *grayscale_matrix, int width, int height) {
    char *ascii_art = malloc(width * height + height + 1); // Allocate memory for the output string with a newline after each row
    memset(ascii_art, 0, width * height + height + 1); // Initialize all memory to 0

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_index = y * width + x;
            char pixel_ascii = grayscale_to_ascii(grayscale_matrix[pixel_index]);
            ascii_art[y*(width+1)+x] = pixel_ascii; // Add pixel to the output string
        }
        ascii_art[(y+1)*(width+1)-1] = '\n'; // Add newline at end of each row
    }

    return ascii_art;
}

int main(void) {
    // Define a grayscale matrix to use for testing
    int grayscale_matrix[canvas_width*canvas_height];
    for (int i = 0; i < canvas_width*canvas_height; i++) {
        grayscale_matrix[i] = rand() % 256;
    }

    char *ascii_art = generate_ascii_art(grayscale_matrix, canvas_width, canvas_height);
    printf("%s", ascii_art);

    free(ascii_art);

    return 0;
}