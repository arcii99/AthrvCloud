//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 100 // Maximum width of input image in pixels
#define MAX_HEIGHT 100 // Maximum height of input image in pixels

char ascii_chars[] = {'.', ',', '-', '~', ':', ';', '=', '*', '#', '%', '@'}; // Array of ASCII characters to represent the image

int main() {
    char image[MAX_HEIGHT][MAX_WIDTH]; // Array to store input image
    int width, height; // Width and height of the input image
    
    // Prompt the user for input
    printf("Enter the width and height of the input image: ");
    scanf("%d %d", &width, &height);
    
    // Read in the input image
    for (int i = 0; i < height; i++) {
        printf("Enter row %d of the input image: ", i+1);
        for (int j = 0; j < width; j++) {
            scanf(" %c", &image[i][j]);
        }
    }
    
    // Convert the input image to ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int brightness = (int)image[i][j] * 10 / 255; // Calculate the brightness of each pixel
            printf("%c", ascii_chars[brightness]); // Print out the corresponding ASCII character for the brightness level
        }
        printf("\n"); // Print a newline character after each row
    }
    
    return 0;
}