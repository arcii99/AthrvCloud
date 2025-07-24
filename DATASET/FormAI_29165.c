//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

void convertToAscii(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    char ascii_chars[11] = {'@', '#', '.', ':', ';', '+', '*', '?', '%', 'S', ' '};
    // Array of ASCII characters to be used in the conversion
    int asciified[MAX_HEIGHT][MAX_WIDTH]; // Matrix to store the ASCII representation of the image
    
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int index = image[i][j] / 25; // Convert pixel value into index of ASCII character
            asciified[i][j] = index; // Store the index into the asciified matrix
        }
    }
    
    // Print ASCII representation to console
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("%c", ascii_chars[asciified[i][j]]); // Access ASCII character corresponding to the index and print it
        }
        printf("\n"); // Move to next line after each row
    }
}

int main() {
    // Sample 10x10 image represented as matrix of pixel values ranging from 0 to 255
    int image[MAX_HEIGHT][MAX_WIDTH] = {
        {209, 212, 211, 213, 214, 213, 212, 214, 213, 211},
        {209, 210, 209, 212, 214, 213, 211, 214, 213, 210},
        {209, 208, 210, 212, 215, 214, 213, 213, 212, 211},
        {207, 209, 212, 214, 215, 216, 215, 214, 211, 212},
        {208, 210, 213, 214, 215, 216, 215, 214, 211, 212},
        {209, 211, 214, 215, 215, 216, 214, 213, 212, 212},
        {209, 211, 213, 214, 214, 216, 215, 214, 212, 211},
        {208, 209, 211, 212, 213, 214, 214, 213, 212, 210},
        {207, 208, 210, 211, 214, 215, 214, 213, 211, 209},
        {206, 208, 209, 211, 214, 215, 214, 213, 210, 208}
    };
    
    convertToAscii(image, 10, 10);
    
    return 0;
}