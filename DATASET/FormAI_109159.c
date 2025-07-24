//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: unmistakable
#include <stdio.h>

// Define the width and height of the image
#define WIDTH 10
#define HEIGHT 10

// Define the pixel array
int pixels[HEIGHT][WIDTH];

// Function to print the image to the console
void printImage() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (pixels[i][j] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    
    // Set all pixels to black
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            pixels[i][j] = 0;
        }
    }
    
    // Draw a smiley face
    pixels[2][2] = 1;
    pixels[2][7] = 1;
    pixels[4][2] = 1;
    pixels[4][7] = 1;
    pixels[5][4] = 1;
    pixels[5][5] = 1;
    pixels[6][3] = 1;
    pixels[6][6] = 1;
    
    // Draw a heart
    pixels[2][1] = 1;
    pixels[2][2] = 1;
    pixels[2][6] = 1;
    pixels[2][7] = 1;
    pixels[3][0] = 1;
    pixels[3][3] = 1;
    pixels[3][4] = 1;
    pixels[3][7] = 1;
    pixels[4][0] = 1;
    pixels[4][3] = 1;
    pixels[4][4] = 1;
    pixels[4][7] = 1;
    pixels[5][1] = 1;
    pixels[5][6] = 1;
    pixels[6][2] = 1;
    pixels[6][5] = 1;
    pixels[7][3] = 1;
    pixels[7][4] = 1;
    
    // Print the image
    printImage();
    
    return 0;
}